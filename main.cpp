#include "FileHandler.h"
#include "CommentRemover.h"
#include "HeaderFileManager.h"
#include "MacroProcessor.h"

int main()
{
    FileHandler f;
    std::vector<std::string> lines;

    lines = f.readFileByLine("input.txt");
    // std::cout << lines.size() << std::endl;
    // f.writeFile("output.txt", "1");
    CommentRemover remover("//", "/*", "*/");
    HeaderFileManager HeaderFileManager("Clang");
    MacroProcessor macroProcessor;
    std::vector<std::string> codeLines = {
        "#include <stdio.h>",
        "int main() {",
        "    // This is a single line comment",
        "    int a = 5; /* This is a",
        "    multi-line comment */",
        "    printf(\"Hello, World!\"); // Print message",
        "    /* Block comment",
        "    that does not end",
        "    here */",
        "    /*11111*/",
        "    return 0;",
        "}"
    };

    for (std::string& line : lines) {
        std::string nline = HeaderFileManager.processHeaders(line);
        nline = macroProcessor.expandMacros(nline);
        nline = remover.checkId(nline);
        if (!line.empty()) {
            std::cout << nline << std::endl; // 打印处理后的代码行
        }
    }

    return 0;

}