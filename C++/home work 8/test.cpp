#include <iostream>
#include <bits/stdc++.h>

using namespace std;
char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
const unsigned char
        PLAYER_X = 'X',
        PLAYER_O = 'O';
unsigned short
    chosenSquare = 0;
unsigned char
    currentPlayer = PLAYER_X,
    lastPlayer = PLAYER_O;
void displayBoard()
{
    cout << endl
         << "current board state:" << endl
         << endl
         << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl
         << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl
         << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl
         << "-+-+-" << endl;
};

    



void getPlayerChoice(char player){
    cout << endl
         << "Player {" << player << "}, enter a number between 1 and 9: ";
    cin >> chosenSquare;
    if(chosenSquare == 1)
        {board[chosenSquare-1][chosenSquare-1] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 2)
        {board[chosenSquare-2][chosenSquare-1] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 3)
        {board[chosenSquare-3][chosenSquare-1] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 4)
        {board[chosenSquare-3][chosenSquare-4] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 5)
        {board[chosenSquare-4][chosenSquare-4] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 6)
        {board[chosenSquare-5][chosenSquare-4] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 7)
        {board[chosenSquare-5][chosenSquare-7] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 8)
        {board[chosenSquare-6][chosenSquare-7] = currentPlayer;swap(lastPlayer, currentPlayer);}else
    if(chosenSquare == 9)
        {board[chosenSquare-7][chosenSquare-7] = currentPlayer;swap(lastPlayer, currentPlayer);}
    else
    {
        cout << "Not a valid choice. Try Again" << endl;
        
    }
};
bool checkForEndGame(short turnNumber,char player){
    bool retval;
    
    if (board[0][0]==player&&board[0][1]==player&&board[0][2]==player)//horizontal
        {cout << "Player " << player << " wins on the upper row!";
        retval =true;}else
    if (board[1][0]==player&&board[1][1]==player&&board[1][2]==player)
        {cout << "Player " << player << " wins on the middle row!";
        retval =true;}else
    if (board[2][0]==player&&board[2][1]==player&&board[2][2]==player)
        {cout << "Player " << player << " wins on the bellow row!";
        retval =true;}else
    if (board[0][0]==player&&board[1][1]==player&&board[2][2]==player||
        board[2][0]==player&&board[1][1]==player&&board[0][2]==player)//diagonal
        {cout << "Player " << player << " wins on the diagonal row!";
        retval =true;}else
    if (board[0][0]==player&&board[1][0]==player&&board[2][0]==player||
        board[0][1]==player&&board[1][1]==player&&board[2][1]==player||
        board[0][2]==player&&board[1][2]==player&&board[2][2]==player)//vertical
        {cout << "Player " << player << " wins on the vertical row!";
        retval =true;}else 
        {
            retval = false;
        }
    if (turnNumber > 9){
        cout << endl << "Draw. Nobody Wins";
        retval = true;
    }
    return retval;
        
    


}
int main(int argc, char const *argv[])
{
    
    short turnNumber = 0;
    while (true)
    {
        displayBoard();
        bool isGameOver = checkForEndGame(turnNumber,lastPlayer);
        if (isGameOver){break;}
        getPlayerChoice(currentPlayer);
        turnNumber++;
    }
    return 0;
}
