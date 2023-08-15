#include <stdio.h>
#include <string.h>

// Structure to represent an element
typedef struct {
    int atomicNumber;
    char symbol[3];
    char name[20];
    double atomicWeight;
} Element;

// Function to initialize an element
Element createElement(int atomicNumber, const char *symbol, const char *name, double atomicWeight) {
    Element element;
    element.atomicNumber = atomicNumber;
    strncpy(element.symbol, symbol, sizeof(element.symbol));
    strncpy(element.name, name, sizeof(element.name));
    element.atomicWeight = atomicWeight;
    return element;
}

// Function to print an element's details
void printElement(const Element *element) {
    printf("Atomic Number: %d\n", element->atomicNumber);
    printf("Symbol: %s\n", element->symbol);
    printf("Name: %s\n", element->name);
    printf("Atomic Weight: %.4f\n", element->atomicWeight);
    printf("\n");
}

int main() {
    // Create an array to store elements
    Element periodicTable[118]; // Assuming there are 118 known elements

    // Populate the periodic table
    periodicTable[0] = createElement(1, "H", "Hydrogen", 1.008);
    periodicTable[1] = createElement(2, "He", "Helium", 4.0026);
    // ... add more elements

    // Print the details of some elements
    printElement(&periodicTable[0]);
    printElement(&periodicTable[1]);
    
    return 0;
}
