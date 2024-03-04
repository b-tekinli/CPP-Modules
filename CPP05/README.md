# **CPP05**

Repetition and Exceptions.

## Exceptions Nedir?

Exceptions aslında istisnai durumlar demektir. Yani program normal akışında devam ederken bu akışı bozacak olan bazı durumlardır. Hata yönetimi, hata ayıklama ve programın beklenmedik hallerle başa çıkması için önemli bir araçtır. Bu yapılar sayesinde programın kontrolü ele alınabilir ve istenmeyen durumların etkileri minimize edilebilir. Bu durumları da *try-catch blokları* ile ele alırız. Eğer o durumlarda hata oluşursa *throw* keyword'ü fırlatılır.


`try`: Potansiyel olarak hata oluşturabilecek kod parçacığı bu blok içine yerleştirilir. Eğer istisna bir durum olursa program akışı _try_ bloğundan çıkar ve ilgili _catch_ bloğuna geçer.

`catch`: Belirli bir türdeki hatayı yakalamak için kullanılır. Bir hata yakalandığında ilgili _catch_ bloğu çalışır ve hatayı ele alır. Birden çok _catch_ bloğu kullanılarak farklı hata türlerine özel mesajlar tanımlayabiliriz.

`throw`: Hata fırlatmak için kullanılır. Bir _throw_ ifadesiyle birlikte bir hata nesnesi veya hata türü belirtilir. Bu istisna oluşturan bir durumu belirtir ve programın normal akışını değiştirir.


Örnek bir kod bloğu;

```cpp

#include <iostream>
#include <exception>

using std::runtime_error, exception, cout, endl;

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Sıfıra bölme hatası!");
    }
    return a / b;
}

int main() {
    try {
        int a = 10;
        int b = 0;
        int c = divide(a, b);
        cout << "Sonuç: " << c << endl;
    } catch (const exception &e) {
        cout << "Hata yakalandı: " << e.what() << endl;
    }

    cout << "Program devam ediyor.\n";

    return 0;
}

```

Yukarıda *exception &e* şeklinde bir referans kullanıyoruz. Orada yakalanan istisnai hata durumu exception class'ından bir nesne türeterek aslında hata türü olduğunu belirtiyor. Aynı şekilde *what()* fonksiyonunu da *e.what()* ifadesi ile yakalanan hatanın açıklamasını ekrana yazdırmak için kullanıyoruz. Yani _e.what()_ ifadesi, istisna nesnesinin içerdiği hata mesajını döndürür. Örnekteki kodda, ekrana "Hata yakalandı: Sıfıra bölme hatası!" şeklinde bir çıktı verir.


## Exception Hiyerarşisi

İlk yakaladığı hatayı aynı _if - else if_ mantığı ile ilk catch bloğunda arar eğer bulamazsa bir sonrakine bakarak devam eder. İlkinde bulursa diğer catch bloklarına bakmaz.

```cpp
#include <iostream>
#include <exception>

int main() 
{
    try {
        int a = 12;
        int b = 0;
        
        if(a >= 0 && a <= 20) 
        {
            if(b == 0) {
                throw std::runtime_error("sifira bolme hatasi!");
                std::cout << "test\n";
            }
            else {
                int c = a / b;
                std::cout << "result: " << c << std::endl;
            }
        }
        else {
            throw std::invalid_argument("gecersiz arguman!");
        }
        
        std::cout << "test 2\n";
    } 
    catch (const std::invalid_argument &e) {
        std::cout << "invalid argument: " << e.what() << std::endl;
    }
    catch (const std::runtime_error &e) {
        std::cout << "runtime error: " << e.what() << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "general error: " << e.what() << std::endl;
    }
    
    std::cout << "test 3\n";
    
    int num = 1;
    std::cout << "total: " << num1 + 3 << std::endl;
    
    return (0);
}
```


## c_str Nedir?

Bir string sınıfının içerdiği karakter dizisini C-style string (null-terminated string) formatına dönüştüren bir fonksiyondur. Bu fonksiyon, C++'taki std::string sınıfının bir üye fonksiyonudur.

Bir std::string nesnesini c_str() fonksiyonuyla C-style string'e dönüştürmek, const char* türünde bir pointer döndürür. Bu pointer, ilgili std::string nesnesinin içerdiği karakter dizisinin başlangıcını gösterir ve bu dizinin sonunda bir null karakter ('\0') bulunur.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string myString = "Hello World!";
    
    const char* cStyleString = myString.c_str();
    
    std::cout << "C-style string: " << cStyleString << std::endl;

    return 0;
}
```

c_str fonksiyonunun döndürdüğü pointer, std::string nesnesi hayatta olduğu sürece geçerli olur.
