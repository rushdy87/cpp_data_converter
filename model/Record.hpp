// Record.hpp
// Used to represent a record in the C++ Data Converter (CDC) system, which 
// can hold various fields as key-value pairs.
#pragma once 
#include <string>
#include <map>

namespace CDC {
    class Record {
    private:
        std::map<std::string, std::string> fields;
    
    public:
        void setField(const std::string& key, const std::string& value);
        std::string getField(const std::string& key) const;
        const std::map<std::string, std::string>& getFields() const;
    };

}

/* NOTES:
* "#pragma once" is a non-standard but widely supported preprocessor directive 
* that serves the same purpose as include guards. It ensures that 
* the header file is included only once during compilation, 
* preventing multiple definitions and potential conflicts.
* This can help improve compilation times and reduce the chances of errors 
* caused by multiple inclusions of the same header file.

* "Map" in C++ is a standard library container that stores key-value pairs. 
* It is implemented as a balanced binary search tree (usually a Red-Black Tree),
* which allows for efficient insertion, deletion, and lookup operations.
* The keys in a map are unique, and the values can be accessed using the keys.
* In this context, the map is used to store the fields of a record, where 
* each field has a name (key) and a corresponding value.
* In Python, a "dictionary" is a built-in data structure that also stores 
* key-value pairs. And like a C++ map, the keys in a Python dictionary are 
* unique, and the values can be accessed using the keys. And in 
* Javascript, an "object" is a collection of properties, where each property 
* is a key-value pair. The difference with C++ map is that in Javascript, 
* the keys can be of any type (including strings, numbers, and symbols), 
* and the values can also be of any type. In contrast, in C++ map, the keys 
* and values must be of a specific type defined at compile time.
*/
