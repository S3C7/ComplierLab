#include "defs.h"

class FileHandler {
public:
    FileHandler();
    std::vector<std::string> readFileByLine(const std::string &fileName);
    std::vector<std::string> readFileByBlocks(const std::string &fileName);
    void writeFile(const std::string& fileName, const std::string& content);
    void inputFileClose(std::ifstream file);
    void outputFileClose(std::ofstream file);
    
};

