#include <stdio.h>
#include <stdlib.h>

// Define the price per ticket
#define TICKET_PRICE 10

// Function to display available movies
void displayMovies() {
    printf("\nAvailable Movies:\n");
    printf("1. Movie A\n");
    printf("2. Movie B\n");
    printf("3. Movie C\n");
    printf("4. Movie D\n");
}

int main() {
    int choice, numTickets;
    double totalCost = 0.0;

    printf("Welcome to the Movie Ticket Booking System\n");

    while (1) {
        // Display available movies
        displayMovies();

        printf("\nEnter the movie number (1-4) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\nThank you for using the Movie Ticket Booking System!\n");
            break;
        } else if (choice < 1 || choice > 4) {
            printf("\nInvalid choice. Please select a valid movie.\n");
            continue;
        }

        printf("Enter the number of tickets: ");
        scanf("%d", &numTickets);

        if (numTickets < 1) {
            printf("\nInvalid number of tickets. Please enter at least 1 ticket.\n");
            continue;
        }

        // Calculate the total cost
        totalCost = numTickets * TICKET_PRICE;

        printf("\nMovie selected: Movie %c\n", 'A' + choice - 1);
        printf("Number of tickets: %d\n", numTickets);
        printf("Total cost: $%.2f\n", totalCost);
    }

    return 0;
}
