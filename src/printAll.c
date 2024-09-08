#include "headerA3.h" 
#include <stdio.h>    

// Function to print all cars in the linked list
void printAll(struct car *headLL) {
    // Check if the list is empty. If so, print a message and exit the function
    if (headLL == NULL) {
        printf("No cars found\n");
        return;
    }

    struct car *currentCar = headLL; // Start with the first car in the list
    int carCount = 0; // Initialize a counter to keep track of the number of cars

    // Loop through each car in the list until there are no more cars
    while (currentCar != NULL) {
        carCount++; // Increment the car counter
        // Print details of the current car
        printf("Car # %d:\n", carCount);
        printf("        Car id: %d\n", currentCar->carId);
        printf("        Model: %s\n", currentCar->model);
        printf("        Type: %s\n", currentCar->type);
        printf("        Price: CDN $%.2f\n", currentCar->price);
        printf("        Year of Manufacture: %d\n", currentCar->year);
        currentCar = currentCar->nextCar; // Move to the next car in the list
    }

    // After printing all cars, print the total number of cars
    printf("\nCurrently, there are %d cars.\n", carCount);
}
