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
#include <stdexcept>

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

    cout << "Program devam ediyor." << endl;

    return 0;
}

```

Yukarıda *exception &e* şeklinde bir referans kullanıyoruz. Orada yakalanan istisnai hata durumu exception class'ından bir nesne türeterek aslında hata türü olduğunu belirtiyor. Aynı şekilde *what()* fonksiyonunu da *e.what()* ifadesi ile yakalanan hatanın açıklamasını ekrana yazdırmak için kullanıyoruz. Yani _e.what()_ ifadesi, istisna nesnesinin içerdiği hata mesajını döndürür. Örnekteki kodda, ekrana "Hata yakalandı: Sıfıra bölme hatası!" şeklinde bir çıktı verir.

