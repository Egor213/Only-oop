#include "log_tracker.h"

LogTracker::LogTracker()
{
    manage_out = new ManageLogs;
    outs = manage_out->getStream();
}

LogTracker::~LogTracker()
{
    delete manage_out;
}

std::ostream &operator<<(std::ostream &out, IMessage &obj)
{
    out << obj.print();
    return out;
}

void LogTracker::update(IMessage& message)
{
    static size_t number = 0;
    for (auto out : outs)
        *out << "Log: " << number << "# " << message << std::endl;
    number++;
}