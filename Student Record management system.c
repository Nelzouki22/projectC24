#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student information
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Global array to store student records
struct Student students[MAX_STUDENTS];
int totalStudents = 0;

// Function to add a new student record
void addStudent() {
    if (totalStudents < MAX_STUDENTS) {
        struct Student newStudent;
        
        printf("Enter Roll Number: ");
        scanf("%d", &newStudent.rollNumber);
        
        printf("Enter Name: ");
        scanf("%s", newStudent.name);
        
        printf("Enter Marks: ");
        scanf("%f", &newStudent.marks);
        
        students[totalStudents] = newStudent;
        totalStudents++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum limit reached. Cannot add more students.\n");
    }
}

// Function to display all student records
void displayStudents() {
    printf("Roll Number\tName\tMarks\n");
    printf("--------------------------------\n");
    for (int i = 0; i < totalStudents; i++) {
        printf("%d\t\t%s\t%.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
