#include <iostream>
#include <fstream>
#include <sstream>

#include "parser/JSONParser.hpp"
#include "writer/CSVWriter.hpp"

int main() {
    std::ifstream file("data/sample_data.json");

    if (!file.is_open()) {
        std::cerr << "Failed to open file\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string content = buffer.str();

    CDC::JSONParser parser;
    CDC::Dataset dataset = parser.parse(content);

    CDC::CSVWriter writer;
    std::string csv = writer.write(dataset);

    std::cout << "CSV Output:\n";
    std::cout << csv << "\n";

    return 0;
}