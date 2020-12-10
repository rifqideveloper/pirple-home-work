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
void ShowBoard()
{
    cout << endl
         << "current board state:" << endl
         << endl
         << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << endl
         << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << endl
         << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << endl
         << "-+-+-" << endl;
};
void Check_for_winner()
{
    if (board[0][0]==lastPlayer&&board[0][1]==lastPlayer&&board[0][2]==lastPlayer)//horizontal
        {cout << "Player " << lastPlayer << " wins on the upper row!";exit(1);}else
    if (board[1][0]==lastPlayer&&board[1][1]==lastPlayer&&board[1][2]==lastPlayer)
        {cout << "Player " << lastPlayer << " wins on the middle row!";exit(1);}else
    if (board[2][0]==lastPlayer&&board[2][1]==lastPlayer&&board[2][2]==lastPlayer)
        {cout << "Player " << lastPlayer << " wins on the bellow row!";exit(1);}else
    if (board[0][0]==lastPlayer&&board[1][1]==lastPlayer&&board[2][2]==lastPlayer||
        board[2][0]==lastPlayer&&board[1][1]==lastPlayer&&board[0][2]==lastPlayer)//diagonal
        {cout << "Player " << lastPlayer << " wins on the diagonal row!";exit(1);}else
    if (board[0][0]==lastPlayer&&board[1][0]==lastPlayer&&board[2][0]==lastPlayer||
        board[0][1]==lastPlayer&&board[1][1]==lastPlayer&&board[2][1]==lastPlayer||
        board[0][2]==lastPlayer&&board[1][2]==lastPlayer&&board[2][2]==lastPlayer)//vertical
        {cout << "Player " << lastPlayer << " wins on the vertical row!";exit(1);}


};
int main(int argc, char const *argv[])
{
    
    for (short X = 0; X < 9; X++)
    {
    ShowBoard();
    cout << endl
         << "Player {" << currentPlayer << "}, enter a number between 1 and 9: ";
    cin >> chosenSquare;
    Check_for_winner();
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
    }
    
    cout << endl << "Draw. Nobody Wins";
    
    return 0;
}
