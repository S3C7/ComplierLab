#include "defs.h"
#include "FileHandler.h"
#include "CommentRemover.h"
#include "HeaderFileManager.h"
#include "MacroProcessor.h"

class Preprocessor {
public:
    Preprocessor();
    void preprocess(const std::string& inputFile, const std::string& outputFile);

    enum class Language {
    C_CPP,
    JAVA,
    PYTHON,
    OTHER,
    EXIT
    };

    Language selectLanguage();

    std::string getInputFileName();
private:
    MacroProcessor macroProcessor;
    HeaderFileManager headerFileManager;
    CommentRemover commentRemover;
    FileHandler fileHandler;


};
