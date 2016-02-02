/* program for testing Observer and StateMachine */

#include <iostream>
#include <string>
#include "dog.h"
#include "fuzzy.h"

int main() {

  Dog my_dog("Fido");

  my_dog.act(EV_toWalk);
  my_dog.act(EV_toSit);
  
  return 0;
}

