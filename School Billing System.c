#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    int studentID;
    char studentName[MAX_NAME_LENGTH];
    double tuitionFee;
    double payment;
} Student;

Student students[MAX_STUDENTS];
int totalStudents = 0;

void addStudent(int studentID, const char *studentName, double tuitionFee) {
    if (totalStudents < MAX_STUDENTS) {
        students[totalStudents].studentID = studentID;
        strcpy(students[totalStudents].studentName, studentName);
        students[totalStudents].tuitionFee = tuitionFee;
        students[totalStudents].payment = 0;
        totalStudents++;
        printf("Student added successfully.\n");
    } else {
        printf("Maximum student limit reached.\n");
    }
}

void makePayment(int studentID, double amount) {
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].studentID == studentID) {
            students[i].payment += amount;
            printf("Payment of %.2f made for student %s.\n", amount, students[i].studentName);
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
}

void generateBill(int studentID) {
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].studentID == studentID) {
            double balance = students[i].tuitionFee - students[i].payment;
            printf("Student: %s\n", students[i].studentName);
            printf("Tuition Fee: %.2f\n", students[i].tuitionFee);
            printf("Payment Made: %.2f\n", students[i].payment);
            printf("Balance: %.2f\n", balance);
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
}

int main() {
    int choice;
    do {
        printf("\nSchool Billing System\n");
        printf("1. Add Student\n");
        printf("2. Make Payment\n");
        printf("3. Generate Bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int studentID;
                char studentName[MAX_NAME_LENGTH];
                double tuitionFee;
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                printf("Enter student name: ");
                scanf("%s", studentName);
                printf("Enter tuition fee: ");
                scanf("%lf", &tuitionFee);
                addStudent(studentID, studentName, tuitionFee);
                break;
            case 2:
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                double paymentAmount;
                printf("Enter payment amount: ");
                scanf("%lf", &paymentAmount);
                makePayment(studentID, paymentAmount);
                break;
            case 3:
                printf("Enter student ID: ");
                scanf("%d", &studentID);
                generateBill(studentID);
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
