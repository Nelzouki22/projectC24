#include <stdio.h>

// Function to print the tic-tac-toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if a player has won
int checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int currentPlayer = 1;
    int moves = 0;
    int row, col;

    printf("Tic-Tac-Toe Game\n");
    printBoard(board);

    while (moves < 9) {
        printf("Player %d's turn.\n", currentPlayer);
        printf("Enter row and column (0-2): ");
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
        printBoard(board);

        if (checkWin(board, board[row][col])) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        moves++;
    }

    if (moves == 9)
        printf("It's a draw!\n");

    return 0;
}
