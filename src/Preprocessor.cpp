#include "Preprocessor.h"

Preprocessor::Preprocessor() 
    : macroProcessor(), headerFileManager(), commentRemover(), fileHandler() {}

void Preprocessor::preprocess(const std::string& inputFile, const std::string& outputFile) {
    FileHandler f (inputFile, outputFile);
    std::vector<std::string> lines = f.readFileByLine();
    CommentRemover remover("//", "/*", "*/");
    HeaderFileManager headerFileManager("Clang");
    MacroProcessor macroProcessor;

    for (auto& line : lines) {
        std::string processedLine = headerFileManager.processHeaders(line);
        processedLine = macroProcessor.expandMacros(processedLine);
        processedLine = remover.checkId(processedLine);
        if (!processedLine.empty()) {
            std::cout << processedLine << std::endl;  // 打印处理后的行

        }
    }
}

Preprocessor::Language Preprocessor::selectLanguage() {
    int choice;
    std::cout << "1. C/C++\n";
    std::cout << "0. exit\n";
    std::cout << "Select: ";
    std::cin >> choice;

    switch (choice) {
        case 1: return Language::C_CPP;
        case 0: exit(0);
        default: 
            std::cout << "Invalid choice, please try again.\n";
            return selectLanguage();
    }
}

std::string Preprocessor::getInputFileName() {
    std::string filename;
    std::cout << "Please enter the input file name: ";
    std::cin >> filename;

    // 这里可以添加检查文件是否存在的逻辑
    // 假设这里用简单的检查模拟文件存在性
    if (filename.empty()) {
        std::cout << "File name cannot be empty. Please try again.\n";
        return getInputFileName();
    }
    
    return filename;
}