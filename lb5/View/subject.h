#ifndef subject_h
#define subject_h
#include "observer.h"

class Subject
{

public:
    virtual void addObserver(Observer* apObserver) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notify(ViewEvent view_event) = 0;
};

#endif