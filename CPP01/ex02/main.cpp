#include <iostream>
#include <string>

int main() 
{

    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;


    std::cout << "String'in bellek adresi: " << &str << std::endl;
    std::cout << "stringPTR'nin tuttugu bellek adresi: " << stringPTR << std::endl;
    std::cout << "stringREF'nin tuttugu bellek adresi: " << &stringREF << std::endl;


    std::cout << "String degişkeninin degeri: " << str << std::endl;
    std::cout << "stringPTR tarafindan isaret edilen deger: " << *stringPTR << std::endl;
    std::cout << "stringREF tarafindan isaret edilen deger: " << stringREF << std::endl;

    return (0);
}
