#ifndef Contact_HPP
#define Contact_HPP

#include <string>
using std::cout;

class Contact {
    private:
        string name;
        string surname;
        string nickname;
        string phonenumber;
        string secret;
        
    public:
        Contact() { }

        ~Contact() { }

        string getName() const { };
        string getSurname() const { };
        string getNickname() const { };
        string getPhonenumber() const { };
        string getSecret() const { };

        void setName( string _name ) { };
        void setSurname( string _surname ) { };
        void setNickname( string _nickname ) { };
        void setPhonenumber( string _phonenumber ) { };
        void setSecret( string _secret ) { };
};

#endif
