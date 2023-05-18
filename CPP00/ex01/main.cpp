#include "PhoneBook.hpp"
#include "Contact.hpp"

int isAllDigit(string str)
{
    int i = str.length();

    if (i == 0)
        return 0;

    while (--i != -1)
        if (!(::isdigit(str[i])))
        {
            cout << "The index must be digit!!" << endl;
            return 0;
        }
    return 1;
}

int getIndexNumber()
{
    string index;

    do
    {
        getline(cin, index);
    } while (!isAllDigit(index));

    return ::atoi(index.c_str());
}

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

            phonebook.contactControl(firstName, lastName, nickname, phoneNumber, darkSecret);
            Contact contact(firstName, lastName, nickname, phoneNumber, darkSecret);
            phonebook.addContact(contact);
            cout << "Contact added to phone book.\n";
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContacts();
            cout << "Enter index of contact to view: ";

            int index = getIndexNumber();

            if (index < 0 || index >= phonebook.getSize())
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
    }

    return (0);
}
