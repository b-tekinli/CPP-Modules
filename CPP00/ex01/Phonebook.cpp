#include "Phonebook.hpp"

PhoneBook::PhoneBook() : index(0) {
    return;
}

PhoneBook::~PhoneBook() {
    return;
}

Contact PhoneBook::getContact(int index) const {
    return contacts[index];
}

void PhoneBook::setContact( Contact _contacts ) {
    contacts[index] = _contacts;
    count = (count < 8) ? count + 1 : count;
    index = (index + 1) % 8;
    return;
}

int PhoneBook::getCount() const {
    return count;
}

int PhoneBook::count = 0;