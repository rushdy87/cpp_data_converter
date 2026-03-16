#include <iostream>
#include <fstream>
#include <sstream>

#include "parser/JSONParser.hpp"

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

    std::cout << "Headers:\n";
    for (const auto& h : dataset.getHeaders()) {
        std::cout << h << " ";
    }

    std::cout << "\n\nRecords:\n";

    for (const auto& record : dataset.getRecords()) {
        for (const auto& [key, value] : record.getFields()) {
            std::cout << key << ": " << value << " ";
        }
        std::cout << "\n";
    }

    return 0;
}