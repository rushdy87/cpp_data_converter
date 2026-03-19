#include <iostream>
#include <stdexcept>

#include "core/Converter.hpp"
#include "core/Format.hpp"
#include "core/FormatUtils.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./converter <input_file> <output_file>\n";
        return 1;
    }

    try {
        std::string inputPath = argv[1];
        std::string outputPath = argv[2];

        CDC::Format inputFormat = CDC::FormatUtils::detectFormatFromExtension(inputPath);
        CDC::Format outputFormat = CDC::FormatUtils::detectFormatFromExtension(outputPath);

        CDC::Converter converter;
        converter.convert(inputPath, outputPath, inputFormat, outputFormat);

        std::cout << "Conversion completed successfully.\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}