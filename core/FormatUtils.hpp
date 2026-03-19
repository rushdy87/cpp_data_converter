#pragma once

#include <string>
#include "Format.hpp"

namespace CDC {
    class FormatUtils {
    public:
        static Format detectFormatFromExtension(const std::string& path);
    };
}