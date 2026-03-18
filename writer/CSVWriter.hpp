// CSVWriter.hpp

#pragma once

#include "Writer.hpp"

namespace CDC
{
    class CSVWriter : public Writer
    {
        public:
            std::string write(const Dataset& dataset) const override;
    };
}