#include "headerA3.h" 

// Function to sort a list of cars by their carId in ascending order.
void sortCarId (struct car ** headLL) {
    struct car *temp; // Temporary pointer to help with swapping cars.
    int isSorted = 0; // Flag to check if the list is sorted.
  
    // Loop until the list is sorted.
    while (!isSorted) {
        isSorted = 1; // Assume the list is sorted.
        struct car *currentCar = *headLL; // Start with the first car in the list.
        
        // Traverse the list until the end.
        while (currentCar->nextCar != NULL) {
            // If the current car's ID is greater than the next car's ID, swap them.
            if (currentCar->carId > currentCar->nextCar->carId) {
                temp = currentCar->nextCar; // Point temp to the next car.
                currentCar->nextCar = temp->nextCar; // Skip over temp in the list.
                temp->nextCar = currentCar; // Insert temp before the current car.
                
                // If the swap involves the first car in the list, update the list head.
                if (currentCar == *headLL) {
                    *headLL = temp;
                } else {
                    // Otherwise, find the car before the current one to update its next pointer.
                    struct car *prev = *headLL;
                    while (prev->nextCar != currentCar) {
                        prev = prev->nextCar;
                    }
                    prev->nextCar = temp; // Complete the swap by pointing to temp.
                }
                isSorted = 0; // Set the flag to 0 as a swap was made, indicating the list may not be sorted.
            } else {
                // Move to the next car if no swap is needed.
                currentCar = currentCar->nextCar;
            }
        }
    }
}
