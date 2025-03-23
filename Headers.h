#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char name[50];  // Name of the contact
    char phone[20]; // Phone number of the contact
    char email[50]; // Email address of the contact
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS]; // Array to store contacts
    int contactCount;              // Number of contacts in the address book
} AddressBook;

void createContact(AddressBook *addressBook); // Function to create a new contact
int searchContact(AddressBook *addressBook);  // Function to search for a contact
void editContact(AddressBook *addressBook);   // Function to edit an existing contact
void deleteContact(AddressBook *addressBook); // Function to delete a contact
void listContacts(AddressBook *addressBook);  // Function to list all contacts
void initialize(AddressBook *addressBook);    // Function to initialize the address book
int Save(AddressBook *addressBook);           // Function to save the address book to a file
int name_validate(char name[], AddressBook *addressBook); // Function to validate the name
int phone_validate(char phone[], AddressBook *addressBook); // Function to validate the phone number
int email_validate(char email[], AddressBook *addressBook); // Function to validate the email address


#endif
