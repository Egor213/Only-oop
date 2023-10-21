#ifndef read_file_cpp
#define read_file_cpp
#include "read_file.h"

ReadFile::ReadFile(const std::string &file_name)
{
    file = std::fopen(file_name.c_str(), "r");
    if (file == nullptr)
    {
        throw std::runtime_error("cannot open " + file_name);
    }
}

ReadFile::ReadFile(ReadFile &&other) : file(nullptr)
{
    std::swap(file, other.file);
}

ReadFile &ReadFile::operator=(ReadFile &&other)
{
    std::swap(file, other.file);
    return *this;
}

ReadFile::~ReadFile()
{
    if (file != nullptr)
    {
        std::fclose(file);
    }
}

std::vector<std::string> ReadFile::read()
{
    std::vector<std::string> strings;
    char line[1024];
    while (fgets(line, sizeof(line), file) != nullptr)
    {
        std::string temp(line);
        strings.push_back(temp);
    }
    return strings;
}

#endif