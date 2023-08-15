#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int isReserved;
    double roomRate;
} Room;

Room rooms[MAX_ROOMS];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].guestName, "");
        rooms[i].isReserved = 0;
        rooms[i].roomRate = 100.0; // Default room rate
    }
}

void displayRooms() {
    printf("Room Number\tGuest Name\tReservation\tRoom Rate\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d\t\t%s\t\t%s\t\t%.2f\n", rooms[i].roomNumber, rooms[i].guestName,
               rooms[i].isReserved ? "Reserved" : "Available", rooms[i].roomRate);
    }
}

void reserveRoom(int roomNumber, const char *guestName) {
    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    if (rooms[roomNumber - 1].isReserved) {
        printf("Room %d is already reserved.\n", roomNumber);
        return;
    }

    rooms[roomNumber - 1].isReserved = 1;
    strcpy(rooms[roomNumber - 1].guestName, guestName);
    printf("Room %d has been reserved for %s.\n", roomNumber, guestName);
}

void setRoomRate(int roomNumber, double rate) {
    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    rooms[roomNumber - 1].roomRate = rate;
    printf("Room rate for room %d has been set to %.2f.\n", roomNumber, rate);
}

int main() {
    initializeRooms();

    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. Display Rooms\n");
        printf("2. Reserve Room\n");
        printf("3. Set Room Rate\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2:
                int roomNumber;
                char guestName[MAX_NAME_LENGTH];
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                printf("Enter guest name: ");
                scanf("%s", guestName);
                reserveRoom(roomNumber, guestName);
                break;
            case 3:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                double roomRate;
                printf("Enter new room rate: ");
                scanf("%lf", &roomRate);
                setRoomRate(roomNumber, roomRate);
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
