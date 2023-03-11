#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string &firstName, const std::string &lastName,
                 const std::string &nickname, const std::string &phoneNumber,
                 const std::string &darkSecret)
    : firstName(firstName),
      lastName(lastName),
      nickname(nickname),
      phoneNumber(phoneNumber),
      darkSecret(darkSecret) {}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return firstName; }

std::string Contact::getLastName() const { return lastName; }

std::string Contact::getNickname() const { return nickname; }

std::string Contact::getPhoneNumber() const { return phoneNumber; }

std::string Contact::getDarkSecret() const { return darkSecret; }

void Contact::setFirstName(const std::string &firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkSecret(const std::string &darkSecret)
{
    this->darkSecret = darkSecret;
}

bool Contact::isEmpty() const
{
    return firstName.empty() && lastName.empty() && nickname.empty() &&
           phoneNumber.empty() && darkSecret.empty();
}

void Contact::printFullInfo() const
{
    std::cout << "First Name: " << firstName << std::endl
              << "Last Name: " << lastName << std::endl
              << "Nickname: " << nickname << std::endl
              << "Phone Number: " << phoneNumber << std::endl
              << "Dark Secret: " << darkSecret << std::endl;
}
