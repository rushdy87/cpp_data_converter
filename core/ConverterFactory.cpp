#include "ConverterFactory.hpp"

#include "../parser/CSVParser.hpp"
#include "../parser/JSONParser.hpp"
#include "../writer/CSVWriter.hpp"
#include "../writer/JSONWriter.hpp"

#include <stdexcept>

namespace CDC
{
    std::unique_ptr<Parser> ConverterFactory::createParser(Format format)
    {
        switch (format)
        {
        case Format::CSV:
            return std::make_unique<CSVParser>();
        case Format::JSON:
            return std::make_unique<JSONParser>();
        default:
            throw std::invalid_argument("Unsupported format");
        }
    }

    std::unique_ptr<Writer> ConverterFactory::createWriter(Format format)
    {
        switch (format)
        {
        case Format::CSV:
            return std::make_unique<CSVWriter>();
        case Format::JSON:
            return std::make_unique<JSONWriter>();
        default:
            throw std::invalid_argument("Unsupported format");
        }
    }
}