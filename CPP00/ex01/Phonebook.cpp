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
        cout << setw(15) << i << "|" << setw(15)
             << contacts[i].getFirstName().substr(0, 9) + (contacts[i].getFirstName().length() > 9 ? "." : "") << "|"
             << setw(15) << contacts[i].getLastName().substr(0, 9) + (contacts[i].getLastName().length() > 9 ? "." : "") << "|"
             << setw(15) << contacts[i].getNickname().substr(0, 9) + (contacts[i].getNickname().length() > 9 ? "." : "") << "|" << endl;
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

string get_line(string prompt)
{
    string str;
    do
    {
        cout << prompt;
        getline(cin, str);
    } while (str.empty());

    return str;
}

void PhoneBook::contactControl(string &firstName, string &lastName, string &nickname,
                               string &phoneNumber, string &darkSecret)
{
    firstName = get_line("Enter FirstName:");
    lastName = get_line("Enter LastName:");
    nickname = get_line("Enter NickName:");
    phoneNumber = get_line("Enter PhoneNumber:");
    darkSecret = get_line("Enter DarkSecret:");
}
