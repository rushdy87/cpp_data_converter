#pragma once

#include "Writer.hpp"

namespace CDC
{
    class JSONWriter : public Writer
    {
        public:
            std::string write(const Dataset& dataset) const override;
    };
}