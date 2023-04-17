# **CPP03**

Inheritance.

## Inheritance nedir?

Bir class'ın özelliklerinin diğer class'lar tarafından kullanılmasına olanak tanıyan bir OOP kavramıdır. Diğer class'lar ana class'tan bir nevi miras alır. Miras alan sınıf, miras veren sınıftaki tüm özellikleri ve fonksiyonları miras alır ve bunları kendi özellikleri ve fonksiyonlarıyla birleştirir. Örneğin:

```cpp

// Base class
class Animal {
private:
    string name;

public:
    Animal(const string& name) : name(name) {}
    virtual void speak() const = 0;
};

// Derived class
class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name) {}

    void speak() const override {
        cout << "Hav hav" << name << endl;
    }
};

// Derived class
class Cat : public Animal {
public:
    Cat(const string& name) : Animal(name) {}

    void speak() const override {
        cout << "Miyav" << name << endl;
    }
};


int main() {
    Animal* animal1 = new Dog("Karabas");
    Animal* animal2 = new Cat("Sansli");

    animal1->speak(); // Hav hav
    animal2->speak(); // Miyav

    delete animal1;
    delete animal2;

    return (0);
}

```

---

## C++ dilinde protected kavramı nedir?

C++'da bir sınıfın değişkenleri default olarak private olarak belirlenir. Private değişkenlere sadece sınıfın kendisi erişebilir, dışarıdan erişim engellenir. Ancak protected değişkenler, sınıfın kendisi ve bu sınıftan türetilmiş sınıflar (miras alan sınıflar) bu değişkenlere erişebilirler. Bu sayede ClapTrap sınıfından türetilen diğer sınıflar, örneğin ScavTrap sınıfı, bu protected değişkenlere erişebilir ve kullanabilirler. Bu nedenle, ClapTrap sınıfında bulunan değişkenlerin protected olarak belirlenmesi, miras alan ve alt sınıfların bu değişkenlere erişebilmesi için önemlidir.
