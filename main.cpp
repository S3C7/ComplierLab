#include "Preprocessor.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        Preprocessor preprocessor;

        // Get input file name
        std::string inputFile = preprocessor.getInputFileName();

        // Generate output file name
        std::string outputFile = "preprocessed_" + inputFile;

        std::cout << "Input file: " << inputFile << std::endl;
        std::cout << "Output file: " << outputFile << std::endl;

        // Perform preprocessing
        preprocessor.preprocess(inputFile, outputFile);

        std::cout << "Preprocessing completed successfully." << std::endl;
        std::cout << "Output written to: " << outputFile << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}