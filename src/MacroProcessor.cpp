#include "MacroProcessor.h"

MacroProcessor::MacroProcessor() {}

std::string MacroProcessor::expandMacros(const std::string& content) {
    parseMacros(content); // 解析宏定义
    return expand(content); // 展开宏
}

void MacroProcessor::parseMacros(const std::string& content) {
    // 解析宏定义的逻辑
    std::string line = content;
    // 存储匹配的键值
    std::smatch match;
    if (regex_search(line, match, macroRegex))
    {
        std::string macroName = match[1];
        std::string macroValue = match[2];

        macros[macroName] = macroValue; // 存储到map中
    }
    
}

std::string MacroProcessor::expand(const std::string& text) {
    // 展开宏的逻辑
    std::string expandedLine = text;
    for (const auto& [macroName, macroValue] : macros) {
        // 替换宏
        size_t pos = 0;
        // 找到需要替换的字符下标，通过replace进行替换
        while ((pos = expandedLine.find(macroName, pos)) != std::string::npos) {
            expandedLine.replace(pos, macroName.length(), macroValue);
            pos += macroValue.length();
        }
    }
    return expandedLine;
}
