#include "IRremote.h"

//Tic Tac Toe Game in C++

//Importing the inbuild libraries in CPP

//using namespace std;
//Array for the board
char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};
//Variable Declaration
int choice;
char turn = 'X';
bool draw = false;
int ROW, COLUMN;

//Function to show the current status of the gaming board
void display_board(){
//board[0][0] = 'X';
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
          if(board[i][j] == 'X')
          {
            drawX(returnPos(i, j));
          }
          else if(board[i][j] == 'O')
          {
          drawO(returnPos(i, j));
          }
      }
    }
  
}
//Function to get the player input and update the board
void player_turn()
{
      choice = remote(results);
    //switch case to get which ROW and COLUMN will be update
    switch(choice)
    {
        case 1: ROW=0; COLUMN=0; break;
        case 2: ROW=0; COLUMN=1; break;
        case 3: ROW=0; COLUMN=2; break;
        case 4: ROW=1; COLUMN=0; break;
        case 5: ROW=1; COLUMN=1; break;
        case 6: ROW=1; COLUMN=2; break;
        case 7: ROW=2; COLUMN=0; break;
        case 8: ROW=2; COLUMN=1; break;
        case 9: ROW=2; COLUMN=2; break;
        //default:
    }
    if(turn == 'X' && board[ROW][COLUMN] != 'X' && board[ROW][COLUMN] != 'O')
    {
        //updating the position for 'X' symbol if
        //it is not already occupied
        board[ROW][COLUMN] = 'X';
        turn = 'O';
    }else if(turn == 'O' && board[ROW][COLUMN] != 'X' && board[ROW][COLUMN] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        board[ROW][COLUMN] = 'O';
        turn = 'X';
    }
    /*else 
    {
      //if input position already filled
      player_turn();    }
    */
}
//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE
bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}
//Program Main Method
void gameplay()
{
   // cout<<"tttT I C K -- T A C -- T O E -- G A M Ettt";
   // cout<<"nttttFOR 2 PLAYERSnttt";
    while(gameover()){
        display_board();
        drawDisplay(field, row, column);
        player_turn();
    }
    if(turn == 'X' && draw == false){
        //cout<<"nnCongratulations!Player with 'X' has won the game";
    }
    else if(turn == 'O' && draw == false){
        //cout<<"nnCongratulations!Player with 'O' has won the game";
    }
    //else
    //cout<<"nnGAME DRAW!!!nn";
}
