#include "contact.h"

int main()
{
    // all function calls should be inside the main

    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    while (1)
    {
        int choice;
        // Display the menu
        printf("\n+============= Address Book Menu===========+\n");
        printf("|  Option  |          Description          |\n");
        printf("+===========================================\n");
        printf("|     1    |  Add Contact                  |\n");
        printf("|     2    |  Display All Contacts         |\n");
        printf("|     3    |  Search Contact               |\n");
        printf("|     4    |  Edit Contact                 |\n");
        printf("|     5    |  Delete Contact               |\n");
        printf("|     6    |  Exit                         |\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user choice

        switch (choice)
        {
        case 1:
            createContact(&addressBook); // Add a new contact
            break;
        case 2:
            listContacts(&addressBook); // Display all contacts
            break;
        case 3:
            searchContact(&addressBook); // Search for a contact
            break;
        case 4:
            editContact(&addressBook); // Edit an existing contact
            break;
        case 5:
            deleteContact(&addressBook); // Delete a contact
            break;
        case 6:
            // Exit the program
            printf("\n+------------------------------------+\n");
            printf("|      Exiting the program...        |\n");
            printf("+------------------------------------+\n\n");
            sleep(1); // Pause for a moment before exiting
            return 0;
        default:
            printf("Invalid choice\n"); // Handle invalid input
            break;
        }
        Save(&addressBook); // Save the address book after each operation
    }

    return 0;
}
