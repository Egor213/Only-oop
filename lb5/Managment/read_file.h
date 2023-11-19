#ifndef read_file_h
#define read_file_h
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
class ReadFile
{
public:
    ReadFile(const std::string &file_name);
    ~ReadFile();
    ReadFile(const ReadFile &) = delete;
    ReadFile &operator=(const ReadFile &) = delete;
    ReadFile(ReadFile &&other);
    ReadFile &operator=(ReadFile &&other);
    std::vector<std::string> read();
private:
    FILE *file;
};

#endif