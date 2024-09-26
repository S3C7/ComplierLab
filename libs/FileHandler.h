#include "defs.h"

class FileHandler
{
public:
    FileHandler();

    void inputFileInit(const std::string &inputFileName);
    void outputFileInit(const std::string &outputFileName);
    
    FileHandler(const std::string &inputFileName, 
                const std::string &outputFileName);

    std::vector<std::string> readFileByLine();
    
    void writeFile(const std::string &content);
    void inputFileClose();
    void outputFileClose();

    ~FileHandler();
private:
    std::ifstream inputStream;
    std::ofstream outputStream;
};
