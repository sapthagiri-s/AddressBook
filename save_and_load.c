#include "contact.h"

int Save(AddressBook *addressBook)
{
    FILE *fp;
    int i;
    // Open the file in write binary mode
    if ((fp = fopen("contact.dat", "wb")) == NULL)
    {
        printf("Can't open file\n");
        return 0;
    }
    // Write the contact count to the file
    fprintf(fp, "#%d#\n", addressBook -> contactCount);
    for (i = 0; i < addressBook -> contactCount; i++)
    {
        // Write each contact's details to the file
        fprintf(fp, "%s,%s,%s\n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
    }
    // Close the file
    fclose(fp);
    return 1;
}

void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
    FILE *fp;
    // Open the file in read binary mode
    if ((fp = fopen("contact.dat", "rb")) == NULL)
    {
        printf("Can't open file\n");
        return;
    }
    // Read the contact count from the file
    fscanf(fp, "#%d#\n", &addressBook -> contactCount);
    for (int i = 0; i < addressBook -> contactCount; i++)
    {
        // Read each contact's details from the file
        fscanf(fp, "%[^,],%[^,],%s\n", addressBook -> contacts[i].name, addressBook -> contacts[i].phone, addressBook -> contacts[i].email);
    }
    // Close the file
    fclose(fp);
}

// Function to list all contacts in the address book
void listContacts(AddressBook *addressBook)
{
    // Check if there are no contacts in the address book
    if (addressBook->contactCount == 0)
    {
        printf("No contacts found\n");
        return;
    }

    // Print the header for the contacts list
    printf("\n\n+----------------------------------Contacts--------------------------------------+\n");
    printf("| S.No |         Name          |       Phone      |              E-mail          |\n");
    printf("+--------------------------------------------------------------------------------+\n");

    // Iterate through the contacts and print each one
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("|  %02d  |     %-15s   |     %-12s |     %-25s|\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }

    // Print the footer for the contacts list
    printf("+--------------------------------------------------------------------------------+\n\n\n");
}