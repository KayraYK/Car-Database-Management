#include "headerA3.h" 
#include <stdio.h>    

// Function to print information about a car at a specific position in the list
void printOne (struct car * headLL, int whichOne){
    struct car *currentCar = headLL; // Pointer to the current car in the list
    int count = 0; // Counter to track the current position in the list

    // Loop through the list until the end is reached or the desired position is found
    while (currentCar != NULL) {
        count++; // Increment the position counter
        if (count == whichOne) {
            // If the current position matches the desired position, print the car's details
            printf("Car ID: %d\n", currentCar->carId);
            printf("Model: %s\n", currentCar->model);
            printf("Type: %s\n", currentCar->type);
            printf("Price: CDN $%.2f\n", currentCar->price);
            printf("Year of Manufacture: %d\n", currentCar->year);
            return; // Exit the function after printing the details
        }
        currentCar = currentCar->nextCar; // Move to the next car in the list
    }

    // If the end of the list is reached without finding the desired position, print a message
    printf("No car found at the specified position.\n");
}
