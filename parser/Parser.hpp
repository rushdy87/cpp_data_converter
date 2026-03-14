// Parser.hpp

#pragma once

#include <string>
#include "../model/Dataset.hpp"

namespace CDC
{
    class Parser
    {
        public:
            virtual Dataset parse(const std::string& content) const = 0;
            virtual ~Parser() = default;
    };
}

/** NOTES:
 * The Parser class is an abstract base class that defines the interface for parsing content into 
 * a Dataset. The parse method takes a string of content and returns a Dataset object. The destructor 
 * is declared as virtual to ensure proper cleanup of derived classes.
 * This design allows for different parsing strategies (e.g., CSV, JSON, XML) to be implemented 
 * by creating subclasses of Parser that override the parse method. Overall, this design provides 
 * a clear and extensible framework for parsing data into a structured format that can be easily 
 * manipulated and accessed through the Dataset class.
 * 
 * Virtual functions in C++ are used to achieve polymorphism, allowing derived classes to provide 
 * specific implementations of the parse method while still being accessed through a common 
 * interface defined by the Parser class.
 * The use of a pure virtual function (indicated by = 0) makes the Parser class abstract, 
 * meaning it cannot be instantiated on its own and must be subclassed to provide a concrete 
 * implementation of the parse method. The virtual destructor ensures that when a derived class 
 * object is deleted through a pointer to the base class (Parser), the appropriate destructor for 
 * the derived class is called, preventing resource leaks and ensuring proper cleanup.
 * 
 * Why parse method take a string of content instead of a file path?
 * The parse method takes a string of content instead of a file path because we separate between:
 * 1) Reading the file 1) and 2) Parsing the content.
 * This separation allows for greater flexibility and reusability of the parsing logic, 
 * as the same parsing code can be applied to content from different sources (e.g., files, 
 * network, user input) without modification.
 */