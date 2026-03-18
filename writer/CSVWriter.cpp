#include "CSVWriter.hpp"
#include <sstream>

namespace CDC
{
    std::string CSVWriter::write(const Dataset& dataset) const
    {
        std::stringstream ss;

        const auto& headers = dataset.getHeaders();
        const auto& records = dataset.getRecords();

        // Write headers
        for (size_t i = 0; i < headers.size(); i++) {
            ss << headers[i];
            if (i < headers.size() - 1) {
                ss << ",";
            }
        }

        ss << "\n";

        // Write records
        for (const auto& record : records) {
            for (size_t i = 0; i < headers.size(); i++) {
                ss << record.getField(headers[i]);
                if (i < headers.size() - 1) {
                    ss << ",";
                }
            }
            ss << "\n";
        }

        return ss.str();
    }
}