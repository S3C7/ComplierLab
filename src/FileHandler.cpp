#include "FileHandler.h"

FileHandler::FileHandler() {}

std::vector<std::string> FileHandler::readFileByLine(const std::string& fileName) {
    // 读取文件的逻辑
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Can not open file : " << fileName << std::endl; 
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.clear();  // 清除 EOF 状态
    file.seekg(0); // 重置文件指针，方便重复读取
    return lines;
}

// 按块读取文件，返回 std::vector<std::string>
std::vector<std::string> FileHandler::readFileByBlocks(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::vector<std::string> blocks;
    std::size_t blockSize = 256;
    char *buffer = new char[blockSize];

    while (file.read(buffer, blockSize))
    {
        blocks.emplace_back(buffer, blockSize); // 将缓冲区内容转换为字符串并添加到向量
    }

    // 处理最后一次读取不足 blockSize 的情况
    if (file.gcount() > 0)
    {
        blocks.emplace_back(buffer, file.gcount());
    }

    delete[] buffer; // 释放缓冲区
    file.clear();    // 清除 EOF 状态
    file.seekg(0);   // 重置文件指针
    return blocks;
}

void FileHandler::writeFile(const std::string& fileName, const std::string& content) {
    // 写入文件的逻辑
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Can not open file : " << fileName << std::endl; 
    }
    file << content;
}

void FileHandler::inputFileClose(std::ifstream file) {
    file.close();
}

void FileHandler::outputFileClose(std::ofstream file) {
    file.close();
}
