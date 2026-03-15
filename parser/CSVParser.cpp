//  CSVParser.cpp

#include "CSVParser.hpp"
#include "../model/Record.hpp"
#include "../model/Dataset.hpp"

#include <sstream>

namespace CDC
{
    std::vector<std::string> CSVParser::splitLines(const std::string& content) const
    {
        std::vector<std::string> lines;
        std::stringstream ss(content);
        std::string line;

        while (std::getline(ss, line))
        {
            if(!line.empty() && line.back() == '\r') // Handle Windows-style line endings
            {
                line.pop_back();
            }
            if(!line.empty())
            {
                lines.push_back(line);
            }
        }

        return lines; 
    }

    std::vector<std::string> CSVParser::splitRow(const std::string& line) const
    {
        std::vector<std::string> cells;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ','))
        {
            cells.push_back(cell);
        }

        return cells;
    }


    Dataset CSVParser::parse(const std::string& content) const
    {
        Dataset dataset;

        std::vector<std::string> lines = splitLines(content);
        if (lines.empty())
        {
            return dataset; // Return empty dataset if no lines are present
        }

        std::vector<std::string> headers = splitRow(lines[0]);
        dataset.setHeaders(headers);

        for(size_t i = 1; i < lines.size(); ++i)
        {
            std::vector<std::string> values = splitRow(lines[i]);
            Record record;

            for (size_t j = 0; j < headers.size(); j++)
            {
                std::string value = (j < values.size()) ? values[j] : "";
                record.setField(headers[j], value);
            }

            dataset.addRecord(record);
        }

        return dataset;
    }
}

/** NOTES:
 * The CSVParser class implements the parse method to 
 * convert a CSV formatted string into a Dataset object.
 * The splitLines method is used to break the input string
 * into individual lines, while the splitRow method is used
 * to split each line into its constituent cells based on 
 * the comma delimiter.
 * 
 * In parse method:
 * - size_t is a C++ type that represents an unsigned integral type, 
 *   typically used for array indexing and loop counting.
 * - The loop starts from 1 to skip the header line, which is 
 *   processed separately to set the headers of the dataset.
 * - Each subsequent line is processed to create a Record object,
 *   where fields are set based on the headers and corresponding values.
 *   The created Record objects are then added to the Dataset.
 * 
 * - (j < values.size()) ? values[j] : "" is a ternary operator that 
 *   checks if the index j is within the bounds of the values vector.
 * 
 * TODO in the future:
 * - Handle quoted fields that may contain commas.
 * - Handle the empty lines more robustly, especially in cases where 
 *   they may be present in the middle of the CSV content.
 * 
 */