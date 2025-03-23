#include "contact.h"

// Function to create a new contact
void createContact(AddressBook *addressBook)
{
    char name[50];
    char phone[15];
    char email[50];

    // Display header for creating a new contact
    printf("\n+----------------------------------+\n");
    printf("|        Create a new contact      |\n");
    printf("+----------------------------------+\n\n");

    char flag = 1;

    // Validate and input the name
    do
    {
        printf("Enter name: ");
        scanf("%s", name);
        flag = name_validate(name, addressBook);
    } while (flag);

    printf("✅ Name is valid\n\n");

    // Validate and input the phone number
    flag = 1;
    do
    {
        printf("Enter phone: ");
        scanf("%s", phone);
        flag = phone_validate(phone, addressBook);
    } while (flag);

    printf("✅ Phone is valid\n\n");

    // Validate and input the email
    flag = 1;
    do
    {
        printf("Enter email: ");
        scanf("%s", email);
        flag = email_validate(email, addressBook);
    } while (flag);

    printf("✅ Email is valid\n");

    // Add the new contact to the address book
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email);

    // Increment the contact count
    addressBook->contactCount++;

    // Display success message
    printf("\n+------------------------------------+\n");
    printf("|    Contact created successfully    |");
    printf("\n+------------------------------------+\n");

    // Pause for a moment
    sleep(1);
}
