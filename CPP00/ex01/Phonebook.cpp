#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : numContacts(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::addContact(const Contact &contact)
{
    if (numContacts < max_capacity)
    {
        contacts[numContacts] = contact;
        numContacts++;
        return true;
    }
    else
    {
        for (int i = 0; i < max_capacity - 1; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contacts[max_capacity - 1] = contact;
        return true;
    }
    return false;
}

void PhoneBook::searchContacts() const
{
    std::cout << std::setw(10) << "Index"
              << "|"
              << std::setw(10) << "First Name"
              << "|"
              << std::setw(10) << "Last Name"
              << "|"
              << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(73) << "-" << std::endl;
    std::cout << std::setfill(' ');

    for (int i = 0; i < numContacts; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(20) << contacts[i].getFirstName() << "|"
                  << std::setw(20) << contacts[i].getLastName() << "|"
                  << std::setw(20) << contacts[i].getNickname() << "|" << std::endl;
    }

    if (numContacts == 0)
    {
        std::cout << "The phonebook is empty." << std::endl;
    }
}

int PhoneBook::getSize() const
{
    return numContacts;
}

Contact PhoneBook::getContact(int index) const
{
    return contacts[index];
}
