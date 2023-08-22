#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

// Function to add a new contact
void addContact(struct Contact *contacts, int *count) {
    if (*count < 100) { // Assuming you want to limit the number of contacts
        struct Contact newContact;
        printf("Enter Name: ");
        scanf("%s", newContact.name);
        printf("Enter Phone: ");
        scanf("%s", newContact.phone);
        printf("Enter Email: ");
        scanf("%s", newContact.email);
        contacts[*count] = newContact;
        (*count)++;
        printf("Contact added successfully!\n");
    } else {
        printf("Contact limit reached!\n");
    }
}

// Function to display all contacts
void displayContacts(struct Contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts found.\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < count; i++) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("-----------------\n");
        }
    }
}

int main() {
    struct Contact contacts[100]; // Assuming a maximum of 100 contacts
    int count = 0;

    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
