# **CPP06** 

Casts.

## Casts nedir?

Basitçe bir veri tipini başka bir veri tipine dönüştürmemizi sağlayan operatörlerdir. Bir değişken veya ifadenin veri tipini cast etmemizi sağlar. 3 tane cast çeşidi vardır. Bunlar;
1. static_cast
2. dynamic_cast
3. reinterpret_cast

Tek tek ne oldukları hakkında bilgi ve örnek verelim.
- `static_cast`: Genellikle güvenli olan ve belirli koşullar altında yapılan dönüşümlerde kullanılır. Sayısal veri türlerini int veya float değerlere dönüştürmek istediğimizde kullanabiliriz. Bir pointer'ı dönüştürme gibi işlemler için de kullanılabilir ama bu tür dönüştürmeler her zaman güvenli değildir.

```cpp
#include <iostream>

using namespace std;

int main ()
{
  double doubleNumber = 3.14;
  int intNumber = static_cast <int>(doubleNumber);
  
  cout << doubleNumber << "\n";
  cout << intNumber << "\n";
  
  return 0;
}
```

Yukarıdaki örnekte `double` veri tipindeki bir değişkeni `int` veri tipine dönüştürdük. Tam tersini de yapmak mümkün.


<br />


- `dynamic_cast`: Genellikle polimorfik sınıflar ve dinamik tür belirleme amacıyla kullanılır. Bir üst sınıfın bir alt sınıfa güvenli bir şekilde dönüştürülmesinde kullanılır. Run time'da tip kontrolü yapar ve uygun olmayan dönüşümlerde nullptr döner.

```cpp
#include <iostream>

using namespace std;

class Base {
public:
    virtual void foo() {
        cout << "base --> foo\n";
    }
};

class Derived : public Base {
public:
    void bar() {}
};


int main ()
{
    Base* basePtr = new Derived;
    basePtr->foo();
    
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    
    if (derivedPtr) {
        cout << "basarili\n";
    } else {
        cout << "basarisiz\n";
    }

    delete basePtr;
      
    return 0;
}
```

Yukarıdaki örnekte Derived class, Base class'ı inherit alıyor ve main üzerinde `Base* basePtr = new Derived` satırında basePtr nesnesi türetiliyor. Bu nesne her ne kadar Base class üzerinden türetiliyor gibi görünse de aslında Derived class'ından türetilmiş bir nesnedir ve amacı da Derived class'ının bir nesnesi olmasına rağmen Base class'ın özellik ve metotlarına da erişebilmemizi sağlamaktır. Bu durum algoritma tasarımına göre değişiklik gösterebilir. Her zaman bu şekilde kullanım yapmak doğru olmaz. Bunlar dışında dinamik olarak türettiğimiz bir nesne heap üzerinde yer kaplayacağı için delete etmeyi unutmamalıyız.


<br />


- `reinterpret_cast`: Genellikle türsüz dönüşümlerde kullanılır ve bu tür dönüşümler potansiyel olarak risklidir. Bit düzeyinde bir türden başka bir türe dönüşüm yapar ve genellikle dikkatli bir şekilde kullanılmalıdır.
Genellikle donanım düzeyinde işlemler yapmak veya özel durumlarda kullanmak için tercih edilir. Türsüz dönüşüm, bir veri tipini başka bir veri tipine dönüştürürken tip güvenliği konusunda kaygılı olmayan bir dönüşümü ifade eder.

```cpp
#include <iostream>

int main() {
    int intValue = 42;

    char* charPointer = reinterpret_cast<char*>(&intValue);

    for (int i = 0; i < sizeof(int); ++i) {
        std::cout << "Byte " << i << ": " << static_cast<int>(charPointer[i]) << std::endl;
    }

    return 0;
}
```

Yukarıdaki örnekte `int` veri tipindeki bir değişkeni `char *` veri tipine çeviriyoruz. Her karakterin bellek değerini ekrana yazdırıyoruz. Ancak dikkatli olmakta fayda var çünkü tür dönüşümü potansiyel olarak tanımsız davranışa neden olabilir.


<br />


### Static Değişken ve Static Fonksiyon nedir?

Static değişkenin ne olduğuyla başlayalım önce. Static değişken, programın çalışma süresi boyunca 1 kez oluşturulan ve bellekte aynı konumu paylaşan değişkendir. Bir static değişken, tanımlandığı sınıfın tüm nesneleri arasında paylaşılabilir. Neden kullandığımıza gelirsek, genel olarak bir bir sınıfın tüm nesneleri arasında paylaşılan verileri tutmak için kullandığımızı söyleyebiliriz.

```cpp
#include <iostream>

class Number {
public:
    static int num;
};

int Number::num = 4;

int main() {

    std::cout << "Sayı: " << Number::num << std::endl;

    return 0;
}
```

Yukarıdaki örnekte Number class'ının içinde num isimli bir static değişken oluşturduk. Bu değişkene `main()` fonksiyonu içinde Number class'ından bir nesne türetmeden direkt class üzerinden erişim sağladık. Belirli bir durumu saymak için mesela bir sınıftan kaç nesne türetildiğini saymak için kullanılabilir. Hatta bununla ilgili de bir örnek yapabiliriz:

```cpp
#include <iostream>

class Counter {
    public:
        static int count;
        
        void counter() {
            count++;
        }
};

int Counter::count = 0;

int main() {
    Counter ins1, ins2, ins3;
    
    ins1.counter();
    ins2.counter();
    ins3.counter();
    
    std::cout << "Toplam türetilen nesne sayısı: " << Counter::count << std::endl;
}
```

Burada 3 tane nesne türetip her seferinde counter fonksiyonunu çalıştırdığımız için 3 tane nesne oluşturulduğunu izleyebiliyoruz. Hangi durumlarda kullanıp izleyeceğiniz algoritma tasarımınıza bağlı.


<br />


Static fonksiyon ise, sınıfın herhangi bir nesnesine bağlı olmayan ve sınıf adı ile direkt olarak çağrılabilen bir fonksiyondur. Static fonksiyonlar sadece static olan değişken ve fonksiyonlara erişebilirler. 

```cpp
#include <iostream>

class Matematik {
public:
    static int kareToplami(int x, int y) {
        return (x * x) + (y * y);
    }

    void normalFonksiyon() {
        std::cout << "Normal fonksiyon" << std::endl;
    }
};

int main() {
    int kareSonucu = Matematik::kareToplami(3, 4);
    
    std::cout << "Kare Toplam: " << kareSonucu << std::endl;

    Matematik mat;
    mat.normalFonksiyon();

    return (0);
}
```


<br />


## Serialization ve Deserialization nedir?

`Serialization`, bir nesnenin durumunu bir dizi bitlere (bu genelde bir dosya veya ağ üzerinden gönderilebilecek bir byte akışı olur) dönüştürme işlemidir.

Daha açıklayıcı olması açısından mesela bir oyunda yeteri kadar ilerleme kat ettikten sonra bulunduğumuz durumu kaydetmek isteyebiliyoruz. Bu durumda oyundaki tüm nesneler, puanlar, ve karakterleri bir dosyaya yazıyoruz. Buna **serialization** deniyor.

`Deserialization` ise bunun tam aksi durumu. Bir byte akışını alır ve orijinal nesneyi yeniden oluşturur. Yine oyun örneği üzerinden gidecek olursak, kaydettiğimiz oyunu tekrar kaldığımız yerden devam ettirmek için yüklediğimiz zaman bu da **deserialization** oluyor.

