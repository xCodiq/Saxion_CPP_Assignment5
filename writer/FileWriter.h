//
// Created by elmar on 07/04/2022.
//

#ifndef CPPASSIGNMENT5_FILEWRITER_H
#define CPPASSIGNMENT5_FILEWRITER_H

#include <iostream>
#include <string>

class FileWriter {
public:
    // opens file using std::fopen
    FileWriter(const char *fileName);

    // flushes the stream and closes the file using std::fclose if it's open
    ~FileWriter();

    // return true if an associated file is open (opening can fail in constructing class)
    [[nodiscard]] bool is_open();

    FileWriter &write(const std::string &string);

    FileWriter &write(const char *str);

    FileWriter &write(const char character);

    FileWriter &write(const int integer);

    FileWriter &write(const double number);

    FileWriter &write(const bool boolean);

    FileWriter &then(const std::string &str);

    FileWriter &then(const char *str);

    FileWriter &then(const char character);

    FileWriter &then(const int integer);

    FileWriter &then(const double number);

    FileWriter &then(const bool boolean);

    FileWriter &newLine();

    [[nodiscard]] int lines() const;

    [[nodiscard]] int count() const;

private:
    FILE *m_file;

    size_t m_characters_written = 0;
    size_t m_lines = 0;

    template<typename T>
    void add_new_line_occurrences(T input);
};


#endif //CPPASSIGNMENT5_FILEWRITER_H
