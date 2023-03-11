#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkSecret;

public:
    Contact();

    Contact(const std::string &firstName, const std::string &lastName,
            const std::string &nickname, const std::string &phoneNumber,
            const std::string &darkSecret);

    ~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkSecret() const;

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickname);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkSecret(const std::string &darkSecret);

    void printFullInfo() const;
};

#endif
