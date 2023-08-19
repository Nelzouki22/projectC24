#include <stdio.h>
#include <conio.h>
#include <windows.h> // for Sleep()

// Function to display the game screen
void draw(int dinoPos, int obstaclePos) {
    system("cls"); // Clear the screen

    // Print the ground
    for (int i = 0; i < 20; i++) {
        printf("_");
    }

    printf("\n");

    // Print the obstacle
    for (int i = 0; i < obstaclePos; i++) {
        printf(" ");
    }
    printf("@"); // The obstacle

    printf("\n");

    // Print the dino
    for (int i = 0; i < dinoPos; i++) {
        printf(" ");
    }
    printf("O"); // The dinosaur

    printf("\n");
}

int main() {
    int dinoPos = 0;
    int obstaclePos = 50;
    int jump = 0;
    int score = 0;

    printf("Dino Game (Press Space to Jump, Q to Quit)\n");

    while (1) {
        if (_kbhit()) { // Check if a key is pressed
            char key = _getch();
            if (key == ' ') { // Spacebar to jump
                jump = 1;
            } else if (key == 'q' || key == 'Q') { // Quit the game
                break;
            }
        }

        if (jump == 1) {
            dinoPos++;
            if (dinoPos == 10) {
                jump = 0;
            }
        } else {
            dinoPos--;
            if (dinoPos == 0) {
                jump = 0;
            }
        }

        obstaclePos--;

        if (obstaclePos == 0) {
            obstaclePos = 50;
            score++;
        }

        if (dinoPos == obstaclePos && jump == 0) {
            printf("\nGame Over! Your Score: %d\n", score);
            break;
        }

        draw(dinoPos, obstaclePos);
        Sleep(50); // Sleep for a short time to control game speed
    }

    return 0;
}
