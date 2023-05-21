# **CPP05**

Repetition and Exceptions.

## Exceptions Nedir?

Exceptions aslında istisnai durumlar demektir. Yani program normal akışında devam ederken bu akışı bozacak olan bazı durumlardır. Bu durumları da *try-catch blokları* ile ele alırız. Eğer o durumlarda hata oluşursa *throw* keyword'ü fırlatılır.

`try`: Potansiyel olarak hata oluşturabilecek kod parçacığı bu blok içine yerleştirilir. Eğer istisna bir durum olursa program akışı _try_ bloğundan çıkar ve ilgili _catch_ bloğuna geçer.

`catch`: Belirli bir türdeki hatayı yakalamak için kullanılır. Bir hata yakalandığında ilgili _catch_ bloğu çalışır ve hatayı ele alır. Birden çok _catch_ bloğu kullanılarak farklı hata türlerine özel mesajlar tanımlayabiliriz.

`throw`: Hata fırlatmak için kullanılır. Bir _throw_ ifadesiyle birlikte bir hata nesnesi veya hata türü belirtilir. 

