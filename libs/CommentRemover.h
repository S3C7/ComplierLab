#include "defs.h"

class CommentRemover {
public:
    CommentRemover();
    CommentRemover(std::string singleID, std::string startMarker,
            std::string endMarker) : blockCommentStartID(startMarker), 
            blockCommentEndID(endMarker), singleCommentID(singleID), inBlockComment(false){
                blockEndLength = blockCommentEndID.length();
                blockStartLength = blockCommentStartID.length();
            }
    
    std::string removeComments(const std::string& content);

    void setSingleCommentID(std::string singleCommentID);
    std::string getSingleCommentID();

    void setBlockCommentStartID(std::string blockCommentStartID);
    std::string getBlockCommentStartID();
    
    void setBlockCommentEndID(std::string blockCommenteID);
    std::string getBlockCommentEndID();

    std::string checkId(std::string& line);
    
private:
    std::string removeSingleLineComments(std::string line, size_t singleLineComment);
    std::string removeMultiLineComments(std::string line, size_t blockCommentStart, 
                                        size_t blockCommentEnd);

    std::string singleCommentID;    // 单行注释标识符
    std::string blockCommentStartID;    // 块注释起始标识符
    std::string blockCommentEndID;  // 块注释终止标识符

    size_t blockStartLength;    // 起始符注释长度
    size_t blockEndLength;      // 终止符注释长度

    bool inBlockComment;
};
