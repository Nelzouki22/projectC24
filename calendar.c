#include <stdio.h>

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return daysInMonth[month - 1];
}

// Function to print the calendar
void printCalendar(int year, int month) {
    printf("   Calendar - %d/%d\n", month, year);
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");

    int dayOfWeek = 0; // 0 corresponds to Sunday

    // Print leading spaces
    for (int i = 0; i < (dayOfWeek + 7 - getDaysInMonth(year, month) % 7) % 7; i++)
        printf("    ");

    // Print days
    for (int day = 1; day <= getDaysInMonth(year, month); day++) {
        printf("%4d", day);
        dayOfWeek = (dayOfWeek + 1) % 7;
        if (dayOfWeek == 0)
            printf("\n");
    }
    printf("\n");
}

int main() {
    int year, month;

    printf("Enter year: ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month input!\n");
        return 1;
    }

    printCalendar(year, month);

    return 0;
}
