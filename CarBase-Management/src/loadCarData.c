#include "headerA3.h" 
#include <stdio.h>    
#include <stdlib.h>   
#include <string.h>   

// Function to load car data from a file into the linked list
void loadCarData(struct car **headLL, char fileName[MAX_LENGTH]) {
    FILE *file = fopen(fileName, "r"); // Open the file for reading
    if (file == NULL) { // Check if the file was successfully opened
        printf("Unable to open file %s\n", fileName); // Print an error message if the file cannot be opened
        return; // Exit the function
    }

    // Variables to temporarily store car data read from the file
    char model[MAX_LENGTH];
    char type[MAX_LENGTH];
    int year;
    double price;
    int carId;

    // Read car data from the file until there is no more data to read
    while (fscanf(file, "%d,%[^,],%[^,],%d,%lf\n", &carId, model, type, &year, &price) == 5) {
        struct car *newCar = (struct car *)malloc(sizeof(struct car)); // Allocate memory for a new car structure
        if (newCar == NULL) { // Check if memory allocation was successful
            printf("Memory allocation failed!\n"); // Print an error message if allocation failed
            fclose(file); // Close the file
            return; // Exit the function
        }

        // Assign the read data to the new car structure
        newCar->carId = carId;
        strcpy(newCar->model, model); // Copy the model string
        strcpy(newCar->type, type);   // Copy the type string
        newCar->year = year;          // Assign the year
        newCar->price = price;        // Assign the price
        newCar->nextCar = NULL;       // Set the next pointer to NULL

        // Insert the new car into the linked list
        if (*headLL == NULL) { // If the list is empty
            *headLL = newCar; // Set the new car as the head of the list
        } else { // If the list is not empty
            struct car *lastCar = *headLL; // Start at the head of the list
            while (lastCar->nextCar != NULL) { // Find the last car in the list
                lastCar = lastCar->nextCar; // Move to the next car
            }
            lastCar->nextCar = newCar; // Set the new car as the next of the last car
        }
    }

    fclose(file); // Close the file after reading all the data
}
