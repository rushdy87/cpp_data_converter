#pragma once

#include <string>
#include "Format.hpp"

namespace CDC {
    class Converter {
    public:
        void convert(const std::string& inputPath,
                     const std::string& outputPath,
                     Format inputFormat,
                     Format outputFormat) const;
    };
}