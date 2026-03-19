# C++ Data Converter (CSV ⇄ JSON)

A simple C++ project that converts data between CSV and JSON formats.

This project is built for learning purposes. It demonstrates:

- Object-Oriented Programming (OOP)
- Basic design patterns (Factory, Strategy-like design)
- Clean project structure
- File handling and parsing

---

## 📌 Features

- Convert CSV → JSON
- Convert JSON → CSV
- Simple and modular architecture
- Easy to extend (e.g. XML, YAML in future)

---

## 📂 Project Structure

cpp_data_converter/

model/
Record.hpp / Record.cpp
Dataset.hpp / Dataset.cpp

parser/
Parser.hpp
CSVParser.hpp / CSVParser.cpp
JSONParser.hpp / JSONParser.cpp

writer/
Writer.hpp
CSVWriter.hpp / CSVWriter.cpp
JSONWriter.hpp / JSONWriter.cpp

core/
Format.hpp
ConverterFactory.hpp / ConverterFactory.cpp
Converter.hpp / Converter.cpp
FormatUtils.hpp / FormatUtils.cpp

data/
sample_data.csv
sample_data.json

---

## 🧠 How It Works

The program does not convert CSV directly to JSON.

Instead, it uses an internal data model:
CSV → CSVParser → Dataset → JSONWriter → JSON
JSON → JSONParser → Dataset → CSVWriter → CSV

### Key Components

#### 1. Model Layer

- `Record`: represents one row (key-value pairs)
- `Dataset`: represents the full table (headers + records)

#### 2. Parser Layer

- `Parser` (abstract class)
- `CSVParser`
- `JSONParser`

These convert text → Dataset

#### 3. Writer Layer

- `Writer` (abstract class)
- `CSVWriter`
- `JSONWriter`

These convert Dataset → text

#### 4. Core Layer

- `Converter`: controls the whole process
- `ConverterFactory`: creates parser/writer objects
- `FormatUtils`: detects file type from extension

---

## ⚙️ Build

Compile using g++:

```bash
g++ main.cpp model/*.cpp parser/*.cpp writer/*.cpp core/*.cpp -o converter
```

## ▶️ Usage

./converter <input_file> <output_file>

Examples

Convert CSV → JSON:
./converter data/sample_data.csv output.json
Convert JSON → CSV:
./converter data/sample_data.json output.csv

## 📥 Input Format

CSV (supported format)

First row = headers

Values separated by ,

No support for quoted fields with commas

JSON (supported format)

Array of objects

All values are strings
