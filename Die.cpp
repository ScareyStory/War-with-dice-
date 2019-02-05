/***************************************************************************
** Program Name: Die.cpp
** Name:         Story Caplain
** Date:         01/22/19
** Description:  This is the cpp file for the Die class. It has a roll
**               function which returns a number between 1 and the user
**               chosen number of sides for the die.
***************************************************************************/
#include <random>
#include "Die.hpp"
#include <iostream>

Die::Die() {
  this->N = 0; //number of sides of die is equal to 0 by default
}

int Die::getN() {
  return this->N; //accessor
}  

void Die::setN(int sides) {
  this->N = sides; //mutator
}

int Die::roll() {
  rando = rand(); //stores a random number in rando
  rando =  (rando % N); //makes rando's range 0 - (N-1)
  rando++;              //rando's range is 1 - N
  return rando;
}
