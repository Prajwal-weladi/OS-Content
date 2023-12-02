#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define hypothetical registers
int R0 = 0; // Register 0
int R1 = 0; // Register 1

// Define memory as an array of integers (simplified for illustration)
int memory[1024] = {0};

// Function to execute LR (Load Register) instruction
void loadRegister(int* reg, int memAddress) {
    *reg = memory[memAddress];
    printf("Loaded %d into R%d\n", *reg, reg - &R0);
}

// Function to execute SR (Store Register) instruction
void storeRegister(int* reg, int memAddress) {
    memory[memAddress] = *reg;
    printf("Stored %d from R%d to memory address %d\n", *reg, reg - &R0, memAddress);
}

// Function to execute CR (Compare Register) instruction
bool compareRegisters(int* reg1, int* reg2) {
    return *reg1 == *reg2;
}

int main() {
    char instruction[3];
    bool running = true;

    printf("Welcome to the Simple Processor Emulator!\n");

    while (running) {
        printf("Enter instruction (LR, SR, CR, BT, or QUIT): ");
        scanf("%s", instruction);

        if (strcmp(instruction, "LR") == 0) {
            int regNum, memAddress;
            printf("Enter register number (0 or 1): ");
            scanf("%d", &regNum);
            printf("Enter memory address: ");
            scanf("%d", &memAddress);

            if (regNum == 0) {
                loadRegister(&R0, memAddress);
            } else if (regNum == 1) {
                loadRegister(&R1, memAddress);
            } else {
                printf("Invalid register number.\n");
            }
        } else if (strcmp(instruction, "SR") == 0) {
            int regNum, memAddress;
            printf("Enter register number (0 or 1): ");
            scanf("%d", &regNum);
            printf("Enter memory address: ");
            scanf("%d", &memAddress);

            if (regNum == 0) {
                storeRegister(&R0, memAddress);
            } else if (regNum == 1) {
                storeRegister(&R1, memAddress);
            } else {
                printf("Invalid register number.\n");
            }
        } else if (strcmp(instruction, "CR") == 0) {
            if (compareRegisters(&R0, &R1)) {
                printf("Registers R0 and R1 are equal.\n");
            } else {
                printf("Registers R0 and R1 are not equal.\n");
            }
        } else if (strcmp(instruction, "BT") == 0) {
            // Simulate a branch based on a condition
            if (compareRegisters(&R0, &R1)) {
                printf("Branching condition is true. Executing branch.\n");
                // Add code here to perform a branch operation
            } else {
                printf("Branching condition is false. Not branching.\n");
            }
        } else if (strcmp(instruction, "QUIT") == 0) {
            running = false;
            printf("Exiting the emulator.\n");
        } else {
            printf("Invalid instruction. Please enter LR, SR, CR, BT, or QUIT.\n");
        }
    }

    return 0;
}

