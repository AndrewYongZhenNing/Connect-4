#ifndef _BOARD_
#define _BOARD_

//Relevant libraries
#include <iostream>
#include <vector>

class Board{
public:
  Board(); // initialises a board that is 7 column by 6 rows
  ~Board();
  void show_board(); // print the current state of the board
  bool mark_board(int u_col, char mark);
  bool check_4();
  bool check_winner();

private:
  std::vector<std::vector<char> > _board; // board for Players to play the game on
  int _col;
  bool _marked;
};

#endif
