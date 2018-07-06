#include "dog.h"

// TODO a StateMachine.h-ba kéne tenni egy stateTable-re mutató pointert
// és a doChange-t is visszatenni, míg a tábla deklarálása később zajlik

// derived StateMachine for dog

dog_SM::dog_SM(int defaultState = ST_standing) : StateMachine(defaultState){

}

int dog_SM::doChange(int action){

  int length = sizeof(stateTable)/sizeof(stateTable[0][0]);

  for (int i=0; i<length; i++) {
   
    if (stateTable[i][SM_currentState] == currentState &&
        stateTable[i][SM_event]        == action ) {
          
          cout << "State changed: " << currentState;
          currentState = stateTable[i][SM_targetState];
          cout << " -> " << currentState << endl;
          return 0;
    }
  }

  cout << "State not changed" << endl;
  return 1;
}

// derived Entity for dog

Dog::Dog(std::string name) : Entity(name) {
  
}

Dog::~Dog(){

}

int Dog::act(int action){
  cout << "Event for " << name << ": ";
  return stateMachine.doChange(action);
}

