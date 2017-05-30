#include "board.h"

Board::Board(){
  std::cout << "Creating board..." << std::endl;

  for (int i = 0; i <6; i++){
    _board.push_back(std::vector<char> (7, ' '));
  }


}

Board::Board(int x_dim, int y_dim){
  std::cout << "Creating board..." << std::endl;

  for (int i = 0; i <x_dim; i++){ // row instantiation
    _board.push_back(std::vector<char> (y_dim, ' ')); // column instantiation
  }

}

Board::~Board(){}

void Board::show_board(){


  for(int x = 0; x < _board.size(); x++){
    for(int y = 0; y < _board[x].size(); y++){
      if(y == 0){ // to provide left side padding
        std::cout << "| " << std::flush;
      }
      std::cout << _board[x][y] << " | " << std::flush; // provide partition between oclumns
    }
    std::cout<<std::endl;
  }

  for(int z=0; z < _board[0].size(); z++){
    if(z == 0){
      std::cout << "| " << std::flush;
    }
    std::cout << z+1 << " | " <<std::flush;
  }

  std::cout<<std::endl;
}

bool Board::mark_board(int u_col, char mark){ // user will input col
  _marked = false;
  _col = u_col-1; // translate user , chosen column into array index

  if(_board[0][_col] != ' '){ // if the top entry of the column is filled
    return false;
  }

  else{
    for(int row = 5; row >=0; row--){ // count from bottom most row

      if(!_marked){
        if(_board[row][_col]==' '){ //
          _board[row][_col] = mark;
          _marked = true;
        }
      }

    }

    return true;
  }

}

bool Board::check_4(){
  bool connect4= false;
  int x,y;

  //horizontal check
  for(int row = 5; row >=0; row--){
    if(!connect4){ // only iterate if no 4 tiles are connected
      for(int col = 0; col <=6; col++){ // start from leftmost column
        if(col+3 <=6){ // make sure not to go out of range
          if(_board[row][col] == _board[row][col+1] && _board[row][col+1]==_board[row][col+2] && _board[row][col+2]==_board[row][col+3]){
            if(_board[row][col] != ' '){
              connect4 = true;
              x = col;
              y = row;
            }
          }
        }
      }
    }

  }

  //vertical check
  for(int col = 0; col <=6; col++){
    if(!connect4){ // only iterate if no 4 tiles are connected
      for(int row = 5; row >=0; row--){ // start from bottom most row
        if(row-3 >=0 ){ // make sure not to go out of range
          if(_board[row][col] == _board[row-1][col] && _board[row-1][col]==_board[row-2][col] && _board[row-2][col]==_board[row-3][col]){
            if(_board[row][col] != ' '){
              connect4 = true;
              x = col;
              y = row;
            }
          }
        }
      }
    }

  }

  // diagonal(/) check
  for(int col = 0; col <=6; col++){
    if(!connect4){ // only iterate if no 4 tiles are connected
      for(int row = 0; row <=5; row++){ // start from bottom most row
        if(row+3 <=5 && col+3 <=6){ // make sure not to go out of range
          if(_board[row][col] == _board[row+1][col+1] && _board[row+1][col+1]==_board[row+2][col+2] && _board[row+2][col+2]==_board[row+3][col+3]){
            if(_board[row][col] == 'X' || _board[row][col] == 'O'){
              connect4 = true;
              x = col;
              y = row;
            }
          }
        }
      }
    }

  }
  //diagonal (\) check
  for(int col = 0; col <=6; col++){
    if(!connect4){ // only iterate if no 4 tiles are connected
      for(int row = 5; row >=0; row--){ // start from bottom most row
        if(row-3 >=0 && col+3 <=6){ // make sure not to go out of range
          if(_board[row][col] == _board[row-1][col+1] && _board[row-1][col+1]==_board[row-2][col+2] && _board[row-2][col+2]==_board[row-3][col+3]){
            if(_board[row][col] == 'X' || _board[row][col] == 'O'){
              connect4 = true;
              x = col;
              y = row;
            }
          }
        }
      }
    }

  }

  if(connect4){
    if (_board[y][x] == 'X'){
      std::cout << "Player 1 wins!" << std::endl;
      return true;
    }

    else if(_board[y][x] == 'O'){
      std::cout << "Player 2 wins!" << std::endl;
      return true;
    }
  }

  else{ // game continues
    return false;

  }
}

bool Board::check_winner(){
  //Check if tie
  int empty_slot = 0;
  for(int col = 0; col < _board[0].size(); col++){ // only look at first row
    if(_board[0][col] == ' '){
      empty_slot++;
    }
  }

  if(empty_slot ==0){ // first row is full, game is a tie
    std::cout << "Game is a tie." << std::endl;
    return true; // exits the while loop

  }

  else{
    if(check_4()){ //player 1 wins
      // std::cout << "Congratulations! Player 1 wins!" << std::endl;
      return true;
    }
    //
    // else if(check_4('O')){// player 2 wins
    //   std::cout << "Congratulations! Player 2 wins!" << std::endl;
    //   return true;
    // }

    else{ // no winner yet, game continues
      return false;
    }
    //check 4 in a row
  }

}
