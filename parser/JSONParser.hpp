// JSONParser.hpp

#pragma once

#include "Parser.hpp"

namespace CDC
{
    class JSONParser : public Parser
    {
        public:
            Dataset parse(const std::string& content) const override;
    };
}

/** NOTES:
 * The JSONParser class is a concrete implementation of the Parser interface, specifically 
 * designed to parse JSON (JavaScript Object Notation) formatted content into a Dataset object.
 * The parse method is overridden to provide the specific logic for parsing JSON data, which 
 * typically involves interpreting the input string as a JSON object or array and extracting
 * the relevant fields and values.
 * The resulting Dataset object will contain headers (if present in the JSON) and records 
 * corresponding to each line of data.
 * 
 * 
 * Why override the parse method?
 * The parse method is overridden in the JSONParser class to provide a specific implementation 
 * for parsing JSON data. This allows the JSONParser to handle the unique structure and formatting
 * of JSON files, while still adhering to the common interface defined by the Parser class.
 * By overriding the parse method, we can ensure that the JSONParser correctly processes the input
 * string according to the rules of JSON formatting, such as handling nested objects, arrays,
 * and different data types.

 */