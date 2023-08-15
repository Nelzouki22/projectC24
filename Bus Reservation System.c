#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 40
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int seatNumber;
} Passenger;

typedef struct {
    int busNumber;
    int availableSeats;
    Passenger passengers[MAX_SEATS];
} Bus;

Bus buses[MAX_BUSES];
int totalBuses = 0;

void initializeBuses() {
    for (int i = 0; i < MAX_BUSES; i++) {
        buses[i].busNumber = i + 1;
        buses[i].availableSeats = MAX_SEATS;
    }
    totalBuses = MAX_BUSES;
}

void displayMenu() {
    printf("1. Reserve a seat\n");
    printf("2. Display available seats\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void reserveSeat(int busIndex) {
    if (busIndex < 0 || busIndex >= totalBuses) {
        printf("Invalid bus number.\n");
        return;
    }

    if (buses[busIndex].availableSeats <= 0) {
        printf("All seats are already reserved for this bus.\n");
        return;
    }

    printf("Enter passenger name: ");
    char name[NAME_LENGTH];
    scanf("%s", name);

    int seatNumber = MAX_SEATS - buses[busIndex].availableSeats + 1;
    Passenger passenger;
    strcpy(passenger.name, name);
    passenger.seatNumber = seatNumber;
    buses[busIndex].passengers[seatNumber - 1] = passenger;
    buses[busIndex].availableSeats--;

    printf("Seat reserved successfully. Passenger %s, Seat Number %d\n", name, seatNumber);
}

void displayAvailableSeats(int busIndex) {
    if (busIndex < 0 || busIndex >= totalBuses) {
        printf("Invalid bus number.\n");
        return;
    }

    printf("Available seats for Bus %d:\n", buses[busIndex].busNumber);
    for (int i = 0; i < MAX_SEATS; i++) {
        if (buses[busIndex].passengers[i].seatNumber == 0) {
            printf("Seat %d\n", i + 1);
        }
    }
}

int main() {
    initializeBuses();

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter bus number: ");
                int busNumber;
                scanf("%d", &busNumber);
                reserveSeat(busNumber - 1);
                break;
            case 2:
                printf("Enter bus number: ");
                scanf("%d", &busNumber);
                displayAvailableSeats(busNumber - 1);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
