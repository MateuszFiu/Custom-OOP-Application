#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];   
    char currentPlayer; 

public:
 
    TicTacToe() {
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }

       
        currentPlayer = 'X';
    }

    
    void displayBoard() {
        cout << "  1 2 3" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

 
    bool makeMove(int row, int col) {
       
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;  
        }
        return false; 
    }


    bool checkWin() {

        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true; 

            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true; 
        }

        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true; 

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true; 

        return false;  
    }


    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false; 
            }
        }
        return true;  
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() {
        return currentPlayer;
    }
};