#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const string &firstName, const string &lastName,
                 const string &nickname, const string &phoneNumber,
                 const string &darkSecret)
    : firstName(firstName),
      lastName(lastName),
      nickname(nickname),
      phoneNumber(phoneNumber),
      darkSecret(darkSecret) {}

Contact::~Contact() {}


string Contact::getFirstName() const { return firstName; }

string Contact::getLastName() const { return lastName; }

string Contact::getNickname() const { return nickname; }

string Contact::getPhoneNumber() const { return phoneNumber; }

string Contact::getDarkSecret() const { return darkSecret; }


void Contact::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkSecret(const string &darkSecret)
{
    this->darkSecret = darkSecret;
}


void Contact::printFullInfo() const
{
    cout << "First Name: " << firstName << endl
              << "Last Name: " << lastName << endl
              << "Nickname: " << nickname << endl
              << "Phone Number: " << phoneNumber << endl
              << "Dark Secret: " << darkSecret << endl;
}
