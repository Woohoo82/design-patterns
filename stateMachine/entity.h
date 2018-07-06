#ifndef _ENTITY
#define _ENTITY

#include <string>
#include "statemachine.h"

class Entity {
  public:
    Entity(std::string _name);
    virtual ~Entity();
    virtual int act(int action) = 0;
    
  protected:
    std::string name;
    

};

#endif

