#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::setfill;

class Contact
{
private:
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
    string darkSecret;

public:
    Contact();

    Contact(const string &firstName, const string &lastName,
            const string &nickname, const string &phoneNumber,
            const string &darkSecret);

    ~Contact();

    string getFirstName() const;
    string getLastName() const;
    string getNickname() const;
    string getPhoneNumber() const;
    string getDarkSecret() const;

    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setNickname(const string &nickname);
    void setPhoneNumber(const string &phoneNumber);
    void setDarkSecret(const string &darkSecret);

    void printFullInfo() const;
};

#endif
