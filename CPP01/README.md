# **CPP01**

Memory allocation, üyeler için işaretçiler, referanslar, switch ifadesi.

## Cpp'de memory allocation nedir ve nasıl yapılır?

Cpp programlama dilinde, programların çalışması sırasında çalışma zamanında dinamik olarak bellek tahsis edilmesi gerekebilir. Bu, programcının yeni veri yapısı oluşturması veya veri yapısının boyutunu değiştirmesi gerektiğinde kullanışlıdır.

Cpp'de, bellek tahsisi yapmak için iki yöntem vardır:

1. **Static allocation**: Bu yöntemde, programcı bellek alanını kodda belirler ve bu bellek alanı programın çalışması boyunca sabit kalır. Bu yöntem, programın bellek yönetimi açısından daha verimli olmasına rağmen, esnek değildir ve bellek boyutunu değiştirmek için yeniden derleme yapmak gerekebilir.
2. **Dynamic allocation**: Bu yöntemde, programcı bellek alanını çalışma zamanında tahsis eder ve programın ihtiyaç duyduğu bellek alanını dinamik olarak değiştirebilir. Bu yöntem daha esnektir ancak bellek yönetimi daha karmaşıktır ve bellek sızıntılarına yol açabilir.

Cpp'de bellek tahsis etmek için "new" ve "delete" operatörleri kullanılır. "new" operatörü, bellek alanı tahsis etmek için kullanılırken, "delete" operatörü bellek alanını serbest bırakmak için kullanılır.

Örneğin, aşağıdaki kod satırı, bir tamsayı için bellek tahsis eder:

```cpp
int *ptr = new int;
```

Bu kod satırı, bir tamsayı için bellek tahsis eder ve "ptr" adlı bir işaretçi değişkenine atar. Bellek tahsisi tamamlandıktan sonra, değişkenin bellekteki adresine "ptr" işaret eder.

Bellek alanının serbest bırakılması için "delete" operatörü kullanılır:

Bu kod satırı, "ptr" işaretçisinin gösterdiği bellek alanını serbest bırakır.

```cpp
delete ptr;
```

Bellek tahsisinin yanı sıra, Cpp'de bellek yönetimi için diğer operatörler de vardır, ancak "new" ve "delete" operatörleri en yaygın olanlarıdır.

Dinamik tahsis yöntemi, programlama sırasında ihtiyaç duyulan bellek miktarının programın çalışma zamanında belirlenmesini sağlar. Bu nedenle, dinamik tahsis yöntemi ile programlama yaparken, programın bellek ihtiyacı değişebildiği durumlarda esneklik sağlar. Dinamik tahsis, programlama sırasında daha fazla kod yazmayı gerektirir, ancak bellek yönetiminde daha fazla esneklik sağlar.

Statik tahsis yöntemi ile arasındaki fark, bellek yönetimi esnekliği ve bellek alanı tahsis yöntemidir. Statik tahsis yöntemi, programın bellek alanını derleme sırasında önceden tahsis eder ve bellek alanı sınırlıdır. Dinamik tahsis yöntemi, programın bellek ihtiyacını çalışma zamanında belirler ve programın çalışması sırasında bellek alanı tahsis edilir.

**Static tahsis yöntemine örnek:**

```cpp
#include <iostream>

int main()
{

	int arr[5] = {1, 2, 3, 4, 5};
	
	for (int i = 0; i < 5; i++) 
	{
	    std::cout << arr[i] << " ";
	}
	
	return (0);
}
```

```cpp
#include <iostream>

const int size = 5;

int main()
{
	int arr[size];
	for (int i = 0; i < size; i++) {
	    arr[i] = i * 2;
	    std::cout << arr[i] << " ";
	}
	
	return (0);
}
```

Yukarıdaki örnekte, programın bellek ihtiyacı derleme sırasında belirlenir ve programın çalışması sırasında tahsis edilen bellek alanı sabit kalır. Statik tahsis yöntemi ile programlama yaparken, bellek yönetimi için daha az kod yazmak gerekir. Ancak, programın bellek ihtiyacı değişebildiği durumlarda esneklik sağlamaz.

**Dinamik tahsis yöntemine örnek:**

```cpp
#include <iostream>

int main()
{
	int n;
	std::cout << "Enter the size of the array: ";
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
	    arr[i] = i * 2;
	    std::cout << arr[i] << " ";
	}

	delete[] arr;
	return (0);
}
```

Yukarıdaki örnekte, kullanıcıdan alınan değer ile dinamik olarak bellek alanı tahsis edilir ve bu bellek alanı programın çalışması sırasında kullanılır. Dinamik tahsis yöntemi, programın bellek ihtiyacının program çalışma zamanında belirlenebilmesi sayesinde esneklik sağlar.

---

## C++ dilinde bir sınıf üyesine pointer ataması nasıl yapılır?

Cpp'de, bir sınıfın üyesi olarak tanımlanan bir veri elemanına, işaretçi veya referans kullanarak erişilebilir. Bu, veri elemanının bellek adresine doğrudan erişmek yerine, sınıfın bir örneği üzerinden erişim sağlar ve nesne yönelimli programlama konseptlerine uygun bir yaklaşımdır.

Bir üyenin işaretçi veya referans olarak tanımlanması, üyenin bellek adresini kullanarak doğrudan bellek manipülasyonunu sağlar. Bu, bellek yönetimi açısından daha esnek bir yaklaşım sunar, ancak aynı zamanda bellek sızıntılarına veya geçersiz bellek erişimlerine yol açabilir.

Örneğin, aşağıdaki kod örneğinde, bir sınıfta bir üye işaretçisi tanımlanmaktadır:

```cpp
class MyClass {
public:
    int *myInt;
};
```

Bu kod örneğinde, "myInt" adlı bir işaretçi, "MyClass" adlı bir sınıfın üyesi olarak tanımlanır. Bu işaretçi, sınıfın örneği üzerinden erişilebilir ve ilgili bellek adresine doğrudan erişim sağlayabilir.

Bir üyenin referans olarak tanımlanması, işaretçi ile aynı şekilde bellek manipülasyonu sağlar, ancak işaretçiye göre daha güvenlidir. Referanslar, bellek sızıntılarına veya geçersiz bellek erişimlerine yol açabilen işaretçi aritmetiği veya bellek adresi aritmetiği kullanmazlar.

Örneğin, aşağıdaki kod örneğinde, bir sınıfta bir üye referansı tanımlanmaktadır:

```cpp
class MyClass {
public:
    int &myInt;
};
```

Bu kod örneğinde, "myInt" adlı bir referans, "MyClass" adlı bir sınıfın üyesi olarak tanımlanır. Bu referans, sınıfın örneği üzerinden erişilebilir ve ilgili bellek adresine doğrudan erişim sağlayabilir.

Üye işaretçileri veya referanslarının kullanımı, programlama sırasında bellek yönetimine daha fazla esneklik sağlar. Ancak, doğru bir şekilde kullanılmadığında, bellek sızıntılarına veya geçersiz bellek erişimlerine yol açabilir. Bu nedenle, üye işaretçileri veya referanslarının kullanımı, programcının dikkatli bir şekilde ve ihtiyatlı bir şekilde ele alması gereken bir konudur.

---

## C++ dilinde, switch ifadesi nedir?

C++ dilinde, switch ifadesi, belirli bir değişkenin değerine göre farklı kod bloklarının çalıştırılmasını sağlar. Genellikle, if ifadesi yerine kullanılır ve kodun okunabilirliğini artırır.

Switch ifadesi, aşağıdaki şekilde kullanılır:

```cpp
switch (değişken) {
    case değer_1:
        // değer_1 için çalışacak kod bloğu
        break;
    case değer_2:
        // değer_2 için çalışacak kod bloğu
        break;
    ...
    default:
        // hiçbiri için geçerli olmayan durumlar için çalışacak kod bloğu
        break;
}
```

Bu kod bloğu, "değişken" adlı bir değişkenin değerine göre farklı kod bloklarının çalıştırılmasını sağlar. "case" ifadesi, farklı değerler için çalışacak kod bloklarını belirtir. Her "case" ifadesi, bir değer veya bir aralık içerebilir.

"break" ifadesi, her "case" ifadesinin sonunda kullanılır ve kod bloğunun çalışmasını durdurur. "default" ifadesi, herhangi bir "case" ifadesiyle eşleşmeyen durumlar için bir kod bloğu belirtir.

Örneğin, aşağıdaki kod örneğinde, bir kullanıcının girdiği sayıya göre farklı bir ayın adı yazdırılır:

```cpp
#include <iostream>

int main() {
    int ay;
    std::cout << "Bir ay numarası girin: ";
    std::cin >> ay;

    switch (ay) {
        case 1:
            std::cout << "Ocak" << std::endl;
            break;
        case 2:
            std::cout << "Şubat" << std::endl;
            break;
        case 3:
            std::cout << "Mart" << std::endl;
            break;
        case 4:
            std::cout << "Nisan" << std::endl;
            break;
        case 5:
            std::cout << "Mayıs" << std::endl;
            break;
        case 6:
            std::cout << "Haziran" << std::endl;
            break;
        case 7:
            std::cout << "Temmuz" << std::endl;
            break;
        case 8:
            std::cout << "Ağustos" << std::endl;
            break;
        case 9:
            std::cout << "Eylül" << std::endl;
            break;
        case 10:
            std::cout << "Ekim" << std::endl;
            break;
        case 11:
            std::cout << "Kasım" << std::endl;
            break;
        case 12:
            std::cout << "Aralık" << std::endl;
            break;
        default:
            std::cout << "Geçersiz ay numarası!" << std::endl;
            break;
    }

    return 0;
}
```

Bu kod örneğinde, kullanıcının girdiği sayıya göre farklı bir ayın adı yazdırılır. "switch" ifadesi, "ay" adlı bir değişkenin değerine göre farklı kod bloklarının çalıştırılmasını sağlar. "case" ifadesi, farklı sayılar için çalışacak kod bloklarını belirtir. "default" ifadesi, hiçbir "case" ifadesiyle eşleşmeyen durumlar için bir kod bloğu belirtir.

---

## C++ dilinde, ifstream nedir?

ifstream, bir dosyanın verilerine erişmek ve onları okumak için kullanılan bir sınıftır. ifstream sınıfının open() metodu çağırılarak dosya okuma işlemi yapılabilir. Okuma işlemi tamamlandıktan sonra close() metodunu çağırmak dosya bağlantısını kapatır.

Örneğin, aşağıdaki kod parçası, example.txt adlı bir dosyayı okuyarak, dosyadaki tüm satırları ekrana yazdıracaktır:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("example.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '\n';
    }
    file.close();
    return 0;
}
```
Yukarıdaki kodda ifstream sınıfı, file adlı bir nesne oluşturmak için kullanılmıştır. Daha sonra, getline() metodu, dosyadan bir satır okur ve bu satırı line adlı bir string değişkenine atar. Bu işlem, dosyadaki tüm satırlar okunana kadar devam eder. En sonunda, close() metodu, dosya bağlantısını kapatır.
