# **CPP02**

Copy constructor, operator overloadlar, geçici polimorfizm, fixed point numbers (noktalı sayılar), noktalı sayılar RAM’de nasıl tutulur, ortodoks Kanonik sınıf formu.

## Fixed Point Numbers

'Fixed' adında sabit noktalı sayıları temsil eden bir sınıf oluşturulur. 'Fixed' sınıfı 32 bitlik tamsayıları kullanarak bir kesirli sayıyı tanımlar. Bu kesirli sayılar, bir tam sayı ve bir ondalık kısmın birleştirilmesiyle oluşur ve sabit bir noktalı sayı hassasiyetine sahiptir.

---

## C++ dilinde copy constructor nedir?

C++ dilinde, copy constructor bir sınıfın başka bir nesnesi ile aynı türde bir nesneyi oluşturmak için kullanılır. Bu işlem, bir nesnenin diğerine tam bir kopyasını oluşturmak için yapılır.

Copy constructor, bir nesnenin referansını alır ve yeni bir nesne oluşturmak için bu referanstaki nesnenin tüm verilerini kullanır. Bu, bir sınıfta tanımlanmış olan verilerin kopyalanması, dinamik olarak tahsis edilmiş bellek bloklarının kopyalanması ve diğer ilgili işlemlerin yapılması gibi adımları içerir.

Copy constructor, bir nesneyi diğerine kopyalamak için kullanılabilecek iki yöntemden biridir (diğeri atama operatörüdür). C++ derleyicisi, bir sınıfın copy constructor'unu otomatik olarak oluşturabilir, ancak sınıfın belirli gereksinimlerini karşılaması gerekir. Eğer sınıfın özel ihtiyaçları varsa, özel bir copy constructor tanımlanabilir.
Örnek olarak:

```cpp
#include <iostream>
using namespace std;

class Ogrenci {
    public:
        int numara;
        string ad;
        string soyad;

        Ogrenci() {
            numara = 0;
            ad = "";
            soyad = "";
        }

        Ogrenci(int n, string a, string s) {
            numara = n;
            ad = a;
            soyad = s;
        }

        Ogrenci(const Ogrenci& ogrenci) {
            numara = ogrenci.numara;
            ad = ogrenci.ad;
            soyad = ogrenci.soyad;
        }
};

int main() {
    Ogrenci ogrenci1(123, "Ahmet", "Yılmaz");
    Ogrenci ogrenci2 = ogrenci1; // Copy yapıcı kullanıldı
    cout << "Öğrenci 1: " << ogrenci1.numara << " " << ogrenci1.ad << " " << ogrenci1.soyad << endl;
    cout << "Öğrenci 2: " << ogrenci2.numara << " " << ogrenci2.ad << " " << ogrenci2.soyad << endl;
    return 0;
}
```

---

## C++ dilinde operator overload nedir?

C++'ta operator overload, bir sınıfta tanımlanmış olan bir operatörün kullanımını değiştirmek veya genişletmek için kullanılan bir tekniktir. Bu teknik sayesinde, sınıfın nesneleri üzerinde operatörlerin daha özelleştirilmiş bir şekilde kullanılması mümkün hale gelir.

Örneğin, bir sınıfın nesneleri üzerinde '+' operatörünü kullanmak istediğimizde, bu operatörün sınıfın özelliklerine uygun bir şekilde çalışması gerekir. Eğer sınıfın nesneleri üzerinde bu operatörün varsayılan davranışı yeterli değilse, operator overload tekniği kullanılarak bu operatörün işlevselliği değiştirilebilir.

Operator overload, C++ programlamasında oldukça önemli bir konudur ve sınıf tasarımı ve uygulamasında sıklıkla kullanılır. Ancak, operatörlerin aşırı yüklenmesi gerektiği durumlar tamamen tasarımcının ihtiyacına bağlıdır ve gereksiz kullanımı kodun okunurluğunu azaltabilir.

```cpp
class MyClass {
public:
  int x;
  
  MyClass& operator=(const MyClass& other) {
    if (this != &other) {
      x = other.x;
    }
    return *this;
  }
};
```

Bu örnekte, MyClass adlı sınıfın = operatörü aşırı yüklenmiştir. Bu operatör, bir MyClass nesnesinin mevcut değerini başka bir MyClass nesnesinin değeriyle değiştirmek için kullanılır.

Aşırı yüklenmiş = operatörü, const anahtar sözcüğü ile geçirilen bir MyClass nesnesinin referansını alır ve MyClass& türünden bir referans döndürür. Operatör, mevcut nesnenin değerini diğer nesnenin değerine eşitlemek için kullanılır.

Bu örnekte, atama işlemi yapılırken bellek yönetimini kontrol etmek için bir özel işlem yapılmadığından, RAM kullanımı sınırlıdır.

---

## Geçici Polimorfizm nedir?

Geçici polimorfizm, C++ gibi bir nesne yönelimli programlama dilinde, aynı arayüzü (saf sanal fonksiyonları) kullanan farklı sınıfların farklı davranışlar sergilemesidir. Bu, işlevin hangi sınıf tarafından çağrıldığına bağlı olarak değişen bir işlevsellik sağlar.

Örneğin, hayvanlar üzerinde çalışan bir programda, Animal sınıfı, hayvanların genel özelliklerini tanımlayacak bir arayüz sağlayabilir. Ardından, Dog ve Cat sınıfları, Animal sınıfından türetilerek Animal sınıfının arayüzünü uygularlar ve kendi özgün davranışlarını eklerler.

Aşağıdaki örnekte, Animal sınıfı, bir speak işlevi sağlar:

```cpp
class Animal {
public:
  virtual void speak() = 0;    // Saf sanal fonksiyon
};

class Dog : public Animal {
public:
  void speak() {
    std::cout << "Hav hav!" << std::endl;
  }
};

class Cat : public Animal {
public:
  void speak() {
    std::cout << "Miyav!" << std::endl;
  }
};

int main() {
  Animal* animal;

  animal = new Dog();
  animal->speak();

  animal = new Cat();
  animal->speak();
}
```

Bu örnekte, Animal sınıfı, saf sanal bir speak fonksiyonunu tanımlar. Dog ve Cat sınıfları, Animal sınıfından türetilir ve speak işlevini aşırı yükler.

main işlevi, önce bir Dog nesnesi oluşturur ve sonra Animal sınıfının bir işaretçisi olarak saklar. Ardından, speak işlevini çağırarak, Dog sınıfının speak işlevini çağırır. Aynı şey, Cat nesnesi için de yapılır. Bu, Animal sınıfı tarafından sağlanan bir arayüzü kullanarak, farklı sınıfların farklı davranışlar sergilemesine örnek bir geçici polimorfizm örneğidir.
