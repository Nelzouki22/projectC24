#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define WIDTH 20
#define HEIGHT 10

int x, y; // Pac-Man's coordinates
char map[HEIGHT][WIDTH];

void drawMap() {
    system("cls"); // Clear the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == y && j == x) {
                printf("P"); // Draw Pac-Man
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

void movePacman(char direction) {
    switch (direction) {
        case 'w':
            if (y > 0 && map[y - 1][x] != '#') {
                y--;
            }
            break;
        case 's':
            if (y < HEIGHT - 1 && map[y + 1][x] != '#') {
                y++;
            }
            break;
        case 'a':
            if (x > 0 && map[y][x - 1] != '#') {
                x--;
            }
            break;
        case 'd':
            if (x < WIDTH - 1 && map[y][x + 1] != '#') {
                x++;
            }
            break;
    }
}

int main() {
    x = 1;
    y = 1;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = ' ';
        }
    }

    // Create walls
    for (int i = 0; i < HEIGHT; i++) {
        map[i][0] = '#';
        map[i][WIDTH - 1] = '#';
    }
    for (int j = 0; j < WIDTH; j++) {
        map[0][j] = '#';
        map[HEIGHT - 1][j] = '#';
    }

    // Main game loop
    char input;
    while (1) {
        drawMap();
        input = _getch(); // Get keyboard input
        movePacman(input);
    }

    return 0;
}
