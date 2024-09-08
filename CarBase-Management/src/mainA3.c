#include <stdio.h>
#include <stdlib.h>
#include "headerA3.h"

int main() {
    struct car *list = NULL; // Initialize the head of the linked list to NULL, indicating an empty list.

    char file[MAX_LENGTH]; // Declare a string array to hold the file name.
    // Use snprintf to safely create a formatted string, preventing tempHolder overflow.
    snprintf(file, MAX_LENGTH, "%s", "inputFile.txt");
    file[MAX_LENGTH - 1] = '\0'; // Ensure the last character is a null terminator to properly end the string.

    int option; // Variable to store the user's menu choice.
    char tempHolder[100]; // tempHolder to store user input temporarily.

    // Main loop to display the menu and process user input.
    do {
        // Display the menu options to the user
        printf("\nMenu:\n");
        printf("1. Add new car data\n");
        printf("2. Load car data from file\n");
        printf("3. Print all car data\n");
        printf("4. Print specific car data\n");
        printf("5. Search car data by ID\n");
        printf("6. Search car data by model and type\n");
        printf("7. Count total cars\n");
        printf("8. Sort cars by ID\n");
        printf("9. Remove specific car data\n");
        printf("10. Remove all car data\n");
        printf("11. Exit\n");

        // Prompt the user to choose an option from the menu.
        printf("\nChoose an option:\n");
        fgets(tempHolder, sizeof(tempHolder), stdin); // Read a line of input into the tempHolder.
        // Parse the input as an integer and validate it.
        if (sscanf(tempHolder, "%d", &option) != 1) {
            printf("Invalid input! Please enter a number.\n");
            continue; // If input is invalid, restart the loop.
        }

        // Process the user's choice using a series of if-else statements
        if (option == 1) {

            addNewCar(&list);

        } else if (option == 2) {

            loadCarData(&list, file);
            printf("Data loaded successfully.\n");
        
        } else if (option == 3) {

            printAll(list);
        
        } else if (option == 4) {

            int pos;
            printf("Enter car position to print: ");
            fgets(tempHolder, sizeof(tempHolder), stdin);
            sscanf(tempHolder, "%d", &pos);
            printOne(list, pos);
        
        } else if (option == 5) {

            int ID;
            printf("Enter car ID: ");
            fgets(tempHolder, sizeof(tempHolder), stdin);
            sscanf(tempHolder, "%d", &ID);
            int pos = lookForCarId(list, ID);
            if (pos != -1) {
                printf("Car found at position %d\n", pos);
            } else {
                printf("Car not found\n");
            }
        
        } else if (option == 6) {

            char modelType[100];
            printf("Enter model and type: ");
            fgets(tempHolder, sizeof(tempHolder), stdin);
            sscanf(tempHolder, "%s", modelType);
            int pos = lookForCarModelType(list, modelType);
            if (pos != -1) {
                printf("Car found at position %d\n", pos);
            } else {
                printf("Car not found\n");
            }
        
        } else if (option == 7) {

            printf("Total cars: %d\n", countCars(list));
        
        } else if (option == 8) {

            sortCarId(&list);
            printf("Cars sorted by ID\n");
        
        } else if (option == 9) {

            int posToRemove;
            printf("Enter position to remove (1 to %d): ", countCars(list));
            fgets(tempHolder, sizeof(tempHolder), stdin);
            sscanf(tempHolder, "%d", &posToRemove);
            oneLessCar(&list, posToRemove);
            printf("Car removed from position %d, %d cars remaining.\n", posToRemove, countCars(list));
        
        } else if (option == 10) {

            noMoreCars(&list);
        
        } else if (option == 11) {

            printf("Exiting...\n");
            exit(0);
        
        } else {

            printf("Invalid option! Please enter a valid choice.\n"); 
        
        }

    } while (option != 11);// Continue the loop until the user selects the option to exit.

    return 0;
}
