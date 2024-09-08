#include "headerA3.h" 
#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>   

// Function to add a new car to the linked list
void addNewCar(struct car **headLL) {
    // Dynamically allocate memory for a new car structure
    struct car *newCar = (struct car *)malloc(sizeof(struct car));
    // Check if memory allocation was successful
    if (newCar == NULL) {
        printf("Memory allocation failed!\n"); // Print error message if allocation failed
        return; // Exit the function
    }

    // Temporary buffer to hold user input
    char tempHolder[MAX_LENGTH];

    // Prompt user and read the car model
    printf("Enter the car model: ");
    fgets(tempHolder, MAX_LENGTH, stdin); // Read input with potential spaces
    sscanf(tempHolder, "%[^\n]", newCar->model); // Parse and store the model

    // Repeat the process for car type, year, and price
    printf("Enter the car type: ");
    fgets(tempHolder, MAX_LENGTH, stdin);
    sscanf(tempHolder, "%[^\n]", newCar->type);

    printf("Enter its year of manufacture: ");
    fgets(tempHolder, MAX_LENGTH, stdin);
    sscanf(tempHolder, "%d", &newCar->year);

    printf("Enter its price: CDN $ ");
    fgets(tempHolder, MAX_LENGTH, stdin);
    sscanf(tempHolder, "%lf", &newCar->price);

    // Calculate a unique ID for the car based on the ASCII sum of the model and length of the type
    int modelAsciiSum = 0;
    for (int i = 0; i < strlen(newCar->model); i++) {
        modelAsciiSum += (int)newCar->model[i]; // Sum ASCII values of each character
    }
    newCar->carId = modelAsciiSum + strlen(newCar->type); // Combine with type length for ID

    // Ensure the new car's ID is unique within the linked list
    struct car *temp = *headLL;
    while (temp != NULL) {
        if (temp->carId == newCar->carId) { // If ID is not unique
            newCar->carId += rand() % 999 + 1; // Add a random number to make it unique
            temp = *headLL; // Restart the search
            continue; // Skip to the next iteration
        }
        temp = temp->nextCar; // Move to the next car in the list
    }

    // Insert the new car into the linked list
    newCar->nextCar = NULL; // Set the next pointer to NULL for the new last car
    if (*headLL == NULL) { // If the list is empty
        *headLL = newCar; // Set the new car as the head of the list
    } else { // If the list is not empty
        struct car *lastCar = *headLL; // Start at the head of the list
        while (lastCar->nextCar != NULL) { // Find the last car in the list
            lastCar = lastCar->nextCar; // Move to the next car
        }
        lastCar->nextCar = newCar; // Set the new car as the next of the last car
    }

    // Inform the user of the assigned car ID
    printf("Your computer-generated carId is %d\n", newCar->carId);
}
