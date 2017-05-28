#include "board.h"

Board::Board(){
  std::cout << "Creating board..." << std::endl;

  for (int i = 0; i <6; i++){
    _board.push_back(std::vector<char> (7, 'a'));
  }

  std::cout << _board.size() << std::endl;
  for(int j = 0; j < _board.size(); j++){
    for(int k = 0; k< _board[j].size(); k++){
      std::cout << _board[j][k] <<  std::endl;
    }
   }

   std::cout << _board[0].size()*_board.size() << std::endl;


  // char **_board  = new char [6]; // initialises an array with 6 elements (rows)
  // for(int i = 0; i < 6; i++){
  //   *_board = new char[7]; // initialises an array of 7 elements (columns) in each of the 6 elements (rows)
  // }
}

Board::~Board(){
  std::cout << "Removing board:" << std::endl;
  // for(int j = 0; j < 7; j++){// deletes the columns first
  //   std::cout << "Deleting column " << j << "..." <<std::endl;
  //   delete [] _board[j];
  // }
  //
  // std::cout << "Deleting rows..." << std::endl;
  // delete [] _board; // delete the rows
  //
  // std::cout << "Board successfully removed from heap." << std::endl;

}
