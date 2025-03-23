#include "contact.h"

// Function to validate the name
int name_validate(char name[], AddressBook *addressBook)
{
    // Check if the name is at least 3 characters long
    if (strlen(name) < 3)
    {
        printf("Name should be at least 3 characters\n");
        return 1;
    }

    // Validate that the name contains only alphabetic characters
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z'))
        {
            printf("Invalid name\n");
            return 1;
        }
    }

    // Return 0 if the name is valid
    return 0;
}

// Function to validate the phone number
int phone_validate(char phone[], AddressBook *addressBook)
{
    // Check if the phone number is exactly 10 digits long
    if (strlen(phone) != 10)
    {
        printf("Phone number should be 10 digits\n");
        return 1;
    }

    // Validate that the phone number contains only numeric characters
    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (!(phone[i] >= '0' && phone[i] <= '9'))
        {
            printf("Invalid phone number\n");
            return 1;
        }
    }

    // Check if the phone number already exists in the address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(phone, addressBook->contacts[i].phone) == 0)
        {
            printf("Phone number already exists\n");
            return 1;
        }
    }

    // Return 0 if the phone number is valid
    return 0;
}

// Function to validate the email
int email_validate(char email[], AddressBook *addressBook)
{
    int at = 0; // Counter for '@' symbol
    int dot = 0; // Flag for '.' symbol

    // Iterate through the email to count '@' and check for '.'
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            at++;
        if (email[i] == '.')
            dot = 1;
    }

    // Validate that there is exactly one '@' and at least one '.'
    if (at != 1 || dot != 1)
    {
        printf("Invalid email\n");
        return 1;
    }

    // Check if the email starts with '@' or '.'
    if(email[0] == '@' || email[0] == '.')
    {
        printf("Invalid email\n");
        return 1;
    }

    // Check if there is at least one character before and after '@'
    char *ptr;
    ptr = strchr(email, '@');
    if (!(*(ptr + 1) >= 'a' && *(ptr + 1) <= 'z') || (*(ptr + 1) >= 'A' && *(ptr + 1) <= 'Z'))
    {
        printf("Invalid email\n");
        return 1;
    }

    // Check if the email is unique in the address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(email, addressBook->contacts[i].email) == 0)
        {
            printf("Email already exists\n");
            return 1;
        }
    }

    // Return 0 if the email is valid
    return 0;
}
