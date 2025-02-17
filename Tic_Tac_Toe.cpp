#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char> > board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() {
       cout << "\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
           cout << "\n";
            if (i < 2) cout << "---------\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool Winnner() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;
        return false;
    }

    bool checkDraw() {
        for (const auto &row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? '0' : 'X';
    }

    void playGame() {
        int row, col;
        while (true) {
            displayBoard();
           cout << "Player " << currentPlayer << ", enter your move (row and column): ";
           cin >> row >> col;
            
            if (!makeMove(row - 1, col - 1)) continue;
            
            if (Winnner()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            
            if (checkDraw()) {
                displayBoard();
               cout << "It's a draw!\n";
                break;
            }
            
            switchPlayer();
        }
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    return 0;
}
