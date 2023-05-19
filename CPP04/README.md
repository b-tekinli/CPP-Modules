# **CPP04**

Subtype polymorphism, abstract classes, interfaces

## Virtual nedir?

virtual, C++ dilinde sanal fonksiyonlar (virtual functions) oluşturmak için kullanılan bir anahtar kelimedir. Sanal fonksiyonlar, oop için çok önemlidir ve subtype polymorphism (alt tür polymorphism) kullanarak, üst sınıf türündeki bir nesnenin alt sınıflarının herhangi bir türüne dönüştürülebilmesini sağlar.

Sanal fonksiyonların tanımlanması, bir sınıfın üyesi olan fonksiyonun alt sınıflar tarafından yeniden tanımlanabileceği anlamına gelir. Bu sayede, aynı üst sınıf türünden olan nesneler, farklı alt sınıfların fonksiyonlarını çağırarak dinamik olarak farklı şekillerde davranabilir.

Sanal fonksiyonlar, bir üst sınıf tarafından tanımlandıklarında ve alt sınıflar tarafından yeniden tanımlandıklarında, "override" (geçersiz kılma) edilirler. Bu, alt sınıf tarafından tanımlanan fonksiyonun çağrıldığı anlamına gelir. Alt sınıfların üye fonksiyonlarında virtual anahtar kelimesi kullanılmazsa, o fonksiyon sanal fonksiyon değildir ve override edilmez.

Ayrıca, sanal fonksiyonlar sayesinde bir üst sınıf türündeki bir nesnenin alt sınıf türündeki bir nesneye dönüştürülmesi işlemi, dinamik bir şekilde yapılır. Bu, alt sınıf türündeki nesnenin türüne göre ilgili alt sınıf fonksiyonlarının çağrılmasını sağlar.

Örnek;
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

Örnek;

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

Yukarıda hayvan class'ının abstract class olup olmadığını virtual fonksiyonların sıfıra eşitlenmesinden dolayı anlayabiliriz. Hayvan class'ından direkt olarak bir nesne türetemeyiz ama onu inherit alan kedi class'ından bir nesne türetebiliriz.


---

## Shallow Copy ve Deep Copy nedir?

Shallow copy (yüzeysel kopya) ve deep copy (derin kopya), nesnelerin kopyalanması sürecinde kullanılan iki farklı yöntemdir. İkisi arasındaki temel fark, kopyalanan nesnenin verilerine ve mevcut nesneye olan ilişkisine bağlıdır.

Shallow copy, mevcut nesnenin bellek alanının bir kopyasını oluştururken, referans türündeki verileri doğrudan kopyalar. Yani, mevcut ve kopya nesne aynı verilere işaret ederler. Bu durumda, eğer mevcut nesne yok edilirse veya değiştirilirse, kopya nesne de etkilenir.

Deep copy ise mevcut nesnenin tamamen bağımsız bir kopyasını oluşturur. Bellek alanı ve verilerin kopyası ayrı ayrı oluşturulur. Mevcut ve kopya nesneler birbirinden bağımsızdır ve herhangi bir değişiklik birbirini etkilemez.

Her 2 kopya yöntemine de günlük hayat üzerinden bakalım;

- Shallow Copy:

    Bir arkadaşınızın gardırobunda bulunan bir elbiseyi ödünç almak istiyorsunuz. Arkadaşınız size elbiseyi verirken elbisenin bir kopyasını değil kendisine ait olan elbiseyi verir. Siz de bu elbiseyi kullanmaya başladığınızda yapacağınız değişiklikler arkadaşınızın elbisesini de etkiler. Mesela rengini değiştirdiyseniz arkadaşınıza elbiseyi geri verdiğinizde rengi değişmiş olarak vereceksiniz. Yani, elbiseyi kullandığınızda yapacağınız değişiklikler arkadaşınızın elbisesini de etkiler.

- Deep Copy:

    Bu sefer arkadaşınız size elbisenin bir kopyasını verir. Bu kopya elbise aynı model, renk ve boyuta sahip olabilir ancak farklı bir elbise yani kopyasıdır. Siz bu kopya elbiseyi kullanırken arkadaşınızın orijinal elbisesi etkilenmez ve sizin yaptığınız değişiklikler sadece kopya elbiseyi etkiler.


Kod örneğiyle de anlatmak gerekirse:

```cpp
#include <iostream>
#include <string>

class Elbise {

private:
    string renk;

public:
    Elbise(const string &renk) : renk(renk) {}

    string getRenk() const {
        return renk;
    }

    void setRenk(const string &yeniRenk) {
        renk = yeniRenk;
    }
};

int main() {
    // Shallow Copy
    Elbise elbise1("Mavi");
    Elbise elbise2 = elbise1;

    cout << "Elbise 1 Rengi: " << elbise1.getRenk() << endl; // Mavi
    cout << "Elbise 2 Rengi: " << elbise2.getRenk() << endl; // Mavi

    elbise2.setRenk("Sarı");

    cout << "Elbise 1 Rengi: " << elbise1.getRenk() << endl; // Sarı - Etkilendi
    cout << "Elbise 2 Rengi: " << elbise2.getRenk() << endl; // Sarı - Değiştirildi


    // Deep Copy
    Elbise elbise3("Kırmızı");
    Elbise elbise4 = Elbise(elbise3.getRenk());

    cout << "Elbise 3 Rengi: " << elbise3.getRenk() << endl; // Kırmızı
    cout << "Elbise 4 Rengi: " << elbise4.getRenk() << endl; // Kırmızı

    elbise3.setRenk("Yeşil");

    cout << "Elbise 3 Rengi: " << elbise3.getRenk() << endl; // Yeşil - Değiştirildi
    cout << "Elbise 4 Rengi: " << elbise4.getRenk() << endl; // Kırmızı - Etkilenmedi

    return (0);
}


```

