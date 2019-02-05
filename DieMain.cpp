/***************************************************************************
** Program Name: DieMain.cpp
** Name:         Story Caplain
** Date:         01/23/19
** Description:  This program simulates a game of war with dice. A player 
**               can choose the number of sides of their die and whether or
**               not they want to use a loaded die. Detailed statistics will
**               be printed out between rounds and after the game as well.
***************************************************************************/
#include <iostream>
#include "menu.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

int main() {

  int val  = 1; //will be used for input validation
  int play = 0; //will be used to see if user wants to play

  play = menu();

  while(play == 1) {
   
    Die p1Fair;
    Die p2Fair;

    LoadedDie p1Load;
    LoadedDie p2Load;

    int p1Sides  = 0;
    int p2Sides  = 0;
    int p1Type   = 0;
    int p2Type   = 0;
    int numRolls = 0;
    int p1Score  = 0;
    int p2Score  = 0;

    cout << "\nHow many sides would player 1 like their die to have?: ";
    cin  >> p1Sides;
    val = 1;
    //input validation  
    while(val == 1) {
      //Make 100 the max for cleaner values
      if(cin.fail() || p1Sides < 1 || p1Sides > 100) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter an integer in the range 1 to 100: ";
        cin  >> p1Sides;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    cout << "\nHow many sides would player 2 like their die to have?: ";
    cin  >> p2Sides;
    val = 1;
    //input validation  
    while(val == 1) {
      //Make 100 the max for cleaner values
      if(cin.fail() || p2Sides < 1 || p2Sides > 100) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter an integer in the range 1 to 100: ";
        cin  >> p2Sides;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    cout << "\nWould player 1 like a fair die or a loaded die?\n";
    cout << "Enter 0 for a fair die and 1 for a loaded die: ";
    cin  >> p1Type;
    val = 1;
    //input validation  
    while(val == 1) {
      //Make 100 the max for cleaner values
      if(cin.fail() || (p1Type != 0 && p1Type != 1)) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 0 or 1 only: ";
        cin  >> p1Type;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    cout << "\nWould player 2 like a fair die or a loaded die?\n";
    cout << "Enter 0 for a fair die and 1 for a loaded die: ";
    cin  >> p2Type;
    val = 1;
    //input validation  
    while(val == 1) {
      //Make 100 the max for cleaner values
      if(cin.fail() || (p2Type != 0 && p2Type != 1)) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a 0 or 1 only: ";
        cin  >> p2Type;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    //If fair die, set sides of fair die
    if(p1Type == 0) {
      p1Fair.setN(p1Sides);
    }
    //If Loaded die, set sides of loaded die
    if(p1Type == 1) {
      p1Load.setN(p1Sides);
    }

    //If fair die, set sides of fair die
    if(p2Type == 0) {
      p2Fair.setN(p2Sides);
    }
    //If Loaded die, set sides of loaded die
    if(p2Type == 1) {
      p2Load.setN(p2Sides);
    }

    //Ask users for number of rolls
    cout << "\nHow many rolls would you like your game to have?: ";
    cin  >> numRolls;
    val = 1;
    //input validation  
    while(val == 1) {
      //Make 10000 the max
      if(cin.fail() || numRolls < 1 || numRolls > 10000) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << endl;
        cout << "Enter a positive integer (Max: 10,000): ";
        cin  >> p2Sides;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    //Roll dice, both fair
    if(p1Type==0 && p2Type==0) {
      for(int i = 0; i < numRolls; i++) {
        
        int p1Side = p1Fair.roll();
        int p2Side = p2Fair.roll();
        
        if(p1Side > p2Side) {
          p1Score++;
        }
        else if(p2Side > p1Side) {
          p2Score++;
        }

        //Output Stats for round
        cout << "\nPlayer 1 rolled a " << p1Side;
        cout << "\nPlayer 1's score = " << p1Score;
        cout << "\nPlayer 1's die is fair.";

        cout << "\n\nPlayer 2's side  = " << p2Side;
        cout <<   "\nPlayer 2's score = " << p2Score;
        cout <<   "\nPlayer 2's die is fair.";
        
        cout << "\nPress enter to roll again...";
        cin.ignore();
      }
    }
    //Roll dice, p1 loaded, p2 fair
    else if(p1Type==1 && p2Type==0) {
      for(int i = 0; i < numRolls; i++) {
        
        int p1Side = p1Load.roll();
        int p2Side = p2Fair.roll();
        
        if(p1Side > p2Side) {
          p1Score++;
        }
        else if(p2Side > p1Side) {
          p2Score++;
        }

        //Output Stats for round
        cout << "\nPlayer 1 rolled a " << p1Side;
        cout << "\nPlayer 1's score = " << p1Score;
        cout << "\nPlayer 1's die is loaded!";

        cout << "\n\nPlayer 2 rolled a " << p2Side;
        cout <<   "\nPlayer 2's score = " << p2Score;
        cout <<   "\nPlayer 2's die is fair.";

        cout << "\nPress enter to roll again...";
        cin.ignore();
      }
    }
    //Roll dice, p1 fair, p2 loaded
    else if(p1Type==0 && p2Type==1) {
      for(int i = 0; i < numRolls; i++) {
        
        int p1Side = p1Fair.roll();
        int p2Side = p2Load.roll();

        if(p1Side > p2Side) {
          p1Score++;
        }
        else if(p2Side > p1Side) {
          p2Score++;
        }

        //Output Stats for round
        cout << "\nPlayer 1 rolled a " << p1Side;
        cout << "\nPlayer 1's score = " << p1Score;
        cout << "\nPlayer 1's die is fair.";

        cout << "\n\nPlayer 2 rolled a " << p2Side;
        cout <<   "\nPlayer 2's score = " << p2Score;
        cout <<   "\nPlayer 2's die is loaded!";

        cout << "\nPress enter to roll again...";
        cin.ignore();
      }
    }
    //Roll dice, both loaded
    else if(p1Type==1 && p2Type==1) {
      for(int i = 0; i < numRolls; i++) {
        
        int p1Side = p1Load.roll();
        int p2Side = p2Load.roll();
        
        if(p1Side > p2Side) {
          p1Score++;
        }
        else if(p2Side > p1Side) {
          p2Score++;
        }

        //Output Stats for round
        cout << "\nPlayer 1 rolled a " << p1Side;
        cout << "\nPlayer 1's score = " << p1Score;
        cout << "\nPlayer 1's die is loaded!";

        cout << "\n\nPlayer 2 rolled a " << p2Side;
        cout <<   "\nPlayer 2's score = " << p2Score;
        cout <<   "\nPlayer 1's die is loaded!";

        cout << "\nPress enter to roll again...";
        cin.ignore();
      }
    }
    cout << "\n\n";
    cout << numRolls << " rolls completed!";
    cout << "\n\nPlayer 1 has a final score of: " << p1Score;
    cout <<   "\nPlayer 2 has a final score of: " << p2Score;
    if(p1Score > p2Score) {
      cout << "\nCongratualtions Player 1!\n"; 
      cout << "You won by " << p1Score - p2Score << " points!";
    }
    else if(p2Score > p1Score) {
      cout << "\nCongratualtions Player 2!\n";
      cout << "You won by " << p2Score - p1Score << " points!";
    }
    else {
      cout << "\nPlayers 1 and 2 tie. Nobody wins :(";
    }
      
    char again;
    cout << "\n\nWould you like to play again?";
    cout << "\nEnter p to play, type anything else to quit: ";
    cin  >> again;
    if(cin.fail() || (again != 'p' && again != 'P')) {
      play = 0;
    }
    else {
      play = 1;
    }
  }
}
