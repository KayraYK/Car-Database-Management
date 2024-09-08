#include "headerA3.h" 
#include <stdio.h>    
#include <stdlib.h>   

// Function to remove all cars from the linked list
void noMoreCars(struct car **headLL) {
    char choice; // Variable to store the user's choice

    // Loop indefinitely until the user enters 'y' or 'n'
    while (1) {
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        scanf(" %c", &choice); // Read a single character from the user
        while(getchar() != '\n'); // Clear the input buffer

        // If the user enters 'y' or 'n', exit the loop
        if (choice == 'y' || choice == 'n') {
            break;
        } else {
            // If the user enters an invalid input, prompt again
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }

    // If the user chooses 'y', proceed to remove all cars
    if (choice == 'y') {
        struct car *currentCar = *headLL; // Pointer to the current car in the list

        // Loop through all cars in the list
        while (currentCar != NULL) {
            struct car *temp = currentCar; // Temporary pointer to the current car
            currentCar = currentCar->nextCar; // Move to the next car
            free(temp); // Free the memory allocated for the current car
        }
        *headLL = NULL; // Set the head of the list to NULL indicating it's empty
        printf("All removed. Linked list is now empty.\n"); // Inform the user that all cars have been removed
    }
}
