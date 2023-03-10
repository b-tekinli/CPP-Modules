# **CPP00**

Namespaceler, sınıflar, member fonksiyonlar, stdio streamleri, initialization listeleri, static, const, ve bazı diğer basit şeyler.

## C++ dilinde namespace nedir ve neden kullanılır?

C++ programlama dilinde `namespace`, birbirinden ayrı işlevleri olan değişkenler, fonksiyonlar, sınıflar ve diğer nesnelerin isimlerini organize etmek için kullanılan bir yapıdır.

Bu yapı, programda tanımlanan isimlerin benzersiz olmasını sağlar. Çünkü aynı isim, farklı `namespace`'lerde kullanılabilir. Böylece, isim çakışması sorunlarından kaçınılır.

`Namespace`'lerin kullanımı ayrıca, programın okunabilirliğini de artırır. Çünkü bir `namespace` içindeki isimler, o `namespace` ile ilgili işlevleri olan isimlerdir. Bu sayede, kodun anlaşılması ve yönetilmesi daha kolay hale gelir.

Örneğin, bir proje içinde "math.h" kütüphanesi ve "myMath.h" isimli bir dosya kullanıyorsak, içerisinde çakışan fonksiyon isimleri olabilir. Bu durumda, "math.h" kütüphanesi için `namespace` tanımlayabiliriz. Böylece, çakışan fonksiyon isimleri arasında bir ayrım yapabiliriz.

```cpp
namespace myMath {
  int add(int a, int b) {
    return a + b;
  }
}

int main() {
  int result = myMath::add(2, 3);
  return 0;
}

```

Yukarıdaki örnekte, "myMath.h" dosyasında "add" isimli bir fonksiyon tanımlanmıştır. Bu fonksiyon, "myMath" isimli bir `namespace`'in içinde yer almaktadır. `Namespace` adı ile birlikte "add" fonksiyonunu kullanarak, çakışan isimlerin önüne geçilmiştir.

Bu nedenlerden dolayı, C++ dilinde `namespace`'ler yaygın bir şekilde kullanılır.

---

## C++ dilinde class nedir ve neden kullanılır?

C++ dilinde `class`lar, nesneye yönelik programlama (OOP) paradigmalarından biridir. `Class`, bir nesneyi oluşturmak için kullanılan bir şablondur. Kodun anlaşılmasını ve yönetilmesini kolaylaştırır. Ayrıca, kodun yeniden kullanılmasını da sağlar.`Class`'lar, bir nesnenin özelliklerini (veri üyeleri) ve davranışlarını (üye fonksiyonlar) tanımlar.

Örneğin, bir arabanın bir `class`'ı şu şekilde olabilir:

```cpp
class Araba {
public:
  // Arabanın özellikleri
  std::string marka;
  std::string model;
  int yil;
  double fiyat;

  // Arabanın davranışları
  void calistir();
  void durdur();
  void hizlan(int hiz);
  void yavasla(int hiz);
};

```

Yukarıdaki örnekte, `Araba` adında bir `class` tanımlanmıştır. Bu `class`'da, bir arabanın özellikleri (marka, model, yıl, fiyat) ve davranışları (çalıştırma, durdurma, hızlanma, yavaşlama) tanımlanmıştır.

`Class`'lar, bir nesneyi oluşturmak için kullanılır. Örneğin, yukarıdaki `Araba` `class`'ından bir nesne oluşturmak için şu şekilde yapabiliriz:

```cpp
Araba araba1;
araba1.marka = "Ford";
araba1.model = "Mustang";
araba1.yil = 2020;
araba1.fiyat = 50000.0;

```

Yukarıdaki örnekte, `Araba` `class`'ından `araba1` adında bir nesne oluşturulmuştur. Bu nesne, `Araba` `class`'ındaki özelliklerle (marka, model, yıl, fiyat) tanımlanmıştır.

---

## C++ dilinde member fonksiyon nedir ve neden kullanılır?

C++ dilinde, `class`'ların bir parçası olarak tanımlanan fonksiyonlara `member fonksiyonlar` denir. `Member fonksiyonlar`, bir `class`'ın özelliklerine (veri üyeleri) ve davranışlarına (diğer `member fonksiyonlar`) erişebilirler.

Örneğin, `Araba` `class`'ımızda `member fonksiyonlar` şu şekilde tanımlanabilir:

```cpp
class Araba {
public:
  // Arabanın özellikleri
  std::string marka;
  std::string model;
  int yil;
  double fiyat;

  // Arabanın davranışları
  void calistir();
  void durdur();
  void hizlan(int hiz);
  void yavasla(int hiz);
};

void Araba::calistir() {
  std::cout << "Araba çalıştı." << std::endl;
}

void Araba::durdur() {
  std::cout << "Araba durdu." << std::endl;
}

void Araba::hizlan(int hiz) {
  std::cout << "Araba " << hiz << " km/s hızlandı." << std::endl;
}

void Araba::yavasla(int hiz) {
  std::cout << "Araba " << hiz << " km/s yavaşladı." << std::endl;
}

```

`Member fonksiyonlar`, `class`'ın özelliklerine (marka, model, yıl, fiyat) ve diğer `member fonksiyonlara` erişebilirler.

Örneğin, `Araba` `class`'ından bir nesne oluşturduktan sonra `member fonksiyonları` kullanabiliriz:

```cpp
Araba araba1;
araba1.marka = "Ford";
araba1.model = "Mustang";
araba1.yil = 2020;
araba1.fiyat = 50000.0;

araba1.calistir();  // Araba çalıştı.
araba1.hizlan(100); // Araba 100 km/s hızlandı.
araba1.yavasla(50); // Araba 50 km/s yavaşladı.
araba1.durdur();    // Araba durdu.

```

Yukarıdaki örnekte, `Araba` `class`'ından `araba1` adında bir nesne oluşturulmuştur. Bu nesne, `Araba` `class`'ındaki özelliklerle (marka, model, yıl, fiyat) tanımlanmıştır. Ardından, `araba1` nesnesinin `member fonksiyonları` (calistir(), hizlan(), yavasla() ve durdur()) kullanılmıştır.

`Member fonksiyonlar`, bir `class`'ın davranışlarını tanımlamak için kullanılır. Bu sayede, nesneye yönelik programlama (OOP) paradigmaları daha kolay bir şekilde uygulanabilir.

---

## C++ dilinde stdio streamleri nedir?

C++ dilinde `stdio streamleri`, standart giriş/çıkış işlemlerini gerçekleştirmek için kullanılan bir yapıdır. Bu streamler, giriş/çıkış işlemlerini kolaylaştırır ve programın okunabilirliğini artırır. Bu streamler, `cin` ve `cout` nesnelerini içerir.

`cin`, kullanıcıdan veri girişi almak için kullanılır. Örneğin, kullanıcıdan bir tamsayı almamız gerektiğinde şu şekilde kullanabiliriz:

```cpp
int sayi;
std::cin >> sayi;
```

Alınan veri, `sayi` adlı değişkene atanmıştır.

`cout`, programın çıkışını yazdırmak için kullanılır. Örneğin, ekrana bir metin yazdırmak için şu şekilde kullanabiliriz:

```cpp
std::cout << "Merhaba Dünya!" << std::endl;
```

"Merhaba Dünya!" metni ekrana yazdırılmıştır.

---

## C++’ta  initialization listeleri nedir?

C++ dilinde `initialization listeleri`, bir sınıfın üyelerine değer atamak için kullanılan bir yapıdır. Bu yapı, nesne oluşturma sürecinde üyelere değer atamayı daha hızlı ve daha etkin hale getirir.

`Initialization listeleri`, bir sınıfta tanımlanan üyelerin, nesne oluşturulurken ilk değerlerinin atanmasını sağlar. Bu sayede, sınıfın üyelerine tek tek değer atama işlemi yerine, `initialization listeleri` kullanarak daha hızlı bir şekilde değer atayabiliriz.

Örneğin, aşağıdaki `Person` sınıfında, `name` ve `age` adlı iki üye tanımlanmıştır:

```cpp
class Person {
private:
  std::string name;
  int age;

public:
  Person(std::string _name, int _age) {
    name = _name;
    age = _age;
  }
};

```

Bu üyelerin değerleri, yapıcı fonksiyon (constructor) tarafından atanır.

Ancak, `initialization listeleri` kullanarak bu işlemi daha hızlı ve daha etkin bir şekilde yapabiliriz:

```cpp
class Person {
private:
  std::string name;
  int age;

public:
  Person(std::string _name, int _age)
    : name(_name), age(_age) {}
};
```

Yukarıdaki örnekte, `initialization listeleri` kullanarak `name` ve `age` üyelerine değer atamışız. Bu sayede, yapıcı fonksiyon daha hızlı ve daha etkin bir şekilde çalışır.

`Initialization listeleri`, nesne oluşturma sürecinde üyelere değer atamayı daha hızlı ve daha etkin hale getirir. Bu nedenle, C++ dilinde yaygın bir şekilde kullanılır.

---

## C++ dilinde static ve const nedir?

C++ dilinde `static` ve `const`, değişkenler ve fonksiyonlar için kullanılan iki önemli özelliktir.

### Static

`Static`, bir değişkenin bir sınıfın tüm örnekleri arasında paylaşılan bir özellik olduğunu belirtmek için kullanılır. Bu, bir sınıftan oluşturulan tüm nesnelerin aynı `static` değişkeni paylaşacağı anlamına gelir.

Örneğin, aşağıdaki `Person` sınıfında `count` adlı bir `static` değişken tanımlanmıştır:

```cpp
class Person {
private:
  std::string name;
  int age;
  static int count; // static değişken

public:
  Person(std::string _name, int _age) {
    name = _name;
    age = _age;
    count++; // Her bir nesne oluşturulduğunda count arttırılır
  }

  static int getCount() {
    return count; // Tüm nesnelerin sayısını döndürür
  }
};

int Person::count = 0; // static değişkenin başlangıç değeri atanır
```

Yukarıdaki örnekte, `Person` sınıfında `count` adlı bir `static` değişken tanımlanmıştır. Bu değişken, her bir `Person` nesnesi oluşturulduğunda arttırılır ve sınıfın tüm örnekleri arasında paylaşılır.

`Static` değişkenler, bir sınıfın tüm örnekleri arasında paylaşılan bir özellik olduğu için, hafıza kullanımını optimize etmek için kullanılabilirler. Ayrıca, `static` fonksiyonlar da tanımlanabilir. Bu fonksiyonlar, sınıfın tüm örnekleri arasında paylaşılan bir özellik taşımazlar.

### Const

`Const`, bir değişkenin sabit olduğunu belirtmek için kullanılır. Bu, bir değişkenin bir kez tanımlanıp daha sonra değiştirilemeyeceği anlamına gelir. Böylelikle programın daha güvenli ve daha tutarlı hale gelmesini sağlar.

Örneğin, aşağıdaki `Circle` sınıfında `PI` adlı bir `const` değişken tanımlanmıştır:

```cpp
class Circle {
private:
  double radius;
  const double PI = 3.14159; // const değişken

public:
  Circle(double _radius) {
    radius = _radius;
  }

  double getArea() {
    return PI * radius * radius; // PI sabiti kullanılır
  }
};
```

Bu değişken, bir kez tanımlanıp daha sonra değiştirilemez. `PI` sabiti, `getArea()` fonksiyonunda kullanılır.

---

***Static ve Const Özet:***
`Static` ve `const`, C++ dilinde değişkenler ve fonksiyonlar için kullanılan iki önemli özelliktir. `Static`, bir değişkenin bir sınıfın tüm örnekleri arasında paylaşılan bir özellik olduğunu belirtmek için kullanılırken, `const`, bir değişkenin sabit olduğunu belirtmek için kullanılır.
