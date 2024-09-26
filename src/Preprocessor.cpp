#include "Preprocessor.h"

Preprocessor::Preprocessor() 
    : macroProcessor(), headerFileManager(), commentRemover(), fileHandler() {}

void Preprocessor::preprocess(const std::string& inputFile, const std::string& outputFile) {
    // std::string< content = fileHandler.readFileByBlocks(inputFile); // 读取文件
    // content = commentRemover.removeComments(content); // 移除注释
    // content = headerFileManager.processHeaders(content); // 处理头文件
    // content = macroProcessor.expandMacros(content); // 展开宏
    // fileHandler.writeFile(outputFile, content); // 写入输出文件
}
