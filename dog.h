#ifndef _ENTITY_DOG
#define _ENTITY_DOG

#include <iostream>
#include <string>
#include "entity.h"

#define SM_currentState 0       // indexes
#define SM_event        1
#define SM_targetState  2

#define ST_standing     0       // states
#define ST_sitting      1
#define ST_lying        2
#define ST_sleeping     3
#define ST_walking      4
#define ST_running      5

#define EV_toRun        0       // transition events
#define EV_toWalk       1
#define EV_toLay        2
#define EV_toSit        3
#define EV_toStand      4
#define EV_toSleep      5

using namespace std;

class dog_SM : public StateMachine {
  public:
    dog_SM(int defaultState);
    int doChange(int action);

  private:
    int stateTable[13][3] = {
        {ST_standing, EV_toRun,   ST_running },
        {ST_standing, EV_toWalk,  ST_walking },
        {ST_standing, EV_toLay,   ST_lying   },
        {ST_standing, EV_toSit,   ST_sitting },    
        {ST_running,  EV_toStand, ST_standing},
        {ST_running,  EV_toWalk,  ST_walking },
        {ST_walking,  EV_toRun,   ST_running },
        {ST_walking,  EV_toStand, ST_standing},
        {ST_sitting,  EV_toStand, ST_standing},
        {ST_sitting,  EV_toLay,   ST_lying   },
        {ST_lying,    EV_toSit,   ST_sitting },
        {ST_lying,    EV_toSleep, ST_sleeping},
        {ST_sleeping, EV_toLay,   ST_lying   }
    };
};

class Dog : public Entity {
  public:
    Dog(std::string name);
    ~Dog();
    int act(int action);
    
  private:
    dog_SM stateMachine;

};

#endif

