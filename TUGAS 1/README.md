# <h1 align="center">TUGAS 1</h1>
<p align="center">Renna Novaria W - S1SD 04A - 2311110047</p>

1. Sederhanakan program di bawah ini!

```C++
#include <iostream>
using namespace std;

bool cekDuplikat(int arr[]){
    int panjangArr = 4;
    for(int i=0; i<panjangArr; i++){
        for(int j=i+1; j<panjangArr; j++){
            if(arr[i]==arr[j]){
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int arrA[] = {2, 1, 3, 1};
    cout << cekDuplikat(arrA);

    return 0;
}
```

### Jawab

Source code
```C++
#include <iostream>
#include <unordered_set>
using namespace std;

bool cekDuplikat(int arr[], int panjangArr) {
    unordered_set<int> unik;

    for (int i = 0; i < panjangArr; i++) {
        if (unik.count(arr[i]) > 0) {
            return true;
        }
        unik.insert(arr[i]);
    }

    return false;
}

int main(void) {
    int arrA[] = {2, 1, 3, 1};
    cout << cekDuplikat(arrA, 4);

    return 0;
}
```

## Output
![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/c5605d83-d5a8-4c92-9105-0cb1d686899f)

## Interpretasi
Untuk mengetahui apakah ada elemen duplikat dalam array yang diberikan, yang terdiri dari array "{2, 1, 3, 1}" yang disimpan dalam array "arrA", program menjalankan fungsi "cekDuplikat". 

Untuk melacak elemen yang ditemukan selama iterasi, fungsi "cekDuplikat" menggunakan struktur data "unordered_set". Saat iterasi terhadap array dilakukan, setiap elemen dicek apakah ada dalam "unordered_set", dan jika ada, fungsi langsung mengembalikan "true", yang menunjukkan adanya duplikat. Jika tidak, elemen tersebut tidak dimasukkan ke dalam "unordered_set". Fungsi mengembalikan "false" jika tidak ditemukan duplikat setelah iterasi.

Dalam contoh ini, fungsi cekDuplikat(arrA, 4) mengembalikan true karena angka 1 muncul lebih dari sekali dalam array arrA, dan program mencetak 1.

Karena pencarian dan penyisipan dalam unordered_set memiliki kompleksitas waktu konstan untuk kebanyakan operasi, program ini dapat mendeteksi duplikat dengan kompleksitas waktu rata-rata O(n), di mana n adalah jumlah elemen dalam array.
