#include "console_read.h"



ConsoleCommandRead::ConsoleCommandRead(ISetManagement* manage) : manage(manage)
{
    bind_command_map = manage->getKeyManagement();
}


Command ConsoleCommandRead::read()
{
    char temp = getSymbol();
    return convert(temp);
}


char ConsoleCommandRead::getSymbol() const
{
    termios oldattr;
    tcgetattr(STDIN_FILENO, &oldattr );
    termios newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    int ch = std::getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}


Command ConsoleCommandRead::convert(const char symbol) const
{
    for (const auto& per : bind_command_map)
    {
        if (per.second == symbol)
            return per.first;
    }
    return Command::Invalid;

}