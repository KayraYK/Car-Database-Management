#include "headerA3.h" 
#include <string.h> 

// Function to search for a car model in a linked list and return its position
int lookForCarModelType(struct car *headLL, char key[100]) {
    // If the head of the linked list is NULL, there are no cars to search, return -1
    if (headLL == NULL)
        return -1;

    int position = 0; // Initialize position counter
    struct car *currentCar = headLL; // Start with the head of the linked list

    // Loop through each car in the linked list
    while (currentCar != NULL) {
        position++; // Increment position for each car
        
        // If the current car's model matches the key, return the current position
        if (strcmp(currentCar->model, key) == 0) {
            return position; 
        }
        currentCar = currentCar->nextCar; // Move to the next car in the list
    }

    // If the model was not found, return -1
    return -1; 
}
