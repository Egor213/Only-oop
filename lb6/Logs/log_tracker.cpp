#include "log_tracker.h"

LogTracker::LogTracker(Game *game) : game(game)
{
    manage_out = new ManageLogs;
    outs = manage_out->getStream();
    win = new WinMessage(game, this);
    lose = new LoseMessage(game, this);
    new_game_mess = new NewGameMessage(game, this);
    dont_mess = new DontCommandMessage(game, this);
    do_mess = new DoCommandMessage(game, this);
    game->addLogObserver(win);
    game->addLogObserver(new_game_mess);
    game->addLogObserver(dont_mess);
    game->addLogObserver(lose);
    game->addLogObserver(do_mess);
}

LogTracker::~LogTracker()
{
    delete win;
    delete new_game_mess;
    delete lose;
    delete do_mess;
    delete dont_mess;
    delete manage_out;
}

std::ostream &operator<<(std::ostream &out, IMessage &obj)
{
    std::time_t currentTime = std::time(nullptr);
    std::tm *localTime = std::localtime(&currentTime);
    std::map<LogsEnum, std::any> temp = obj.getData();
    std::map<LogsEnum, std::string> convert = {
        {LogsEnum::Key, "Key: "},
        {LogsEnum::Commands, "Command: "},
        {LogsEnum::LoseY, "LoseY: "},
        {LogsEnum::LoseX, "LoseX: "},
        {LogsEnum::Height, "Height: "},
        {LogsEnum::Width, "Width: "},
        {LogsEnum::StartX, "StartX: "},
        {LogsEnum::StartY, "StartY: "},
        {LogsEnum::HealPoint, "HealPoint: "},
        {LogsEnum::Attack, "Attack: "},
        {LogsEnum::Experience, "Experience: "}};
    std::map<Command, std::string> convert_command = {
     {Command::MoveLeft, "MoveLeft"},
        {Command::MoveDown, "MoveDown"},
        {Command::MoveRight, "MoveRight"},
        {Command::MoveUp, "MoveUp"},
        {Command::Quit, "Quit"},
        {Command::Restart, "Restart"},
        {Command::Invalid, "Invalid"}};
    if (localTime != nullptr)
    {
        out << "Time: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << ' ';
    }
    for (const auto &pair : temp)
    {
        out << convert[pair.first];
        try
        {
            if (pair.second.type() == typeid(int))
                out << std::any_cast<int>(pair.second);
            else if (pair.second.type() == typeid(std::string))
                out << std::any_cast<std::string>(pair.second);
            else if (pair.second.type() == typeid(char))
                out << std::any_cast<char>(pair.second);
            else if (pair.second.type() == typeid(Command))
                out << convert_command[std::any_cast<Command>(pair.second)];
            else if (pair.second.type() == typeid(unsigned))
                out << std::any_cast<unsigned>(pair.second);
            else
                std::cerr << "Unknown type";
        }
        catch (const std::bad_any_cast &what)
        {
            std::cerr << "Exception: " << what.what();
        }
        out << " ";
    }
    return out;
}

void LogTracker::update(LogObservers observer)
{
    static size_t number = 0;
    switch (observer)
    {
    case LogObservers::DoCommand:
        for (auto out : outs)
            *out << "Log: " << number << "# " << *do_mess << std::endl;
        break;

    case LogObservers::DontCommand:
        for (auto out : outs)
            *out << "Log: " << number << "# " << *dont_mess << std::endl;
        break;

    case LogObservers::WinGame:
        for (auto out : outs)
            *out << "Log: " << number << "# " << *win << std::endl;
        break;

    case LogObservers::NewGame:
        for (auto out : outs)
            *out << "Log: " << number << "# " << *new_game_mess << std::endl;
        break;

    case LogObservers::LoseGame:
        for (auto out : outs)
            *out << "Log: " << number << "# " << *lose << std::endl;
        break;

    default:
        break;
    }
    number++;
}