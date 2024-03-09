## Container nedir?

Verileri depolamak ve yönetmek için kullanılan veri yapısıdır. Mesela bir dizi (array) oluşturduğumuzda nasıl içindeki elemanlara erişip istediğimiz elemanı çıkartıp ekleme yapabiliyorsak aynı şekilde container'lar da aslında içinde eleman bulunduran dizilerdir.

## Iteratör nedir?

Bir container'ın içindeki elemanlara erişmeyi sağlar. Aynı şekilde array üzerinden gidecek olursak bir for döngüsü açtığımızı düşünelim. Döngünün içinde indeksin i'sinden gelen bir i değişkeni tanımlayıp array'in içindeki elemanları yazdırmak istediğimizde indeks indeks gezeceğiz. İşte burada array diye bahsettiğim şey container ve içinde indislerle gezmek de iteratör oluyor. Kısaca iteratör de aslında container'ın içindeki her bir elemanına tekabül ediyor.

## Container yapıları nelerdir?

Vector, list, map, queue, stack gibi birçok container vardır. Neden bu kadar çok container var diyecek olursak aslında çok basit. Hepsi farklı erişim stratejisi sunuyor ve çeşitli işlevler sağlıyorlar. Mesela **vector** _random access (rastgele erişim)_ bir erişim sağlıyor yani array kullanırken arr[2] dediğimizde 3. elemanı alabilmemizi sağlaması gibi yani bir indekse doğrudan erişim sağlıyor. Farklı bir örnek üzerinden gidelim mesela **list** ise _bidirectional (çift yönlü)_ bir erişim sağlıyor. Yani sadece ileri ve geri giderek list'in içindeki elemanlara erişebiliriz yani direkt olarak bir doğrudan bir elemana erişim sağlayamayız. Aşağıda diğer container'lara örnek verelim:
- **Map** --> key-value ile key'e göre bir erişim sağlar. (Binary tree search tabanlı)
- **Stack** --> LIFO (son giren, ilk çıkar) ilkesine göre veri sakladığı için sadece en üstteki elemana erişim sağlayabiliriz.
- **Queue** --> FIFO (ilk giren, ilk çıkar) ilkesine göre veri sakladığından sadece en öndeki ve en arkadaki elemanlara erişim sağlayabiliriz.
- **Bitset** --> Bit düzeyinde işlemler yapmak için kullanılır. Bit dizisi gibi düşünebiliriz. Belirli bir bitin durumunu sorgulamak ve değiştirmek için kullanabiliriz yani random access sağlar.


```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = { 12, 2, 36, 42, 51 };;
    
    auto it = v.begin();
    
    cout << v[2] << "\n";
    
    cout << *it << "\n";
    
    it++;
    
    cout << *it << "\n";
    
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << "\n";
    }
}
```

Yukarıdaki kodda örnek bir vector kullanımı var. Buna ek olarak list ve stack kullanımlarına da bakalım. Önce list kullanımına bakalım.

```cpp
#include <iostream>
#include <list>

using namespace std;

int main() 
{
    list<int> myList = { 12, 2, 36, 42, 51 };
    
    auto it = myList.begin();
    
    cout << "3. eleman: " << *(++(++it)) << "\n";
    
    cout << "su anda gosterdigi yer: " << *myList.begin() << "\n";
    
    advance(it, 2);
    
    cout << "simdi de burayi gosteriyor: " << *it << "\n";


    for(auto it = myList.begin(); it != myList.end(); it++) {
        cout << "eleman degeri: " << *it << "\n";
    }
    
    
    return 0;
}
```

Aslında list, vector ile hemen hemen aynı fonksiyonlara sahip sadece random access olmadığından [] (subscript) operatörü ile erişemiyoruz. Buna ek olarak da _advance()_ fonksiyonu için konuşacak olursak, 2 parametre alır. İlk aldığı parametre iteratör, 2. aldığı parametre ise iteratörü kaç adım ilerletmek istediğimiz sayıdır. 3. elemanı yazdırdığımız satırda 3. elemana kadar ilerletmiş olduğumuzdan advance fonksiyonu içinde 2. parametreyi 2 verirsek 2 adım ilerletir ve 51 değerini yazdırmış oluruz.

Şimdi de stack kullanımını görelim.

```cpp
#include <iostream>
#include <stack>

using namespace std;

int main() 
{
    stack<int> myStack;

    myStack.push(15);
    myStack.push(20);
    myStack.push(25);
    myStack.push(42);
    
    cout << "en ussteki eleman: " << myStack.top() << "\n";
    
    while (!myStack.empty()) {
        cout << "cikartilan eleman: " << myStack.top() << "\n";
        myStack.pop();
    }
    
    
    return 0;
}
```
