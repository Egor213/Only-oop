#ifndef log_tracker_h
#define log_tracker_h
#include "../Game/game.h"
#include <ctime>
#include "manage_logs.h"



class LogTracker
{
public:
    LogTracker();
    ~LogTracker();
    void update(IMessage& message);
    
   
private:
    ManageLogs* manage_out;
  
   std::vector<std::ostream*> outs;


};

#endif