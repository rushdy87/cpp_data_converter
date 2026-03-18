// Writer.hpp

#pragma once

#include <string>
#include "../model/Dataset.hpp"

namespace CDC
{
    class Writer
    {
        public:
            virtual std::string write(const Dataset& dataset) const = 0;
            virtual ~Writer() = default;
    };
}