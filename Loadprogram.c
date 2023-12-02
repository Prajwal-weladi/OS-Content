#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants representing memory blocks
#define B0 0
#define B1 1

// Function to load a program card into memory block
void loadProgramCard(int block, char* program) {
    // Simulate loading the program into the specified memory block
    printf("Loading program into Block %d...\n", block);
    // You can implement the actual memory writing logic here.

    printf("Program loaded successfully into Block %d!\n", block);

    // Open output.txt for writing
    FILE *outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        perror("Error opening output.txt");
        return;
    }

    // Write the program content to output.txt
    fprintf(outputFile, "Program loaded into Block %d:\n", block);
    fprintf(outputFile, "%s\n", program);

    // Close the output file
    fclose(outputFile);

    printf("Program content saved to output.txt\n");
}

int main() {
    char program[256];
    int block;
    bool validBlock = false;

    // Get the program card from the user
    printf("Enter the program card: ");
    scanf("%s", program);

    // Get the memory block from the user
    while (!validBlock) {
        printf("Enter the memory block (0 for B0, 1 for B1): ");
        scanf("%d", &block);

        if (block == B0 || block == B1) {
            validBlock = true;
        } else {
            printf("Invalid memory block. Please enter 0 or 1.\n");
        }
    }

    // Load the program card into the specified memory block and save it to output.txt
    loadProgramCard(block, program);

    return 0;
}
