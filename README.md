# SerialOptimisticConcurrencyControl
Implementation Serial Optimistic Concurrency Control DBMS in C++

Implementasi dari salah satu algoritma untuk menjaga konsistensi suatu database<br>
menggunakan bahaca c++

untuk menjalankan uji kasus 1<br>
ketik perintah berikut pada terminal ubuntu
```
g++ SerialOCC.cpp Transaction.cpp
./a.out
```
<br><br>

untuk menjalankan uji kasus 2 <br>
hilangkan komentar pada SerialOCC.cpp line 2
```
#define testcase2
```
kemudian ketik perintah berikut pada terminal ubuntu
```
g++ SerialOCC.cpp Transaction.cpp
./a.out
```
