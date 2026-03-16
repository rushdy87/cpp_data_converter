// JSONParser.cpp

#include "JSONParser.hpp"
#include "../model/Record.hpp"
#include "../model/Dataset.hpp"

#include <cctype> // for std::isspace
#include <stdexcept> // for std::runtime_error

namespace CDC
{

    std::string JSONParser::trim(const std::string& str) const
    {
        
        size_t start = 0;
        while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))){
            start++;
        } 
        size_t end = str.size();
        while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) {
            end--;
        }
        return str.substr(start, end - start);
    }

    std::vector<std::string> JSONParser::extractObjects(const std::string& content) const
    {
        std::vector<std::string> objects;
        int braceCount = 0; // To track the nesting level of braces
        std::string currentObject; // To accumulate characters for the current JSON object
        bool insideObject = false; // Flag to indicate whether we are currently inside a JSON object
        
        for (char ch : content) {
            if (ch == '{') {
                // If we encounter an opening brace, we start a new JSON object
                braceCount++;
                insideObject = true;
            }
            if (insideObject) {
                // If we are inside a JSON object, we accumulate characters
                currentObject += ch;
            }
            if(ch == '}') {
                // If we encounter a closing brace, we decrease the brace count
                braceCount--;
                // If the brace count returns to zero, it means we have completed a JSON object
                if (braceCount == 0 && insideObject) {
                    objects.push_back(currentObject); // Add the completed JSON object to the list
                    currentObject.clear(); // Clear the current object for the next one
                    insideObject = false;
                }
            }
        }

        return objects;
    }

    Record JSONParser::parseObject(const std::string& objectContent) const {
        Record record;

        std::string content = trim(objectContent);

        if (!content.empty() && content.front() == '{') {
            content.erase(0, 1);
        }
        if (!content.empty() && content.back() == '}') {
            content.pop_back();
        }

        size_t pos = 0;

        while (pos < content.size()) {
            while (pos < content.size() && std::isspace(static_cast<unsigned char>(content[pos]))) {
                pos++;
            }

            if (pos >= content.size()) {
                break;
            }

            if (content[pos] != '"') {
                break;
            }

            size_t keyStart = pos + 1;
            size_t keyEnd = content.find('"', keyStart);
            if (keyEnd == std::string::npos) {
                break;
            }

            std::string key = content.substr(keyStart, keyEnd - keyStart);
            pos = keyEnd + 1;

            while (pos < content.size() && (std::isspace(static_cast<unsigned char>(content[pos])) || content[pos] == ':')) {
                pos++;
            }

            if (pos >= content.size() || content[pos] != '"') {
                break;
            }
            size_t valueStart = pos + 1;
            size_t valueEnd = content.find('"', valueStart);
            if (valueEnd == std::string::npos) {
                break;
            }

            std::string value = content.substr(valueStart, valueEnd - valueStart);
            record.setField(key, value);
            pos = valueEnd + 1;

            while (pos < content.size() &&
                   (std::isspace(static_cast<unsigned char>(content[pos])) || content[pos] == ',')) {
                pos++;
            }
        }
        return record;
    }


    Dataset JSONParser::parse(const std::string& content) const
    {
        Dataset dataset;
        std::string trimmed = trim(content);

        if (trimmed.empty()) {
            return dataset;
        }

        if (trimmed.front() != '[' || trimmed.back() != ']') {
            return dataset;
        }

        std::vector<std::string> objects = extractObjects(trimmed);
        bool headersSet = false;

        for (const auto& objectStr : objects) {
            Record record = parseObject(objectStr);

            if(!headersSet) {
                std::vector<std::string> headers;
                for (const auto& field : record.getFields()) {
                    headers.push_back(field.first);    
                }
                dataset.setHeaders(headers);
                headersSet = true;
            }
            dataset.addRecord(record);
        }

        return dataset;
    }
    
}
/**
 * NOTES:
 * Use static_cast in the trim method to ensure that the character is treated as 
 * an unsigned char, which is important for correctly handling whitespace characters 
 * in the ASCII range.
 * isspace function checks if the character is a whitespace character (space, tab, newline, etc.)
 * 
 * The extractObjects method uses a simple state machine approach to identify and extract JSON objects
 * from the input string. It keeps track of the nesting level of braces to ensure that it correctly 
 * identifies complete JSON objects, even if they contain nested structures.
 * 
 * parseRecord method is responsible for parsing a single JSON object and converting it into a Record.
 * It handles the extraction of key-value pairs and populates the Record accordingly.
 * How parseRecord works:
 * - It first trims the input string to remove any leading or trailing whitespace.
 * - It then removes the enclosing braces if they exist.
 * - It iterates through the content, extracting key-value pairs enclosed in double quotes.
 * - It skips whitespace and colon characters between keys and values.
 * - It adds each key-value pair to the Record.
 * - It continues until all key-value pairs are processed or an error is encountered.
 *
 */