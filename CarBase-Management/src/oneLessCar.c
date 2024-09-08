#include "headerA3.h" 
#include <stdio.h>    

// Function to remove a specific car from the linked list
void oneLessCar(struct car **headLL, int whichOne) {
    // If the list is empty, there's nothing to remove, so return immediately
    if (*headLL == NULL) {
        return; 
    }

    // If the first car is to be removed
    if (whichOne == 1) {
        struct car *temp = *headLL; // Temporary pointer to the first car
        *headLL = (*headLL)->nextCar; // Move the head pointer to the second car
        free(temp); // Free the memory of the first car
        return;
    }

    // Counter to track the position in the list
    int count = 1;
    struct car *currentCar = *headLL; // Pointer to traverse the list
    struct car *prevCar = NULL; // Pointer to keep track of the previous car

    // Traverse the list until the desired position or end of list is reached
    while (currentCar != NULL && count < whichOne) {
        prevCar = currentCar; // Update the previous car pointer
        currentCar = currentCar->nextCar; // Move to the next car
        count++; // Increment the position counter
    }

    // If the desired position is beyond the end of the list
    if (currentCar == NULL) {
        printf("Invalid position. Please enter a position within the range.\n");
        return;
    }
    
    // Remove the car at the desired position
    prevCar->nextCar = currentCar->nextCar; // Link the previous car to the next car
    free(currentCar); // Free the memory of the car being removed
}
