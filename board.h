#ifndef _BOARD_
#define _BOARD_

//Relevant libraries
#include <iostream>
#include <vector>

class Board{
public:
  Board(); // initialises a board that is 7 column by 6 rows
  ~Board();

private:
  std::vector<std::vector<char> > _board;//(6,std::vector<char> (7,' '))
};

#endif
