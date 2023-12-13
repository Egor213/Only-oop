#ifndef iview_h
#define iview_h



class IView
{
public:
    virtual void update() = 0;
    virtual void updateChooseLvl() = 0;
    virtual void updateEndGame() = 0;
    virtual void updateRestart() = 0;
    virtual void updateEndGameLessHp() = 0;
    virtual void updateInvalideKey() = 0;
    virtual ~IView() {}
};


#endif