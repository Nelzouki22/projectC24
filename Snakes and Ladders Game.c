#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
    return rand() % 6 + 1;
}

// Function to play the game
void playGame() {
    int player1 = 0, player2 = 0; // Player positions
    int currentPlayer = 1; // 1 for player 1, 2 for player 2
    int dice;
    
    while (player1 < 100 && player2 < 100) {
        printf("Player %d, press Enter to roll the dice...\n", currentPlayer);
        getchar();
        
        dice = rollDice();
        printf("You rolled a %d!\n", dice);
        
        if (currentPlayer == 1) {
            player1 += dice;
        } else {
            player2 += dice;
        }
        
        // Check for snakes and ladders
        if (player1 == 4) player1 = 14;
        if (player1 == 9) player1 = 31;
        if (player1 == 17) player1 = 7;
        if (player1 == 20) player1 = 38;
        if (player1 == 28) player1 = 84;
        if (player1 == 40) player1 = 59;
        if (player1 == 51) player1 = 67;
        if (player1 == 54) player1 = 34;
        if (player1 == 62) player1 = 19;
        if (player1 == 64) player1 = 60;
        if (player1 == 71) player1 = 91;
        if (player1 == 87) player1 = 24;
        if (player1 == 93) player1 = 73;
        if (player1 == 95) player1 = 75;
        if (player1 == 99) player1 = 78;
        
        if (player2 == 4) player2 = 14;
        if (player2 == 9) player2 = 31;
        if (player2 == 17) player2 = 7;
        if (player2 == 20) player2 = 38;
        if (player2 == 28) player2 = 84;
        if (player2 == 40) player2 = 59;
        if (player2 == 51) player2 = 67;
        if (player2 == 54) player2 = 34;
        if (player2 == 62) player2 = 19;
        if (player2 == 64) player2 = 60;
        if (player2 == 71) player2 = 91;
        if (player2 == 87) player2 = 24;
        if (player2 == 93) player2 = 73;
        if (player2 == 95) player2 = 75;
        if (player2 == 99) player2 = 78;
        
        printf("Player 1 is at position %d, Player 2 is at position %d\n", player1, player2);
        
        if (player1 >= 100) {
            printf("Player 1 wins!\n");
            break;
        }
        if (player2 >= 100) {
            printf("Player 2 wins!\n");
            break;
        }
        
        // Switch players
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    printf("Welcome to Snakes and Ladders!\n");
    printf("Rules:\n");
    printf("- Each player rolls a dice in turns.\n");
    printf("- If you land on a snake's head, you move down.\n");
    printf("- If you land on a ladder's bottom, you move up.\n");
    printf("- The first player to reach or exceed 100 wins.\n");
    
    playGame();
    
    return 0;
}
