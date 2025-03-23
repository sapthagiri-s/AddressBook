#include "Headers.h"


// Function to edit a contact
void editContact(AddressBook *addressBook)
{
    // Display header for editing a contact
    printf("\n+------------------------------------+\n");
    printf("|        Edit a contact              |\n");
    printf("+------------------------------------+\n\n");

    // Search for the contact to edit
    int index = searchContact(addressBook);

    // If no contact is found, return
    if (index == -1)
    {
        return;
    }

    char name[50];
    char phone[15];
    char email[50];

    char flag = 1;

    // Prompt user for the field to edit
    printf("Enter the option to edit\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");

    int choice;

    // Read the user's choice
    scanf(" %d", &choice);

    // Handle the user's choice
    switch (choice)
    {
    case 1:
    {
        // Validate and update the name
        flag = 1;
        do
        {
            printf("Enter name: ");
            scanf("%s", name);
            flag = name_validate(name, addressBook);

        } while (flag);

        strcpy(addressBook->contacts[index].name, name);
        break;
    }
    case 2:
    {
        // Validate and update the phone number
        flag = 1;
        do
        {
            printf("Enter phone: ");
            scanf("%s", phone);
            flag = phone_validate(phone, addressBook);

        } while (flag);

        strcpy(addressBook->contacts[index].phone, phone);
        break;
    }
    case 3:
    {
        // Validate and update the email
        flag = 1;
        do
        {
            printf("Enter email: ");
            scanf("%s", email);
            flag = email_validate(email, addressBook);

        } while (flag);

        strcpy(addressBook->contacts[index].email, email);
        break;
    }
    default:
        // Handle invalid choice
        break;
    }

    // Display the updated contact if a valid choice was made
    if (choice >= 1 && choice <= 3)
    {
        printf("\n\n+---------------------- --------Contacts----------------------------------+\n");
        printf("|         Name          |       Phone      |              E-mail          |\n");
        printf("+-------------------------------------------------------------------------+\n");

        printf("|     %-15s   |     %-12s |     %-25s|\n", addressBook->contacts[index].name, addressBook->contacts[index].phone, addressBook->contacts[index].email);

        printf("+------------------------------------------------------------------------+\n\n");

        // Display success message
        printf("\n+------------------------------------+\n");
        printf("|    Contact edited successfully     |");
        printf("\n+------------------------------------+\n\n");
    }
    else
    {
        // Display invalid choice message
        printf("\n+------------------------------------+\n");
        printf("|            invalid choice          |");
        printf("\n+------------------------------------+\n\n");
    }
}
