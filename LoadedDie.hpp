/***************************************************************************
** Program Name: LoadedDie.hpp
** Name:         Story Caplain
** Date:         01/23/19
** Description:  This is the implementation file for the LoadedDie class.
***************************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include <iostream>
#include "Die.hpp"

class LoadedDie : public Die {

private:

  int loaded = 0;

protected:

public:

  LoadedDie();

  int roll();

};
#endif

