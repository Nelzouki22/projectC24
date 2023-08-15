#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    int isReserved;
} Room;

Room rooms[MAX_ROOMS];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].guestName, "");
        rooms[i].isReserved = 0;
    }
}

void displayRooms() {
    printf("Room Number\tGuest Name\tReservation\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d\t\t%s\t\t%s\n", rooms[i].roomNumber, rooms[i].guestName,
               rooms[i].isReserved ? "Reserved" : "Available");
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

int main() {
    initializeRooms();

    int choice;
    do {
        printf("\nHotel Accommodation System\n");
        printf("1. Display Rooms\n");
        printf("2. Reserve Room\n");
        printf("3. Exit\n");
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
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
