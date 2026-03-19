#pragma once

#include <memory>

#include "../parser/Parser.hpp"
#include "../writer/Writer.hpp"
#include "Format.hpp"

namespace CDC {
    class ConverterFactory {
    public:
        static std::unique_ptr<Parser> createParser(Format format);
        static std::unique_ptr<Writer> createWriter(Format format);
    };
}

/**
 * NOTES:
 * - The ConverterFactory class provides static methods to create instances of 
 *   Parser and Writer based on the specified Format. This allows for easy 
 *   extension in the future if new formats are added, as you can simply implement
 *   new Parser and Writer classes and update the factory methods accordingly.
 * - The use of std::unique_ptr ensures that the created Parser and Writer instances 
 *   are properly managed and will be automatically deleted when they go out of scope, 
 *   preventing memory leaks.
 * 
 * - <memory> in C++ is a header that provides facilities for managing dynamic memory, 
 *   including smart pointers like std::unique_ptr and std::shared_ptr. In this context, 
 *   std::unique_ptr is used to ensure that the created Parser and Writer instances are 
 *   automatically destroyed when they are no longer needed, thus preventing memory leaks.
 */