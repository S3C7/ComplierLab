#include "defs.h"

class HeaderFileManager {
public:
    HeaderFileManager();
    HeaderFileManager(std::string lang) :lang(lang), lineNumber(1) {
        preprocessorRegexMap["Java"] = std::regex(R"(^\s*import\s+[\w.]+\s*;)");
        preprocessorRegexMap["Clang"] = std::regex(R"(^\s*#\s*include\s*<.*>)");
        preprocessorRegexMap["Python"] = std::regex(R"(^\s*import\s+[\w.]+)");
    };

    std::string processHeaders(std::string& line);

    std::string removeIncludes(std::string& code);

    bool isPreprocessor(const std::string& line, const std::string& lang);

private:
    std::string includeHeader(const std::string& headerFile);
    // 存储已包含的头文件
    std::unordered_set<std::string> includedHeaders;
    // 存储定义的头文件类型
    std::unordered_map<std::string, std::regex> preprocessorRegexMap;

    std::vector<int> HeaderFileLines;
    int lineNumber;
    std::string lang;

};
