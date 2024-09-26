#include "CommentRemover.h"

CommentRemover::CommentRemover() {
    inBlockComment = false;
}

std::string CommentRemover::removeComments(const std::string& content) {
    return content;
}

void CommentRemover::setSingleCommentID(std::string singleCommentID) {
    this->singleCommentID = singleCommentID;
}
std::string CommentRemover::getSingleCommentID() {
    return singleCommentID;
}

void CommentRemover::setBlockCommentStartID(std::string blockCommentStartID) {
    this->blockCommentStartID = blockCommentStartID;
}
std::string CommentRemover::getBlockCommentStartID() {
    return blockCommentStartID;
}

void CommentRemover::setBlockCommentEndID(std::string blockCommentEndID) {
    this->blockCommentEndID = blockCommentEndID;
}
std::string CommentRemover::getBlockCommentEndID() {
    return blockCommentEndID;
}

std::string CommentRemover::checkId(std::string& line){
    // 用于标识需要删除的注释
    size_t singleLineComment;
    size_t blockCommentStart;
    size_t blockCommentEnd;
    
    if (inBlockComment) {   // 如果说是在块注释里面，只查找尾部标识
        blockCommentEnd = line.find(blockCommentEndID);   // 查找是否有结束标识
        if (blockCommentEnd != std::string::npos) { 
            // 查找到结束标识，返回处理标识
            line = removeMultiLineComments(line, blockCommentStart, blockCommentEnd);
            inBlockComment = false;
        }else {
            // 处理单行注释和块注释
            line.clear();
        }

    } else {
        
        singleLineComment = line.find(singleCommentID);
        blockCommentStart = line.find(blockCommentStartID);
        
        if (singleLineComment != std::string::npos && 
            (blockCommentStart == std::string::npos || singleLineComment < blockCommentStart)) {
            // 单行注释删除
            line = removeSingleLineComments(line, singleLineComment);
        } else if (blockCommentStart != std::string::npos) {
            // 查找到多行注释
            blockCommentEnd = line.find(blockCommentEndID, blockCommentStart + blockEndLength);
            line = removeMultiLineComments(line, blockCommentStart, blockCommentEnd);
        }
    }
    return line;
}



std::string CommentRemover::removeSingleLineComments(std::string line, size_t signleLineComment) {
    // 移除单行注释的逻辑
    return line = line.substr(0, signleLineComment);
}

std::string CommentRemover::removeMultiLineComments(std::string line, size_t blockCommentStart, 
                                                    size_t blockCommentEnd) {
    if (blockCommentEnd != std::string::npos) {
        // 找到结束标识，结束块注释
        line = line.substr(blockCommentEnd + blockEndLength); // 保留结束后的内容
    } else {
        // 块注释未结束，删除从开始到行尾的内容
        line = line.substr(0, blockCommentStart);
        inBlockComment = true; // 设置为在块注释中
    }
    return line; // 返回处理后的行
}
