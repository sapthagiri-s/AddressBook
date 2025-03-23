#include "contact.h"

// Function to delete a contact
void deleteContact(AddressBook *addressBook)
{
    // Display header for deleting a contact
    printf("\n+------------------------------------+\n");
    printf("|        Delete a contact            |\n");
    printf("+------------------------------------+\n\n");

    // Search for the contact to delete
    int index = searchContact(addressBook);

    // If no contact is found, return
    if (index == -1)
    {
        return;
    }

    // Prompt user for confirmation
    printf("Are you sure you want to delete the contact? (y/n): ");

    char choice;

    // Read the user's choice
    scanf(" %c", &choice);

    // If user does not confirm, return
    if (!(choice == 'y' || choice == 'Y'))
    {
        printf("\n+------------------------------------+\n");
        printf("|        Contact not deleted         |");
        printf("\n+------------------------------------+\n");
        return;
    }

    // Shift contacts to remove the deleted contact
    for (int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    // Decrement the contact count
    addressBook->contactCount--;

    // Display success message
    printf("\n+------------------------------------+\n");
    printf("|    Contact deleted successfully    |");
    printf("\n+------------------------------------+\n\n");
}
