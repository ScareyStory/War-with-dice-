/***************************************************************************
** Program Name: LoadedDie.cpp
** Name:         Story Caplain
** Date:         01/23/19
** Description:  This is the cpp file for the LoadedDie class. It has a roll
**               function which returns a number between 1 and the user
**               chosen number of sides for the die. A Loaded die differs
**               from a Die in that a LoadedDie average roll is higher than 
**               a Die average roll.
***************************************************************************/
#include <iostream>
#include <random>
#include "LoadedDie.hpp"

LoadedDie::LoadedDie() : Die() {
  this->N = 0; //number of sides of die is equal to 0 by default
}

int LoadedDie::roll() {
  rando = rand();           //stores a random number in rando
  loaded = (rando % N);     //makes rando's range 1-6 stores in loaded
  loaded++;
  if(loaded < N) {
    loaded++;
  }
  return this->loaded;
}
