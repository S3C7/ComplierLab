#include "FileHandler.h"

FileHandler::FileHandler() {}

void FileHandler::inputFileInit(const std::string& inputFileName){
    // 初始化输入流
    this->inputStream = std::ifstream(inputFileName);
    if (!inputStream.is_open())
    {
        std::cerr << "无法打开输入文件。" << std::endl;
    }
    
}

void FileHandler::outputFileInit(const std::string &outputFileName)
{ 
    // 初始化输出流
    this->outputStream = std::ofstream(outputFileName);
    if (!outputStream.is_open())
    {
        std::cerr << "无法打开输入文件。" << std::endl;
    }
}


FileHandler::FileHandler(const std::string& inputFileName, const std::string& outputFileName)
{
    inputFileInit(inputFileName);
    outputFileInit(outputFileName);
}

std::vector<std::string> FileHandler::readFileByLine() {
    // 读取文件的逻辑

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputStream, line)) {
        lines.push_back(line);
    }
    inputStream.clear();  // 清除 EOF 状态
    inputStream.seekg(0); // 重置文件指针，方便重复读取
    return lines;
}

void FileHandler::writeFile(const std::string& content) {
    // 写入文件的逻辑
    outputStream << content << "\n";
}

void FileHandler::inputFileClose() {
    inputStream.close();
}

void FileHandler::outputFileClose() {
    outputStream.close();
}


FileHandler::~FileHandler() {
    inputStream.close();
    outputStream.close();
}