#include <stdio.h>

int main() {
    int memory[1000] = {0}; // Assuming memory is an array with 1000 cells
    int accumulator = 0;
    int instructionCounter = 0;

    while (1) {
        int instruction;
        printf("Enter instruction (0 for GD, 1 for PD, 2 for H): ");
        scanf("%d", &instruction);

        switch (instruction) {
            case 0: // GD - Get Data
                printf("Enter data value: ");
                scanf("%d", &memory[instructionCounter]);
                instructionCounter++;
                break;

            case 1: // PD - Print Data
                printf("Data at address %d: %d\n", instructionCounter, memory[instructionCounter]);
                instructionCounter++;
                break;

            case 2: // H - Halt
                printf("Program halted.\n");
                return 0;

            default:
                printf("Invalid instruction. Please enter 0 (GD), 1 (PD), or 2 (H).\n");
                break;
        }
    }

    return 0;
}
