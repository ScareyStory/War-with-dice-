/***************************************************************************
** Program Name: Die.hpp
** Name:         Story Caplain
** Date:         01/22/19
** Description:  This is the implementation file for the Die class.
***************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP
#include <iostream>

class Die {

private:

protected:

  int N; //represents the number of sides of the die
  int rando; //used for random number in roll

public:

  Die();

  int getN();

  void setN(int);

  int roll();

};
#endif
