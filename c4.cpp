#include "c4.h"

C4::C4(){

  std::cout << "Welcome to Connect 4!" << std::endl;
  // std::cout << "Would you like to play with another player(p) or with an AI(c)? Please respond with: p/c";
  // std::cin >> _decision;
  std::cout << "Player 1: X \nPlayer 2: O" << std::endl;

}

C4::~C4(){}

void C4::play(){
  std::cout << "Game begins." << std::endl;
  // enter another line to start the game

  //create a board here:
  Board board = Board();

  _p1turn = true; //Player 1 starts first
  _winner = false; // will let the game carry on in the while look until somebody wins

  while(!_winner){
    if(_p1turn){ // when it is Player 1's turn

      //Clear screen for Linux with ANSI code
      std::cout << "\033[2J\033[1;1H";
      _noError = false;
      board.show_board();
      while(!_noError){ // ensures that user selects the right columns
        std::cout << "Player 1: \nPlease select one of the columns:";
        std::cin >> _column;
        if(_column <1 || _column > 7){ // array would go out of range
          std::cout << "Oops, that is not one of the columns!" << std::endl;
        }
        else{

          if(board.mark_board(_column,'X')){
            _noError = true;
          }

          else{
            std::cout << "The selected column is full!" << std::endl;
          }

        }
      }

      _p1turn = false; // ensures that next turn is Player 2's


    }

    else{ // when it is Player 2's turn

      //Clear screen for Linux with ANSI code
      std::cout << "\033[2J\033[1;1H";
      _noError = false;
      board.show_board();
      while(!_noError){ // ensures that user selects the right columns
        std::cout << "Player 2: \nPlease select one of the columns:";
        std::cin >> _column;
        if(_column <1 || _column > 7){ // array would go out of range
          std::cout << "Oops, that is not one of the columns!" << std::endl;
        }
        else{

          if(board.mark_board(_column,'O')){
            _noError = true;
          }

          else{
            std::cout << "The selected column is full!" << std::endl;
          }

        }
      }

      _p1turn = true; // ensures that next turn is Player 1's

    }

    //IF LOOP HERE TO CHECK IF THERE IS WINNER
    std::cout << "\033[2J\033[1;1H";
    board.show_board();
    if(board.check_winner()){
      _winner = true;
    }

    // _winner = true; // NOT part of hte game, exit loop for avoiding infinite loops during testing
  }// while loop closing braces

}
