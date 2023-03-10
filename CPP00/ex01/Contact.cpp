#include "Contact.hpp"

Contact::Contact() {
    return;
}

Contact::~Contact() {
    return;
}

string Contact::getName() const {
    return name;
}

string Contact::getSurname() const {
    return surname;
}

string Contact::getNickname() const {
    return nickname;
}

string Contact::getPhonenumber() const {
    return phonenumber;
}

string Contact::getSecret() const {
    return secret;
}

void Contact::setName( string _name ) {
    name = _name;
}

void Contact::setSurname( string _surname ) {
    surname = _surname;
}

void Contact::setNickname( string _nickname ) {
    nickname = _nickname;
}

void Contact::setPhonenumber( string _phonenumber ) {
    phonenumber = _phonenumber;
}

void Contact::setSecret( string _secret ) {
    secret = _secret;
}
