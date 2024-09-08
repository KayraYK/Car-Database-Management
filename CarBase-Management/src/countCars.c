#include "headerA3.h" 

// Function to count the number of cars in the linked list
int countCars(struct car *headLL) {
    int count = 0; // Initialize a counter to 0
    struct car *currentCar = headLL; // Start with the head of the list

    // Loop through each car in the list
    while (currentCar != NULL) {
        count++; // Increment the counter for each car
        currentCar = currentCar->nextCar; // Move to the next car in the list
    }

    return count; // Return the total count of cars
}
