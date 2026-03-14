// Dataset.cpp

#include "Dataset.hpp"

namespace CDC
{
    void Dataset::setHeaders(const std::vector<std::string>& headers)
    {
        this->headers = headers;
    }

    const std::vector<std::string>& Dataset::getHeaders() const
    {
        return headers;
    }

    void Dataset::addRecord(const Record& record)
    {
        records.push_back(record);
    }

    const std::vector<Record>& Dataset::getRecords() const
    {
        return records;
    }

    bool Dataset::isEmpty() const
    {
        return records.empty();
    }
}