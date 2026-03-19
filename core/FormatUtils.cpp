#include "FormatUtils.hpp"

#include <stdexcept>

namespace CDC
{
    
    Format FormatUtils::detectFormatFromExtension(const std::string& path)
    {
        size_t dotPos = path.find_last_of('.');

        if (dotPos == std::string::npos) {
            throw std::runtime_error("File has no extension: " + path);
        }

        std::string ext = path.substr(dotPos + 1);

        if (ext == "csv") {
            return Format::CSV;
        }

        if (ext == "json") {
            return Format::JSON;
        }

        throw std::runtime_error("Unsupported file extension: " + ext);
    }

}