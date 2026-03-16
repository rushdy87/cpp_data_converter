// JSONParser.hpp

#pragma once

#include "Parser.hpp"

namespace CDC
{
    class JSONParser : public Parser
    {
    private:
        std::string trim(const std::string& str) const;
        std::vector<std::string> extractObjects(const std::string& content) const;
        Record parseObject(const std::string& objectContent) const;
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
 * 
 * trim method:
 *  - The trim method is a utility function that removes leading and trailing whitespace from a string.
 *  - This is important when parsing JSON, as it helps to clean up the input and ensure that the
 *    extracted data is accurate and free from extraneous spaces.
 * 
 * extractObjects method:
 * - The extractObjects method is responsible for identifying and extracting individual JSON objects
 *  from the input string. This is crucial for parsing JSON arrays, where multiple objects may be present.
 * - for example: [{...}, {...}, ...] would be parsed to extract each {...} as a separate JSON object.
 *   like this: [{"name": "Alice", "age": 30}, {"name": "Bob", "age": 25}] would be parsed to extract
 *   two JSON objects: {"name": "Alice", "age": 30} and {"name": "Bob", "age": 25}.
 * 
 * parseObject method:
 * - The parseObject method takes a single JSON object as input and converts it into a Record
 *  object. This involves interpreting the key-value pairs in the JSON object and mapping them to
 * the appropriate fields in the Record structure.
 * - For example, if the JSON object is {"name": "Alice", "age": 30}, the parseObject method would
 *  create a Record with fields "name" and "age", and assign the values "Alice" and 30 respectively.
 * 
 */