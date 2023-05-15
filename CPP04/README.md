# **CPP04**

Subtype polymorphism, abstract classes, interfaces

## Virtual nedir?

virtual, C++ dilinde sanal fonksiyonlar (virtual functions) oluşturmak için kullanılan bir anahtar kelimedir. Sanal fonksiyonlar, oop için çok önemlidir ve subtype polymorphism (alt tür polymorphism) kullanarak, üst sınıf türündeki bir nesnenin alt sınıflarının herhangi bir türüne dönüştürülebilmesini sağlar.

Sanal fonksiyonların tanımlanması, bir sınıfın üyesi olan fonksiyonun alt sınıflar tarafından yeniden tanımlanabileceği anlamına gelir. Bu sayede, aynı üst sınıf türünden olan nesneler, farklı alt sınıfların fonksiyonlarını çağırarak dinamik olarak farklı şekillerde davranabilir.

Sanal fonksiyonlar, bir üst sınıf tarafından tanımlandıklarında ve alt sınıflar tarafından yeniden tanımlandıklarında, "override" (geçersiz kılma) edilirler. Bu, alt sınıf tarafından tanımlanan fonksiyonun çağrıldığı anlamına gelir. Alt sınıfların üye fonksiyonlarında virtual anahtar kelimesi kullanılmazsa, o fonksiyon sanal fonksiyon değildir ve override edilmez.

Ayrıca, sanal fonksiyonlar sayesinde bir üst sınıf türündeki bir nesnenin alt sınıf türündeki bir nesneye dönüştürülmesi işlemi, dinamik bir şekilde yapılır. Bu, alt sınıf türündeki nesnenin türüne göre ilgili alt sınıf fonksiyonlarının çağrılmasını sağlar.


```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        cout << "The Animal Sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "Barks!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "Meows!" << endl;
    }
};

int main() {
    Animal* a1 = new Animal();
    Animal* a2 = new Dog();
    Animal* a3 = new Cat();

    a1->makeSound();  // The Animal Sound
    a2->makeSound();  // Barks!
    a3->makeSound();  // Meows!

    delete a1;
    delete a2;
    delete a3;

    return 0;
}
```

Yukarıda aynı fonksiyon olan makeSound() her sınıfta farklı şekilde tanımlandığı için yani override edildiği için her seferinde farklı çıktı verdi.

---

## Abstract class nedir?

Soyut sınıflar (abstract class) belirli fonksiyonları veya değişkenleri olan ancak doğrudan nesne oluşturulamayan sınıflardır. Soyut sınıflar, en az bir saf sanal fonksiyon içerirler. Saf sanal fonksiyonlar, sınıfın bir tür arayüzü olarak kullanılmasına izin verir ve bu fonksiyonlar soyut sınıfın alt sınıfları tarafından implement edilmelidir.

Örneğin, bir hayvan sınıfını soyut sınıf olarak ele alabiliriz. Hayvanların özelliklerini temsil eden bir sınıf tanımlayabilir ve bu sınıfın alt sınıfları olarak örnek olarak kedi, köpek, kuş, gibi hayvanları tanımlayabiliriz.

```cpp
class Hayvan
{
public:
    virtual void beslen() = 0;
    virtual void hareketEt() = 0;
};

class Kedi : public Hayvan
{
public:
    void beslen()
    {
        cout << "Kedi, balık yiyerek beslenir." << endl;
    }
    void hareketEt()
    {
        cout << "Kedi, dört ayak üzerinde hareket eder." << endl;
    }
};

int main()
{
    Hayvan *k = new Kedi();
    k->beslen();
    k->hareketEt();

    delete k;

    return (0);
}

```



---

