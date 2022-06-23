//
// Created by elmar on 07/04/2022.
//

#include "FileWriter.h"

FileWriter::FileWriter(const char *fileName) : m_file(std::fopen(fileName, "r+")) {
    if (this->is_open()) {
        std::cout << "Opening \"" << fileName << "\"" << std::endl;
    } else {
        std::cerr << "Err: Something went wrong while opening \"" << fileName << "\"" << std::endl;
    }
}

FileWriter::~FileWriter() {
    std::fclose(this->m_file);
}

bool FileWriter::is_open() {
    return m_file != nullptr;
}

FileWriter &FileWriter::write(const std::string &string) {
    this->m_characters_written += std::fprintf(m_file, "%s", &string);
    this->add_new_line_occurrences(string);
    std::fflush(m_file);
    return *this;
}

FileWriter &FileWriter::write(const char *str) {
    this->m_characters_written += std::fprintf(m_file, "%s", str);
    this->add_new_line_occurrences(str);
    std::fflush(m_file);
    return *this;
}

FileWriter &FileWriter::write(const char character) {
    this->m_characters_written += std::fprintf(m_file, "%c", character);
    this->add_new_line_occurrences(character);
    std::fflush(m_file);
    return *this;
}

FileWriter &FileWriter::write(const int integer) {
    this->m_characters_written += std::fprintf(m_file, "%d", integer);
    std::fflush(m_file);
    return *this;
}

FileWriter &FileWriter::write(const double number) {
    this->m_characters_written += std::fprintf(m_file, "%.5f", number);
    std::fflush(m_file);
    return *this;
}

FileWriter &FileWriter::write(const bool boolean) {
    return this->write(boolean ? "true" : "false");
}

FileWriter &FileWriter::then(const std::string &str) {
    return this->write(str);
}

FileWriter &FileWriter::then(const char *str) {
    return this->write(str);
}

FileWriter &FileWriter::then(const char character) {
    return this->write(character);
}

FileWriter &FileWriter::then(const int integer) {
    return this->write(integer);
}

FileWriter &FileWriter::then(const double number) {
    return this->write(number);
}

FileWriter &FileWriter::then(const bool boolean) {
    return this->write(boolean);
}

FileWriter &FileWriter::newLine() {
    return this->write("\n");
}

int FileWriter::lines() const {
    return this->m_lines;
}

int FileWriter::count() const {
    return this->m_characters_written;
}

template<typename T>
void FileWriter::add_new_line_occurrences(T input) {
    std::string inputStr{input};
    char new_line_char = '\n';

    int count = 0;
    for (int i = 0; (i = inputStr.find(new_line_char, i)) != std::string::npos; i++) {
        count++;
    }

    if (count != 0) this->m_lines += count;
}
