#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20  // Maximum allowed size for sets

// Global Variables
int superSet[MAX_SIZE], superSetSize = 0;  // Universal set and its size
int setA[MAX_SIZE], setASize = 0;          // Set A and its size
int setB[MAX_SIZE], setBSize = 0;          // Set B and its size
int bitStringA[MAX_SIZE], bitStringB[MAX_SIZE];  // Bit strings representing sets A and B


// Function prototypes
void getUniversalSet();
void getSet(int arr[], int *size);
int checkSetInUniversal(int arr[], int size);
void generateBitStrings();
void setUnion();
void setIntersection();
void setDifferenceAminusB();
void setDifferenceBminusA();
void printBitString(int arr[], int size);
void printSetFromBitString(int arr[], int size);



// Input Functions
// Function to input the Universal Set
void getUniversalSet() {
    printf("Enter Universal Set Size (max %d): ", MAX_SIZE);
    scanf("%d", &superSetSize);
    
    // Ensure the size doesn't exceed the maximum allowed size
    if (superSetSize > MAX_SIZE) {
        printf("Error: Size exceeds maximum limit.\n");
        exit(1);  // Exit the program if size is invalid
    }

    // Input elements for the Universal Set
    printf("Enter %d elements for the Universal Set:\n", superSetSize);
    for (int i = 0; i < superSetSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &superSet[i]);
    }
}

// Function to input a specific set (Set A or Set B)
void getSet(int arr[], int *size) {
    printf("Enter %d elements (must be in the Universal Set):\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Function to check if the set elements are part of the Universal Set
int checkSetInUniversal(int arr[], int size) {
    // Iterate through elements of the given set
    for (int i = 0; i < size; i++) {
        int found = 0;
        // Check if each element exists in the Universal Set
        for (int j = 0; j < superSetSize; j++) {
            if (arr[i] == superSet[j]) {
                found = 1;
                break;
            }
        }
        // If element is not found in the Universal Set, return error
        if (!found) {
            printf("Error: Element %d is not in the Universal Set. Please enter the set again.\n", arr[i]);
            return 0;  // Set is invalid
        }
    }
    return 1;  // All elements are valid
}

// Bit String Operations
// Function to generate the bit string representation of Sets A and B
void generateBitStrings() {
    // Initialize bit strings to 0
    for (int i = 0; i < superSetSize; i++) {
        bitStringA[i] = 0;
        bitStringB[i] = 0;
    }

    // Generate bit string for Set A (1 if element is present in Set A)
    for (int i = 0; i < setASize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setA[i] == superSet[j]) {
                bitStringA[j] = 1;
                break;
            }
        }
    }

    // Generate bit string for Set B (1 if element is present in Set B)
    for (int i = 0; i < setBSize; i++) {
        for (int j = 0; j < superSetSize; j++) {
            if (setB[i] == superSet[j]) {
                bitStringB[j] = 1;
                break;
            }
        }
    }

    // Print the bit strings for both sets
    printf("Set A Bit String: ");
    printBitString(bitStringA, superSetSize);
    printf("Set B Bit String: ");
    printBitString(bitStringB, superSetSize);
}

// Function to compute the union of Sets A and B
void setUnion() {
    int bitStringUnion[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        // Union operation: 1 if either bit in A or B is 1
        bitStringUnion[i] = bitStringA[i] | bitStringB[i];
    }
    // Print the union result in bit string form
    printf("Union: ");
    printBitString(bitStringUnion, superSetSize);
    // Print the union result as actual values
    printf("Union Result (Values): ");
    printSetFromBitString(bitStringUnion, superSetSize);
}

// Function to compute the intersection of Sets A and B
void setIntersection() {
    int bitStringIntersection[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        // Intersection operation: 1 if both bits in A and B are 1
        bitStringIntersection[i] = bitStringA[i] & bitStringB[i];
    }
    // Print the intersection result in bit string form
    printf("Intersection: ");
    printBitString(bitStringIntersection, superSetSize);
    // Print the intersection result as actual values
    printf("Intersection Result (Values): ");
    printSetFromBitString(bitStringIntersection, superSetSize);
}

// Function to compute the difference (A - B) of Sets A and B
void setDifferenceAminusB() {
    int bitStringDifferenceAminusB[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        // Difference (A - B) operation: 1 if bit is in A but not in B
        bitStringDifferenceAminusB[i] = bitStringA[i] & (1 - bitStringB[i]);
    }
    // Print the difference (A - B) result in bit string form
    printf("Difference (A - B): ");
    printBitString(bitStringDifferenceAminusB, superSetSize);
    // Print the difference (A - B) result as actual values
    printf("Difference Result (A - B, Values): ");
    printSetFromBitString(bitStringDifferenceAminusB, superSetSize);
}

// Function to compute the difference (B - A) of Sets B and A
void setDifferenceBminusA() {
    int bitStringDifferenceBminusA[MAX_SIZE];
    for (int i = 0; i < superSetSize; i++) {
        // Difference (B - A) operation: 1 if bit is in B but not in A
        bitStringDifferenceBminusA[i] = bitStringB[i] & (1 - bitStringA[i]);
    }
    // Print the difference (B - A) result in bit string form
    printf("Difference (B - A): ");
    printBitString(bitStringDifferenceBminusA, superSetSize);
    // Print the difference (B - A) result as actual values
    printf("Difference Result (B - A, Values): ");
    printSetFromBitString(bitStringDifferenceBminusA, superSetSize);
}

// Output Functions
// Function to print a bit string (e.g., {1, 0, 1, ...})
void printBitString(int arr[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

// Function to print the set represented by a bit string
void printSetFromBitString(int arr[], int size) {
    int first = 1;
    printf("{");
    // Iterate through the bit string and print corresponding elements from the Universal Set
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            if (!first) {
                printf(", ");
            }
            printf("%d", superSet[i]);  // Print the element from the Universal Set
            first = 0;
        }
    }
    printf("}\n");
}

// Main Function
int main() {
    // Get Universal Set from the user
    getUniversalSet();

    // Input and validate Set A
    do {
        printf("Enter Set A Size (max %d): ", superSetSize);
        scanf("%d", &setASize);
        if (setASize > superSetSize) {
            printf("Error: Set A size cannot exceed Universal Set size.\n");
        }
    } while (setASize > superSetSize);

    do {
        getSet(setA, &setASize);  // Get Set A elements from the user
    } while (checkSetInUniversal(setA, setASize) == 0);  // Validate Set A

    // Input and validate Set B
    do {
        printf("Enter Set B Size (max %d): ", superSetSize);
        scanf("%d", &setBSize);
        if (setBSize > superSetSize) {
            printf("Error: Set B size cannot exceed Universal Set size.\n");
        }
    } while (setBSize > superSetSize);

    do {
        getSet(setB, &setBSize);  // Get Set B elements from the user
    } while (checkSetInUniversal(setB, setBSize) == 0);  // Validate Set B

    // Generate bit strings for Sets A and B and perform set operations
    generateBitStrings();
    setUnion();
    setIntersection();
    setDifferenceAminusB();
    setDifferenceBminusA();

    return 0;
}
