# AddressBook

The AddressBook project is a simple C-based application for managing contacts. It allows users to create, edit, delete, search, and list contacts, as well as save and load contact data from a file.

## Features

- **Add Contact**: Create a new contact with name, phone number, and email.
- **Edit Contact**: Modify the details of an existing contact.
- **Delete Contact**: Remove a contact from the address book.
- **Search Contact**: Search for a contact by name, phone number, or email.
- **List Contacts**: Display all contacts in the address book.
- **Save and Load**: Save contacts to a file and load them when the application starts.

## Project Structure


## How to Compile and Run

1. Open a terminal in the `AddressBook` directory.
2. Compile the project using `gcc`:
   ```sh
   gcc -o AddressBook Main_menu_and_function_call.c Add_contact.c Edit_contact.c Delete_contact.c Search_contact.c save_and_load.c Validations_file.c -Wall
3. Run the compiled program:
    ./AddressBook

Usage

1. When the program starts, you will see a menu with options to add, edit, delete, search, list, or exit.
2. Enter the corresponding number to perform an action.
3. Follow the prompts to input or modify contact details.
4. The program automatically saves changes to contact.dat.

Validation Rules

1. Name: Must be at least 3 characters long and contain only alphabetic characters.
2. Phone: Must be exactly 10 digits and unique.
3. Email: Must contain exactly one @ and at least one . and be unique.

File Descriptions

1. contact.dat: Stores the contact data in a binary format.
2. Headers.h: Contains type definitions for Contact and AddressBook, as well as function declarations.

Future Enhancements

1. Add support for exporting contacts to a CSV file.
2. Implement sorting of contacts by name, phone, or email.
3. Add a graphical user interface (GUI).

License

1. This project is open-source and available under the MIT License.

