#include "JSONWriter.hpp"
#include <sstream>

namespace CDC
{
    std::string JSONWriter::write(const Dataset& dataset) const
    {
        std::stringstream ss;
        ss << "[\n";

        const auto& headers = dataset.getHeaders();
        const auto& records = dataset.getRecords();

        for(size_t i = 0; i < records.size(); ++i)
        {
            const auto& record = records[i];

            ss << "{ ";

            for (size_t j = 0; j < headers.size(); j++)
            {
                const auto& key = headers[j];
                std::string value = record.getField(key);

                ss << "\"" << key << "\": \"" << value << "\"";

                if (j < headers.size() - 1) {
                    ss << ", ";
                }
            }

            ss << " }";

            if (i < records.size() - 1) {
                ss << ",";
            }

            ss << "\n";
        }
        ss << "]";

        return ss.str();
    }
};