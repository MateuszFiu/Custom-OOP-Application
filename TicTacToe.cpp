#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];   // Plansza do gry
    char currentPlayer;  // Aktualny gracz (X lub O)

public:
    // Konstruktor inicjalizujący planszę i ustawiający pierwszego gracza na X
    TicTacToe() {
        // Inicjalizacja planszy
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }

        // Ustawienie pierwszego gracza
        currentPlayer = 'X';
    }

    // Wyświetla planszę do gry
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

    // Próba wykonania ruchu w danym miejscu przez aktualnego gracza
    bool makeMove(int row, int col) {
        // Sprawdzenie, czy pole jest wolne
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            return true;  // Ruch udany
        }
        return false;  // Pole zajęte
    }

    // Sprawdzenie, czy aktualny gracz wygrał
    bool checkWin() {
        // Sprawdzenie wierszy, kolumn i przekątnych
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true; // Wygrana w wierszu

            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true; // Wygrana w kolumnie
        }

        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true; // Wygrana na przekątnej

        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true; // Wygrana na przekątnej

        return false;  // Brak wygranej
    }

    // Sprawdzenie, czy plansza jest pełna (remis)
    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ')
                    return false; // Jest wolne pole
            }
        }
        return true;  // Plansza jest pełna
    }

    // Zmiana gracza
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Zwraca aktualnego gracza
    char getCurrentPlayer() {
        return currentPlayer;
    }
};