#include "defs.h"
#include "MacroProcessor.h"
#include "FileHandler.h"
#include "CommentRemover.h"
#include "HeaderFileManager.h"

class Preprocessor {
public:
    Preprocessor();
    void preprocess(const std::string& inputFile, const std::string& outputFile);

private:
    MacroProcessor macroProcessor;
    HeaderFileManager headerFileManager;
    CommentRemover commentRemover;
    FileHandler fileHandler;
};
