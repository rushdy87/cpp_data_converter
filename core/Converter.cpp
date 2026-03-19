#include "Converter.hpp"
#include "ConverterFactory.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

namespace CDC
{
    void Converter::convert(const std::string& inputPath,
                            const std::string& outputPath,
                            Format inputFormat,
                            Format outputFormat) const
    {
        // 1) Read the input file.
        std::ifstream inputFile(inputPath);

        if (!inputFile.is_open()) {
                throw std::runtime_error("Failed to open input file: " + inputPath);
        }

        // 2) Parse the input data using the appropriate parser.
        std::stringstream buffer;
        buffer << inputFile.rdbuf(); //rdbuf() reads the entire content of the file into the buffer
        std::string content = buffer.str();

        // 3) Create the appropriate parser based on the input format.
        std::unique_ptr<Parser> parser = ConverterFactory::createParser(inputFormat);
        Dataset dataset = parser->parse(content);

        // 4) Create the appropriate writer based on the output format.
        std::unique_ptr<Writer> writer = ConverterFactory::createWriter(outputFormat);
        std::string outputContent = writer->write(dataset);

        // 5) Write the output data to the specified file.
        std::ofstream outputFile(outputPath);
        if (!outputFile.is_open()) {
            throw std::runtime_error("Failed to open output file: " + outputPath);
        }
        outputFile << outputContent;
    }
}