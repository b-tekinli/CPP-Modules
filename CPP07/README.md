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

int main() {
    int x = 3;
    int y = 2;
    
    char a = 'b';
    char b = 't';
    
    float pi = 3.14;
    float c = 12.4;
    
    std::string name = "beyza";
    std::string surname = "tekinli";
    
    std::string q = "test";
    std::string w = "test0";
    
    std::cout << "min value: " << min(x, y) << "\n";            // 2
    std::cout << "min value: " << min(a, b) << "\n";            // b --> ascii karakter değerine bakar.
    std::cout << "min value: " << min(pi, c) << "\n";           // 3.14
    std::cout << "min value: " << min(name, surname) << "\n";   // beyza --> ascii karakter değerine bakar.
    std::cout << "min value: " << min(q, w) << "\n";            // test --> ascii karakter değerlerini karşılaştırır.

    return 0;
}
```

Mesela burada yazmış olduğum örnekte float pi ve float c değişkenlerinden birini double yapsam bile ikisi de ondalıklı sayı olmasına rağmen T double ya da float arasında kalıp hangi veri tipini alacağını bilemediğinden error alırız. 
