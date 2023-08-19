#include <stdio.h>

// Function to determine if a given year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month for a given year
int daysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return days[month];
}

// Function to print a calendar for a given month and year
void printCalendar(int month, int year) {
    printf("\n\n");
    printf("       %d/%d\n", month, year);
    printf("Mo Tu We Th Fr Sa Su\n");

    // Calculate the day of the week for the first day of the month
    int day = 1;
    int firstDay = ((day + (month < 3 ? year - 1 : year) + (month < 3 ? year - 1 : year) / 4 -
                     (month < 3 ? year - 1 : year) / 100 + (month < 3 ? year - 1 : year) / 400 +
                     (13 * (month < 3 ? month + 12 : month) + 8) / 5) +
                    6) %
                   7;

    // Print leading spaces for the first week
    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }

    // Print the days of the month
    for (int i = 1; i <= daysInMonth(month, year); i++) {
        printf("%2d ", i);

        // If it's the last day of the week, start a new line
        if ((i + firstDay) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main() {
    int month, year;

    printf("Enter month and year (MM YYYY): ");
    scanf("%d %d", &month, &year);

    printCalendar(month, year);

    return 0;
}
