#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Global array to store employee records
struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

// Function to add an employee
void addEmployee() {
    if (numEmployees >= MAX_EMPLOYEES) {
        printf("Maximum number of employees reached.\n");
        return;
    }

    struct Employee newEmployee;

    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);
    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);

    employees[numEmployees++] = newEmployee;

    printf("Employee added successfully.\n");
}

// Function to display all employees
void displayEmployees() {
    if (numEmployees == 0) {
        printf("No employees to display.\n");
        return;
    }

    printf("Employee ID\tName\t\tSalary\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < numEmployees; i++) {
        printf("%d\t\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

// Function to search for an employee by ID
void searchEmployee() {
    if (numEmployees == 0) {
        printf("No employees to search.\n");
        return;
    }

    int searchId;
    printf("Enter employee ID to search for: ");
    scanf("%d", &searchId);

    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == searchId) {
            printf("Employee found:\n");
            printf("Employee ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }

    printf("Employee with ID %d not found.\n", searchId);
}

int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
