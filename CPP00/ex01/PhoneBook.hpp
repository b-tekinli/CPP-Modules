#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    int numContacts;
    
    static const int max_capacity = 8;
    Contact contacts[max_capacity];

public:
    PhoneBook();
    ~PhoneBook();

    bool addContact(const Contact &contact);
    void searchContacts() const;
    int getSize() const;
    Contact getContact(int index) const;
};

#endif
