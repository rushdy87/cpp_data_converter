// Record.cpp
// Implementation of the Record class defined in Record.hpp, which is 
// used to represent a record in the C++ Data Converter (CDC) system, 
// allowing it to hold various fields as key-value pairs

#include "Record.hpp"

namespace CDC {
    void Record::setField(const std::string& key, const std::string& value) {
        fields[key] = value;
    }

    std::string Record::getField(const std::string& key) const {
        auto it = fields.find(key);
        if (it != fields.end()) {
            return it->second;
        }
        return "";
    }

    const std::map<std::string, std::string>& Record::getFields() const {
        return fields;
    }
}
