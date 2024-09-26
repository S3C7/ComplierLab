#include "defs.h"

class MacroProcessor {
public:
    MacroProcessor();
    std::string expandMacros(const std::string& content);

private:
    void parseMacros(const std::string& content);
    std::string expand(const std::string& text);

    // 存储宏定义的哈希表
    std::unordered_map<std::string, std::string> macros;
    std::regex macroRegex = std::regex(R"(#define\s+(\w+)\s+(.*))");

};
