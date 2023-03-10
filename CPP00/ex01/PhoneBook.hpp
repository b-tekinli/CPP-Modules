#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
using std::cout;

class PhoneBook {
    private:
        Contact contacts[8];
        static int count;
        int index;
    
    public:
        PhoneBook() { }
        ~PhoneBook() { }
        Contact getContact(int index) const { };
        void setContact( Contact contact ) { }; 
        int getCount() const; 
};

#endif
