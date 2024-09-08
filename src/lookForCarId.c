#include "headerA3.h" 

// Function to search for a car by its ID in the linked list
int lookForCarId(struct car *headLL, int key) {
    if (headLL == NULL) // Check if the list is empty
        return -1; // Return -1 to indicate the car ID was not found

    int position = 0; // Initialize position counter
    struct car *currentCar = headLL; // Start with the head of the list

    // Loop through each car in the list
    while (currentCar != NULL) {
        position++; // Increment position for each car
        if (currentCar->carId == key) // Check if the current car's ID matches the key
            return position; // Return the position if a match is found
        currentCar = currentCar->nextCar; // Move to the next car in the list
    }

    return -1; // Return -1 if the car ID is not found in the list
}
