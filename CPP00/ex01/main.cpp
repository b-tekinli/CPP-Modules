#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string command;

    std::cout << "Welcome to the 80's! This is your Phone Book.\n"
              << "You can ADD, SEARCH or EXIT. What would you like to do?\n";

    while (std::getline(std::cin, command))
    {
        if (command == "ADD")
        {
            std::string firstName, lastName, nickname, phoneNumber, darkSecret;
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkSecret);

            Contact contact(firstName, lastName, nickname, phoneNumber, darkSecret);
            phonebook.addContact(contact);
            std::cout << "Contact added to phone book.\n";
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContacts();
            std::cout << "Enter index of contact to view: ";

            int index;
            std::cin >> index;

            if (index < 0 || index > phonebook.getSize())
            {
                std::cout << "Invalid index.\n";
            }
            else
            {
                phonebook.getContact(index).printFullInfo();
            }
        }
        else if (command == "EXIT")
        {
            std::cout << "Goodbye!\n";
            return (0);
        }
        else
        {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    return (0);
}
