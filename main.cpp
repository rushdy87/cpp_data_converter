#include <iostream>
#include <fstream>
#include <sstream>

#include "parser/CSVParser.hpp"

int main() {
    // Read CSV file content
    std::ifstream file("data/sample_data.csv");

    // Create a stringstream to hold the file content
    std::stringstream buffer; 
    buffer << file.rdbuf();

    // Get the content as a string
    std::string content = buffer.str();

    std::cout << "CSV Content:\n" << content << "\n\n";

    // Parse the CSV content
    CDC::CSVParser parser;
    CDC::Dataset dataset = parser.parse(content);

    std::cout << "Headers:\n";
    for (const auto& h : dataset.getHeaders()) {
        std::cout << h << " ";
    }

    std::cout << "\n\nRecords:\n";

    for (const auto& record : dataset.getRecords()) {
        for (const auto& field : record.getFields()) {
            std::cout << field.first << ": " << field.second << " ";
        }
        std::cout << "\n";
    }

    return 0;
}