#ifndef eventPattern_h
#define eventPattern_h


class GameEvent
{
public:
    virtual void event() = 0;
    virtual ~GameEvent(){};
};

#endif