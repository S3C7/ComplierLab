#include "Preprocessor.h"

Preprocessor::Preprocessor() 
    : macroProcessor(), headerFileManager(), commentRemover(), fileHandler() {}

void Preprocessor::preprocess(const std::string& inputFile, const std::string& outputFile) {
    FileHandler f (inputFile, outputFile);
    std::vector<std::string> lines = f.readFileByLine();

}

Preprocessor::Language Preprocessor::selectLanguage() {
    int choice;
    std::cout << "选择编程语言:\n";
    std::cout << "1. C/C++\n";
    std::cout << "2. Java\n";
    std::cout << "3. Python\n";
    std::cout << "4. 其他\n";
    std::cout << "0. 退出\n";
    std::cout << "请输入你的选择: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return Language::C_CPP;
        case 2: return Language::JAVA;
        case 3: return Language::PYTHON;
        case 4: return Language::OTHER;
        case 0: exit(0);
        default: 
            std::cout << "无效选择，请重试。\n";
            return selectLanguage();
    }
}

std::string Preprocessor::getInputFileName() {
    std::string filename;
    std::cout << "请输入输入文档的名字: ";
    std::cin >> filename;

    // 这里可以添加检查文件是否存在的逻辑
    // 假设这里用简单的检查模拟文件存在性
    if (filename.empty()) {
        std::cout << "文件名不能为空，请重试。\n";
        return getInputFileName();
    }
    
    return filename;
}