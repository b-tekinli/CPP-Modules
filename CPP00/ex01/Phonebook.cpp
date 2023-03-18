#include "PhoneBook.hpp"

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
    cout << setw(15) << "Index"
              << "|"
              << setw(15) << "First Name"
              << "|"
              << setw(15) << "Last Name"
              << "|"
              << setw(15) << "Nickname"
              << "|" << endl;
    cout << setfill('-') << setw(65) << "-" << endl;
    cout << setfill(' ');

    for (int i = 0; i < numContacts; i++)
    {
        cout << setw(15) << i << "|"
                  << setw(15) << contacts[i].getFirstName() << "|"
                  << setw(15) << contacts[i].getLastName() << "|"
                  << setw(15) << contacts[i].getNickname() << "|" << endl;
    }

    if (numContacts == 0)
    {
        cout << "The phonebook is empty." << endl;
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
