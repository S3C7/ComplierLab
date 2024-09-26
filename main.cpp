#include "Preprocessor.h"

int main()
{
    // 测试用
    std::vector<std::string> lines;
    FileHandler f ("input.txt", "output.txt");

    lines = f.readFileByLine();
    CommentRemover remover("//", "/*", "*/");
    HeaderFileManager HeaderFileManager("Clang");
    MacroProcessor macroProcessor;
    Preprocessor preprocessor;  // 创建 Preprocessor 对象

    // 选择语言
    Preprocessor::Language lang = preprocessor.selectLanguage();
    
    if (lang == Preprocessor::Language::EXIT) {
        std::cout << "退出程序\n";
        return 0;
    }

    // 获取输入文件名
    std::string inputFile = preprocessor.getInputFileName();

    // 假设输出文件可以根据输入文件命名
    std::string outputFile = "output_" + inputFile;

    // 调用 preprocess 函数进行预处理
    preprocessor.preprocess(inputFile, outputFile);

    std::cout << "文件处理成功！\n";

    // // 测试用
    // for (std::string& line : lines) {
    //     std::string nline = HeaderFileManager.processHeaders(line);
    //     nline = macroProcessor.expandMacros(nline);
    //     nline = remover.checkId(nline);
    //     if (!nline.empty()) {
    //         f.writeFile(nline); // 写入文件
    //     }
    // }

    return 0;

}