#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phonebook;
    string command;

    cout << "Welcome to the 80's! This is your Phone Book.\n"
              << "You can ADD, SEARCH or EXIT. What would you like to do?\n";

    while (getline(cin, command))
    {
        if (command == "ADD")
        {
            string firstName, lastName, nickname, phoneNumber, darkSecret;
            cout << "Enter first name: ";
            getline(cin, firstName);
            cout << "Enter last name: ";
            getline(cin, lastName);
            cout << "Enter nickname: ";
            getline(cin, nickname);
            cout << "Enter phone number: ";
            getline(cin, phoneNumber);
            cout << "Enter darkest secret: ";
            getline(cin, darkSecret);

            Contact contact(firstName, lastName, nickname, phoneNumber, darkSecret);
            phonebook.addContact(contact);
            cout << "Contact added to phone book.\n";
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContacts();
            cout << "Enter index of contact to view: ";

            int index;
            cin >> index;

            if (index < 0 || index > phonebook.getSize())
            {
                cout << "Invalid index.\n";
            }
            else
            {
                phonebook.getContact(index).printFullInfo();
            }
        }
        else if (command == "EXIT")
        {
            cout << "Goodbye!\n";
            return (0);
        }
        else
        {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return (0);
}
