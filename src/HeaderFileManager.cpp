#include "HeaderFileManager.h"

HeaderFileManager::HeaderFileManager() {}

std::string HeaderFileManager::processHeaders(std::string &line)
{
    // 处理头文件的逻辑
    std::string result;
    if (isPreprocessor(line, lang)){
        // 记录头文件行
        includedHeaders[lineNumber] = line;
        HeaderFileLines.push_back(lineNumber);  // 记录行号
        result = removeIncludes(line);
        return result;
    }
    
    return line;
}

std::string HeaderFileManager::includeHeader(const std::string& headerFile) {
    // 包含头文件的逻辑
    return "";
}

bool HeaderFileManager::isPreprocessor(const std::string& line, const std::string& lang) {
    auto it = preprocessorRegexMap.find(lang);
    if (it != preprocessorRegexMap.end()) {
        return std::regex_search(line, it->second);
    }
    lineNumber++;
    return false; 
}

std::string HeaderFileManager::removeIncludes(std::string& code) {
    // 正则表达式匹配 #include 语句
    std::regex includeRegex(preprocessorRegexMap[lang]);
    return std::regex_replace(code, includeRegex, ""); // 用空字符串替换
}

std::vector<int> HeaderFileManager::getLineNumbers(){
    return HeaderFileLines;
}

void HeaderFileManager::printIncludedHeaders() const {
    for (const auto& [line, header] : includedHeaders) {
        std::cout << "Line " << line << ": " << header << std::endl;
    }
}