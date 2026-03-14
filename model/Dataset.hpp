// Dataset.hpp

#pragma once

#include <vector>
#include <string>
#include "Record.hpp"

namespace CDC
{
    class Dataset
    {
    private:
        std::vector<std::string> headers;
        std::vector<Record> records;
    public:
        void setHeaders(const std::vector<std::string>& headers);
        const std::vector<std::string>& getHeaders() const;

        void addRecord(const Record& record);
        const std::vector<Record>& getRecords() const;

        bool isEmpty() const;
    };
}

/** NOTES:
 * The Dataset class is a utility class used to represent a dataset, 
 * which consists of headers and records.
 * - headers: A vector of strings representing the column names of the dataset.
 * - records: A vector of Record objects representing the rows of the dataset.
 * 
 * The class provides methods to set and get headers, add records, retrieve records, 
 * and check if the dataset is empty.
 * 
 * Why isEmpty() method useful?
 * The isEmpty() method is useful to quickly check if the dataset contains any records. 
 * This can be particularly helpful in scenarios where you want to avoid processing an empty dataset, 
 * or when you want to provide feedback to the user about the state of the dataset.
 * 
 * Vectors in C++ are dynamic arrays that can grow in size.
 * They provide efficient access to elements and are commonly 
 * used for storing collections of data. In this case, we use
 * vectors to store headers and records because they allow us 
 * to easily add new records and manage the dataset dynamically.
 * 
 *  Vectors vs. Arrays:
 * - Vectors are dynamic and can resize themselves automatically when elements 
 *   are added or removed, while arrays have a fixed size that must be defined 
 *   at compile time.
 * - Vectors provide built-in functions for adding, removing, and accessing elements,
 *   while arrays require manual management of memory and size.
 * - Vectors are generally safer to use than arrays because they handle memory management
 *   internally, reducing the risk of memory leaks and other memory-related issues.
 */