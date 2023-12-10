#include "file_output.h"

FileOutput::FileOutput(const std::string &file_name)
{
    file.open(file_name);

    if (!file.is_open())
    {
        throw std::runtime_error("Ошибка открытия файла для записи");
    }
}

FileOutput::~FileOutput()
{
    if (file.is_open())
    {
        file.close();
    }
}

std::ostream* FileOutput::getOutput()
{
    return &file;
}