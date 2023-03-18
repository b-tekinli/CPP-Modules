#include <iostream>
#include <string>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() 
{

    string str = "HI THIS IS BRAIN";
    string *stringPTR = &str;
    string &stringREF = str;


    cout << "String'in bellek adresi: " << &str << endl;
    cout << "stringPTR'nin tuttugu bellek adresi: " << stringPTR << endl;
    cout << "stringREF'nin tuttugu bellek adresi: " << &stringREF << endl;


    cout << "String degişkeninin degeri: " << str << endl;
    cout << "stringPTR tarafindan isaret edilen deger: " << *stringPTR << endl;
    cout << "stringREF tarafindan isaret edilen deger: " << stringREF << endl;

    return (0);
}
