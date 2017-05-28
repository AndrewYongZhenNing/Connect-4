#ifndef _CONNECT_4_
#define _CONNECT_4_

//Relevant class header files
#include "board.h"

//Relevant libraries
#include <iostream>

class C4{

public:
  C4();
  ~C4();
  void start_game();

private:
  char _decision; // to be used whenever a user input is required
  bool _p1turn; // determines whether it is Player 1's turn or not
  bool _winner; // determines whether a winner has been selected
  int _column; // the column selected by the Player

  bool _noError; // an error handling boolean

};

#endif
