## Container nedir?

Verileri depolamak ve yönetmek için kullanılan veri yapısıdır. Mesela bir dizi (array) oluşturduğumuzda nasıl içindeki elemanlara erişip istediğimiz elemanı çıkartıp ekleme yapabiliyorsak aynı şekilde container'lar da aslında içinde eleman bulunduran dizilerdir.

## Iteratör nedir?

Bir container'ın içindeki elemanlara erişmeyi sağlar. Aynı şekilde array üzerinden gidecek olursak bir for döngüsü açtığımızı düşünelim. Döngünün içinde indeksin i'sinden gelen bir i değişkeni tanımlayıp array'in içindeki elemanları yazdırmak istediğimizde indeks indeks gezeceğiz. İşte burada array diye bahsettiğim şey container ve içinde indislerle gezmek de iteratör oluyor. Kısaca iteratör de aslında container'ın içindeki her bir elemanına tekabül ediyor. 

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
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

Buradaki kodda örnek bir kullanım var. 
