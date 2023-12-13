#include "manage_logs.h"



ManageLogs::~ManageLogs()
{
    for (auto ptr : temp_vec)
        delete ptr;
} 

std::vector<std::ostream*> ManageLogs::getStream()
{
    return getOut();
}

std::vector<std::ostream*> ManageLogs::getOut()
{
    char temp;
    IOuput* temp_out;
    std::cout << "Введите куда будет происходить логгирование:\n\t0 - файл\n\t1 - консоль\n\t2 - консоль и файл\n\t3 - никуда\n";
    temp = getchar();
        
    switch(temp)
    {
        case '1':
            temp_out = new ConsoleOutput();
            temp_vec.push_back(temp_out->getOutput());
            return temp_vec;
        case '2':
            temp_out = new FileOutput("logs.txt");
            temp_vec.push_back(temp_out->getOutput());
            temp_out = new ConsoleOutput();
            temp_vec.push_back(temp_out->getOutput());
            return temp_vec;
        case '3':
            return temp_vec;
        default:
            temp_out = new FileOutput("logs.txt");
            temp_vec.push_back(temp_out->getOutput());
            return temp_vec;
    }
    delete temp_out;
}


