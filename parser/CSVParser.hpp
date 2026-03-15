// CSVParser.hpp

#pragma once

#include "Parser.hpp"

namespace CDC
{
    class CSVParser : public Parser
    {
    private:
        std::vector<std::string> splitLines(const std::string& content) const;
        std::vector<std::string> splitRow(const std::string& line) const;
    public:
            Dataset parse(const std::string& content) const override;
    };
}

/** NOTES:
 * The CSVParser class is a concrete implementation of the Parser interface, specifically 
 * designed to parse CSV (Comma-Separated Values) formatted content into a Dataset object.
 * The parse method is overridden to provide the specific logic for parsing CSV data, which 
 * typically involves splitting the input string into lines, then further splitting each 
 * line into fields based on a delimiter (commonly a comma).
 * The resulting Dataset object will contain headers (if present in the CSV) and records 
 * corresponding to each line of data.
 * 
 * 
 * Why override the parse method?
 * The parse method is overridden in the CSVParser class to provide a specific implementation 
 * for parsing CSV data. This allows the CSVParser to handle the unique structure and formatting
 * of CSV files, while still adhering to the common interface defined by the Parser class.
 * By overriding the parse method, we can ensure that the CSVParser correctly processes the input
 * string according to the rules of CSV formatting, such as handling quoted fields, escaping characters,
 * and managing different delimiters if necessary.
 */