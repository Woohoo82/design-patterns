#ifndef _STATE_MACHINE
#define _STATE_MACHINE

class StateMachine {
  public:
    StateMachine(int defaultState);
    virtual ~StateMachine();
    virtual int doChange(int action) = 0;
    
  protected:
    int currentState;

};

#endif

