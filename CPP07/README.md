# **CPP07** 

Templates.

## Templates nedir?

Türkçeye şablonlar olarak çevirebiliriz. Template, bir fonksiyonun farklı veri tipleri ile tekrar tekrar kullanılmasını sağlar. En büyük avantajı kod tekrarını önlemesidir. Compile anında çalışırlar.

```cpp
template<typename T>
void example(T y) {
    std::cout << y << std::endl;
}
```

Templateler sadece yukarıdaki gibi fonksiyon değil class olarak da oluşturabilirler. Burada _**template<typename T>**_ ifadesinde T harfi aslında veri tipimizi belirtiyor. Mesela ben **y** parametresi için 12 verirsem buradaki T _int_ veri tipi almış olacak ama farklı bir veri tipi verirsem T o tipi almış olacak. 

```cpp
#include <iostream>
#include <string>

template<typename T>
T min(T&a, T &b) {
    return a < b ? a : b;
}

int main() 
{
    int x = 3;
    int y = 2;
    
    char a = 'b';
    char b = 't';
    
    float pi = 3.14;
    float c = 12.4;
    
    std::string name = "beyza";
    std::string surname = "tekinli";
    
    std::string q = "test1";
    std::string w = "test2";
    
    std::cout << "min value: " << ::min(x, y) << "\n";            // 2
    std::cout << "min value: " << ::min(a, b) << "\n";            // b --> ascii karakter değerine bakar.
    std::cout << "min value: " << ::min(pi, c) << "\n";           // 3.14
    std::cout << "min value: " << ::min(name, surname) << "\n";   // beyza --> ascii karakter değerine bakar.
    std::cout << "min value: " << ::min(q, w) << "\n";            // test1 --> ascii karakter değerlerini karşılaştırır.

    return 0;
}
```

Mesela burada yazmış olduğum örnekte _float pi_ ve _float c_ değişkenlerinden birini double yapsam bile ikisi de ondalıklı sayı olmasına rağmen T, double ve float arasında kalıp hangi veri tipini alacağını bilemediğinden error alırız. Her 2 değişken de aynı veri tipinde olmak zorunda.

Aynı zamanda main fonksiyonu içinde çağırırken **::min()** şeklinde başına **::** vererek çağırıyoruz. Neden _std_ vermiyoruz diyebilirsiniz. Bunun sebebi ise şu global namespace ya da başka herhangi bir yerde min ya da maks gibi fonksiyonlar illaki bulunuyor. Bu yüzden onlarla karışmasın diye kendi template'imiz olduğunu başına **::** vererek belirtiyoruz.

Aşağıya daha fazla örnek bırakıyorum.

```cpp
#include <iostream>
#include <string>

using namespace std;

// arraydeki tüm elemanların karesini al
template <typename T>
T square(T* arr, T len) {
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] * arr[i] << "\n";
    }
}

// stringin ilk harfini büyük yap
template <typename T>
void toUpperCaseFirst(T& str) {
    str[0] = toupper(str[0]);
}

// stringin tüm harflerini büyük yap
template <typename T>
void toUpperCase(T& str) {
    for(int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);       
    }
}

int main() {
    int arr[3] = {2, 3, 4};

    ::square(arr, 3);

    string name = "beyza";
    ::toUpperCaseFirst(name);

    cout << name << "\n";

    ::toUpperCase(name);
    cout << name << "\n";

    return (0);
}
```
