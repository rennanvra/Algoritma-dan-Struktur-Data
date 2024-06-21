# <h1 align="center">TUGAS 3</h1>
<p align="center">Renna Novaria W - S1SD 04A - 2311110047</p>

## Priority Queue

### Pengertian Priority Queue

Priority queue merupakan tipe data struktur data queue, namun yang membedakan antara priority queue dan queue adalah pada priority queue setiap elemen mempunyai "pioritas" yang telah ditetapkan pada masing-masing elemen[1]. Pada dasarnya, pada priority queue memiliki 3 prioritas yaitu tinggi, sedang, dan rendah. Karena adanya "prioritas" tersebut, maka algoritma priority queue bekerja dengan prinsip HPIFO *(Higher Priority In First Out)* yang mana elemen yang memiliki prioritas tertinggi akan diselesaikan terlebih dahulu[2]. 

**2 Jenis ALgoritma Priority Queue**
- *Ascending Priority Queue* : data diurutkan dengan prioritas naik
- *Descending Priority Queue* : data diurutkan dengan prioritas menurun.

**2 Operasi mengubah data pada Algoritma Priority Queue**
- *Enqueue* : proses menambahkan data ke akhir urutan data
- *Dequeue* : proses menghapus data pada awal urutan data.

### Metode Priority Queue

**1. Push()**

Push() digunakan untuk memasukkan elemen baru ke dalam antrian dengan memperhatikan prioritasnya,  Nilai prioritas elemen baru dibandingkan dengan nilai prioritas elemen yang sudah ada dalam antrian, lalu menempatkan elemen baru di posisi yang tepat di antara elemen yang sudah ada untuk memastikan urutan prioritas yang konsisten. Sebagai contoh, elemen dengan nilai numerik akan memiliki prioritas yang lebih tinggi daripada elemen dengan nilai numerik yang lebih kecil[3]. 


**2. Pop()**

Pop() digunakan untuk menghapus elemen dengan prioritas tertinggi. Fungsi perbandingan, yang membandingkan nilai prioritas dua elemen dalam antrian, menetapkan elemen dengan prioritas tertinggi. Setelah elemen dengan prioritas tertinggi dihapus, elemen dengan prioritas selanjutnya akan diubah menjadi elemen dengan prioritas tertinggi, dan seterusnya. Proses ini dilanjutkan sampai antrian kosong atau tidak ada lagi elemen dalamnya[3].

**3. Size()**

Size() digunakan untuk menghitung jumlah elemen yang saat ini ada dalam antrian. Nilai akan dikembalikan oleh operator ini dengan tipe data integer, yang menunjukkan jumlah elemen yang ada dalam priority queue[3].

**4. Empty()**

Empty digunakan untuk mengetahui apakah antrian prioritas kosong atau tidak. Jika antrian saat ini dalam keadaan kosong, operasi pop tidak akan dapat dilakukan, dan jika sebaliknya, operasi push tidak akan dapat dilakukan[3].

**5. Top()**

Top() merujuk pada elemen dengan prioritas tertinggi yang ada dalam priority queue. Karena dalam kebanyakan implementasi, elemen dengan prioritas tertinggi selalu ditempatkan di depan atau di atas elemen lain di dalam priority queue, yang akan dihapus terlebih dahulu dari antrian[3].

**6. Swap()**

Swap() pada priority queue adalah proses menukar posisi dua elemen yang berbeda dalam priority queue. Ini biasanya dilakukan untuk mengubah urutan prioritas dari dua elemen tertentu dalam priority queue[3].

**7. Emplace()**

Emplace() pada queue prioritas memungkinkan untuk menambahkan elemen baru ke dalam priority queue dengan menggunakan nilai yang diberikan untuk membuat elemen baru saat penambahan. Teknik ini serupa dengan metode push, tetapi dengan emplace kita dapat langsung memasukkan nilai yang akan digunakan untuk membuat elemen baru tanpa harus membuat elemen baru terlebih dahulu[3].


### Keunggulan Priority Queue

1. Membantu mendapatkan elemen dengan lebih cepat. Ini karena elemen dalam antrian prioritas diurutkan menurut prioritas, sehingga seseorang dapat dengan mudah mengambil elemen dengan prioritas tertinggi tanpa mencari di seluruh antrian. 2. Pengurutan elemen dalam antrian prioritas dilakukan secara dinamis. Ini memungkinkan antrian untuk mengurutkan ulang secara dinamis saat prioritas berubah.
3. Ada kemungkinan untuk menerapkan algoritma yang efektif. Banyak algoritme, seperti algoritme Djikstra untuk menemukan jalur terpendek di graf dan algoritme pencarian A* untuk pencarian jalur, menggunakan antrean prioritas untuk meningkatkan efisiensinya.
4. Termasuk dalam sistem real-time karena memungkinkan elemen dengan prioritas tertinggi diambil dengan cepat melalui antrean prioritas. Antrean ini sering digunakan dalam sistem waktu nyata, di mana waktu sangat penting.

### Kekurangan Priority Queue
1. Tingkat kompleksitas tinggi. Antrean prioritas lebih kompleks dan mungkin lebih sulit untuk diterapkan dan dipelihara daripada struktur data sederhana seperti larik dan daftar tertaut.
2. Penggunaan memori yang tinggi Untuk sistem dengan sumber daya terbatas, menyimpan nilai prioritas untuk setiap elemen dalam antrian prioritas dapat menghabiskan memori tambahan.
3: Itu mungkin bukan struktur data yang paling efektif. Untuk tugas tertentu, seperti menemukan elemen minimum atau maksimum dalam antrean, struktur data lain seperti tumpukan atau pohon pencarian biner mungkin lebih efektif.
4. Terkadang kurang dapat diprediksi: Ini karena urutan elemen dalam antrean prioritas ditentukan oleh nilai prioritas mereka. Jika dibandingkan dengan struktur data lain seperti tumpukan atau antrean, yang mengikuti first-in,  first-out (FIFO) atau last-in, first-out (LIFO), urutan pengambilan elemen mungkin kurang dapat diprediksi. 

#### Contoh Program

Source code
```C++
#include <iostream>
#include <queue>

using namespace std;

// Struktur data untuk menyimpan elemen priority queue
struct Elemen {
    int nilai;
    string nama;
};

// Fungsi untuk membandingkan dua elemen berdasarkan nilai
bool operator<(const Elemen& a, const Elemen& b) {
    return a.nilai < b.nilai;
}

int main() {
    // Deklarasi priority queue
    priority_queue<Elemen> pq;

    // Menambahkan elemen ke priority queue
    pq.push({10, "Haha"});
    pq.push({5, "Hihi"});
    pq.push({15, "Hehe"});
    pq.push({8, "Hoho"});

    // Menampilkan isi priority queue
    cout << "Isi priority queue:" << endl;
    while (!pq.empty()) {
        Elemen elemen = pq.top();
        cout << "Nilai: " << elemen.nilai << ", Nama: " << elemen.nama << endl;
        pq.pop();
    }

    return 0;
}
```

#### Output
![Screenshot 2024-06-21 181919](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/e0c26dc2-9c9e-4600-83c5-5dbaa4eb2f89)

#### Interpretasi
Untuk mengelola elemen yang terdiri dari pasangan nilai integer dan string nama, program ini menggunakan `priority_queue`. Priority queue membandingkan nilai integer setiap elemen yang ditambahkan dengan operator "<" overload. Akibatnya, elemen dengan nilai terbesar diatur sebagai prioritas tertinggi. Program membuat queue prioritas terdiri dari empat elemen, masing-masing dengan nama dan nilai unik. Elemen dengan nilai tertinggi ditampilkan terlebih dahulu saat menampilkan dan menghapus elemen dari queue prioritas. Hasilnya menunjukkan elemen dengan nilai tertinggi hingga terendah. Elemen dengan nilai 15 disebut "Hehe", elemen dengan nilai 10 disebut "Haha", elemen dengan nilai 8 disebut "Hoho", dan elemen dengan nilai 5 disebut "Hihi". Output menunjukkan bahwa queue prioritas mengurutkan elemen berdasarkan nilai tertinggi dengan benar.

## Hash Table

### Pengertian Hash Table

Tabel hash adalah struktur data yang digunakan untuk penyimpanan data sementara dengan tujuan untuk mempercepat pencarian kembali dari sejumlah besar data yang telah disimpan. Karena teknik penyimpanan mereka, waktu yang dibutuhkan untuk penambahan data (insertions), penghapusan data (deletions), dan pencarian data (searching) hampir sama dengan struktur data atau algoritma yang lain[4].  

Sebuah tabel hash terdiri dari dua bagian: sebuah larik atau array dan sebuah fungsi untuk memetakan. Fungsi hash adalah pemetaan ke dalam larik sesuai dengan kunci-kunci yang diberikan, atau dengan kata lain, fungsi hash mendistribusikan data yang dimasukkan oleh pengguna ke dalam tabel atau larik yang telah disediakan[5].

Sistem hash table menggunakan fungsi hash untuk mengambil input kunci dan memetakkannya ke nilai indeks array. Kemudian, fungsi hash menghasilkan posisi indeks array, dan ketika data perlu dicari, input kunci dijadikan parameter untuk fungsi hash, dan posisi indeks array yang dihasilkan digunakan untuk mencari data. Dalam situasi di mana dua atau lebih data memiliki nilai hash yang sama, hash table menyimpan data tersebut dalam slot yang sama. Teknik yang disebut chaining adalah cara untuk melakukan ini dalam kasus di mana hash collision terjadi.

![image](https://github.com/rennanvra/Praktikum-Algoritma-dan-Strukdat/assets/162097323/8fe07a8d-cb5a-46dd-968e-d6ab70952c9f)

Sebuah fungsi hashing yang bagus memiliki dua kriteria yakni harus dapat cepat dihitung dan harus meminimalkan terjadinya collisoin. Collision adalah jika dua buah key atau lebih di petakan pada sel data yang sama. Ada dua strategi umum untuk meminimalisir terjadinya collision yakni Close Hashing(Opening Addres) dan Open Hashing(Chaining).

### Collision 
Ketika dua atau lebih data memiliki hash index yang sama, itu disebut collision. Sebagaimana diketahui, satu alamat atau index array hanya dapat menyimpan satu data [4]. Namun, dalam situasi tertentu, ketika beberapa kunci memetakan data ke dalam integer yang sama, elemen-elemen tersebut akan disimpan pada slot yang sama pada tabel hash [5].

### cara Mengatasi Collision
**a. Closed Hashing (Open Addressing)**

Close hashing menyelesaikan collision dengan menggunakan memori yang masih ada tanpa menggunakan memori di luar array yang dipakai. Closed hashing mencari alamat lain apabila alamat yang akan dituju sudah terisi oleh data. Terdapat tiga cara untuk mencari alamat lain tersebut, yaitu linear probing, quadratic probing, dan double hashing[4]

- Linear Probing (Metode Pembagian)
    
    Linear probing mencari alamat lain dengan mengubah satu indeks dari alamat sebelumnya hingga menemukan alamat data yang belum terisi, rumusnya adalah[5]:

    ![image](https://github.com/rennanvra/Praktikum-Algoritma-dan-Strukdat/assets/162097323/a2a4036f-8453-4483-a9bb-260b958b9666)


- Quadratic Probing (Metode Midsquare/Nilai Tengah)

    Proses perhitungan kuadratik yang lebih kompleks mencari lokasi baru. Quadratic probing ini tidak memiliki formula yang jelas [4].

- Double Hashing (Metode Penjumlahan Digit) 

    Seperti namanya, hash function lagi digunakan untuk mendapatkan alamat baru untuk menyimpan data yang tidak dapat dimasukkan ke dalam tabel. Hash function kedua, yang digunakan setelah alamat yang dihasilkan oleh hash function pertama telah terisi, tentu saja berbeda dengan hash function awal [4].

Kelemahan metode closed hashing adalah bahwa ukuran array harus lebih besar dari jumlah data dan membutuhkan lebih banyak memori untuk meminimalkan collision. Metode ini memungkinkan untuk membagi kunci yang dikenal menjadi beberapa kelompok. Jika total kelompok yang ada masih lebih besar dari jumlah alamat yang akan digunakan, pemecahan dan penjumlahan akan terus dilakukan [4].

**b. Open Hashing (Separate Chaining)**

Pada dasarnya, open hashing atau separate chaining, membuat tabel yang digunakan untuk hashing menjadi sebuah array pointer dengan masing-masing pointer diikuti oleh sebuah daftar yang terhubung, dengan rantai (atau mata rantai) 1 terletak pada array pointer, dan rantai 2 dan seterusnya berhubungan dengan rantai 1 secara memanjang. Jika data ditumpuk pada satu atau lebih indeks, akan terjadi daftar terkait yang panjang [4].

### Operasi Hash Table
- Insertion: Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash untuk menentukan posisi bucket yang tepat, dan kemudian menambahkan data ke bucket tersebut.
- Deletion: Menghapus data dari hash table dengan mencari data menggunakan fungsi hash, dan kemudian menghapusnya dari bucket yang sesuai.
- Searching: Mencari data dalam hash table dengan memasukkan input kunci ke fungsi hash untuk menentukan posisi bucket, dan kemudian mencari data di dalam bucket yang sesuai.
- Update: Memperbarui data dalam hash table dengan mencari data menggunakan fungsi hash, dan kemudian memperbarui data yang ditemukan.
- Traversal: Melalui seluruh hash table untuk memproses semua data yang ada dalam tabel.

#### Contoh Program

Source code
```C++
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // Deklarasi hash table
    unordered_map<string, int> hashTable;

    // Menambahkan elemen ke hash table
    hashTable["Haha"] = 20;
    hashTable["Hihi"] = 30;
    hashTable["Hehe"] = 40;
    hashTable["Hoho"] = 50;

    // Menampilkan isi hash table
    cout << "Isi hash table:" << endl;
    for (auto& elemen : hashTable) {
        cout << "Nama: " << elemen.first << ", Nilai: " << elemen.second << endl;
    }

    // Mencari elemen di hash table
    string nama = "Hihi";
    if (hashTable.find(nama)!= hashTable.end()) {
        cout << "Nama " << nama << " ditemukan dengan nilai " << hashTable[nama] << endl;
    } else {
        cout << "Nama " << nama << " tidak ditemukan" << endl;
    }

    // Menghapus elemen dari hash table
    hashTable.erase("Hehe");
    cout << "Isi hash table setelah dihapus:" << endl;
    for (auto& elemen : hashTable) {
        cout << "Nama: " << elemen.first << ", Nilai: " << elemen.second << endl;
    }

    return 0;
}
```

#### Output
![Screenshot 2024-06-21 182109](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/d63d951b-45ab-423a-aa52-760581708a39)


#### Interpretasi
Untuk menerapkan hash table yang menyimpan pasangan nilai string dan integer, program ini menggunakan "unordered_map" dalam C++. Pertama, hash table diisi dengan beberapa elemen dengan nama dan nilai angka. Program kemudian menampilkan seluruh isi hash table, di mana setiap elemen dicetak dengan format "Nama:..., Nilai:...". Kemudian, program mencari elemen dengan nama "Hihi" dan mencetak hasil pencarian, menunjukkan apakah elemen ditemukan bersama nilainya. Selanjutnya, elemen dengan nama "Hehe" dihapus dari hash table, dan isi hash table ditampilkan kembali untuk mence Pasangan nama dan nilai sebelum dan sesudah penghapusan, serta hasil pencarian elemen dengan nama tertentu, ditampilkan dalam output program.


## Rekursif

### Pengertian Rekursif

Rekursi adalah proses perulangan untuk menyelesaikan suatu masalah yang didasarkan pada hubungan rekurens (recurrence relation)[6]. Oleh karena itu, rekursi adalah teknik pemrograman di mana metode atau fungsi memanggil dirinya sendiri. Menghitung nilai faktorial dari bilangan bulat positif dan menemukan deret Fibonacci dari suatu bilangan bulat adalah dua contoh paling sederhana dari fungsi rekursi, di mana ada dua blok penting: blok yang menjadi titik berhenti dari proses rekursi dan blok yang memanggil dirinya sendiri [7].

Ilustrasi bagaimana rekursif berjalan:

![image](https://github.com/rennanvra/Praktikum-Algoritma-dan-Strukdat/assets/162097323/6dec81b3-45a1-4ea3-ad56-20e050920d38)

### Jenis-Jenis Rekursi
- Rekursif langsung : fungsi memanggil dirinya sendiri secara langsung.
- Rekursif tidak langsung : jika sebuah fungsi memanggil dirinya sendiri secara tidak langsung dari fungsi lain.

### Kelemahan Rekursif
- Stack Overflow dan Konsumsi Memori
- Pertimbangan Kinerja
- Analisis Kompleksitas dan Teknik Optimasi

#### Contoh Program

Source code
```C++
#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    if (n == 0) {
        return 1; // basis kasus: faktorial 0 adalah 1
    } else {
        return n * faktorial(n-1); // rekursif: faktorial n adalah n dikali faktorial n-1
    }
}

int main() {
    int bilangan;
    cout << "Masukkan bilangan: ";
    cin >> bilangan;

    int hasil = faktorial(bilangan);
    cout << "Faktorial " << bilangan << " adalah " << hasil << endl;

    return 0;
}
```

#### Output
![Screenshot 2024-06-21 182214](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/24171929-122d-49a4-89db-8aa0279318eb)


#### Interpretasi
Program ini menggunakan fungsi rekursif untuk menghitung faktorial dari sebuah bilangan. Saat program dijalankan, pengguna diminta untuk memasukkan sebuah bilangan. Selanjutnya, bilangan yang dimasukkan sebagai argumen digunakan untuk menggambarkan fungsi rekursif "faktorial". Fungsi faktorial mendefinisikan basis kasus di mana faktorial dari 0 adalah 1. Untuk setiap nilai di atas 0, fungsi memanggil dirinya sendiri dengan nilai yang dikurangi 1 dan mengalikan hasilnya dengan nilai saat ini. Prosedur ini dilakukan secara rekursif hingga mencapai basis kasus. Program menampilkan hasil faktorial kepada pengguna dalam format "Faktorial [bilangan] adalah [hasil]" setelah perhitungan selesai. Misalnya, program akan menghitung 5! = 5 * 4 * 3 * 2 * 1 = 120 dan mencetak "Faktorial 5 adalah 120."


## Graph & Tree

## Pengertian Graph&Tree
Graf adalah sekumpulan node (simpul) yang terletak dalam bidang dua dimensi dan terhubung oleh garis-garis (sisi). Graf ini digunakan untuk merepresentasikan objek-objek diskret serta hubungan antar objek tersebut. Dalam representasi visual, objek-objek ini digambarkan sebagai node, bulatan, atau titik (vertex), sedangkan hubungan antar objek digambarkan dengan garis (edge)[4].

![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/a7429719-aa7d-4aae-9bd1-b71ea13123b5)

```
Keterangan:
G = graph
V = simpul atau titik (vertex atau node)
E = busur atau edge, atau arc
```

Jalur pada graph dituliskan sebagai berikut:

![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/f945b29f-f2c9-4e81-aebf-874c84524f23)

```
Keterangan:
P = jalur
Vi = titik jalur
n = jumlah titik jalur
```

## Istilah pada Graph

1. Vertex

Vertex yaitu himpunan node/titik pada sebuah graph[4].

2. Edge

Edge yaitu himpunan garis yang menghubungkan tiap node/vertex[4].

3. Adjacent

Dua buah titik dikatakan berdekatan (adjacent) jika keduanya terhubung dengan sebuah sisi[4].

4. Weight

Sebuah graph G = (V, E) disebut sebuah graph berbobot (weight graph) apabila terdapat sebuah fungsi bobot bernilai real W pada himpunan E[4].

W : E -> R

Nilai W(e) disebut bobot untuk sisi e, ∀ e ∈ E. Graph berbobot tersebut dinyatakan pula sebagai: G = (V, E, W).Graph berbobot G = (V, E, W) dapat menyatakan:

Suatu sistem perhubungan udara, di mana:

V = himpunan kota-kota

E = himpunan penerbangan langsung dari satu kota ke kota lain

W = fungsi bernilai real pada E yang menyatakan jarak atau ongkos atau waktu

Suatu sistem jaringan komputer, di mana:

V = himpunan komputer

E = himpunan jalur komunikasi langsung antar dua komputer

W = fungsi bernilai real pada E yang menyatakan jarak atau ongkos atau waktu

5. Path

Path adalah jalur dengan setiap vertex berbeda. Contoh: P = D5B4C2A. Sebuah jalur (W) didefinisikan sebagai urutan (tidak nol) vertex dan edge. Diawali origin vertex (vertex awal) dan diakhiri terminus vertex (vertex akhir). Dan, setiap dua garis berurutan adalah series. Contoh: W = A1B3C4B1A2[4].

6. Cycle

Cycle (siklus) atau circuit (sirkuit) merupakan lintasan yang berawal dan berakhir pada simpul yang sama[4].

## Jenis-Jenis Graph

1. Graf Tak Berarah (Undirected graph)

Graf tak berarah adalah graf yang sisinya tidak memiliki orientasi arah. Pada graf tak berarah, urutan pasangan simpul yang dihubungkan oleh sisi tidak diperhatikan[8]. 

![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/2c5129fb-865d-43be-84ab-54e697708f89)
 

2. Graf Berarah (Directed graph)

Graf berarah adalah graf yang memiliki orientasi arah di setiap sisinya. Dalam diagram ini, sisi berarah disebut busur (arc). Dibandingkan dengan graf tak-berarah, urutan pasangan simpul sangat diperhatikan di sini karena dapat menunjukkan hal yang berbeda. (vj,vk) dan (vk,vj) menyatakan dua buah busur pada graf berarah[8].

![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/b1eb91cf-191e-487b-acee-a5b64a21c47e)

3. Graph Berbobot (Weighted Graph)

Bobot sebuah busur dapat menunjukkan panjang sebuah jalan dari dua titik, jumlah kendaraan rata-rata per hari yang melalui sebuah jalan, dan sebagainya jika setiap busur memiliki nilai yang menunjukkan hubungan antara dua simpul[4].

![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/871b7ca9-da63-4805-9a4c-b7ebd3881851)


### Pengertian Tree

Struktur pohon(tree), atau data tree, adalah struktur yang penting yang mengharuskan kita mengorganisasikan informasi dengan struktur lojik. Struktur pohon juga memungkinkan akses ke elemen tertentu [9]. Struktur data tidak linear atau non linear, seperti tree, digunakan terutama untuk menunjukkan hubungan data hierarkis antara elemen-elemennya[9].

![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/0225666e-807b-42b8-b325-9fddb92655a9)

### Implementasi Teori Pohon

Berikut adalah beberapa contoh implementasi teori pohon, yang merupakan salah satu opsi terbaik untuk struktur data yang pernah ada, dan setiap implementasi pasti akan menjadi yang terbaik dalam situasi tertentu[10].

1. Binary Search Tree

Sebuah pohon biner dengan properti tambahan. Properti berikut adalah:

- Semua elemen pada upapohon (subpohon) kiri nilainya lebih kecil atau sama dengan nilai akar.
- Semua elemen pada upapohon kanan nilainya lebih besar dari nilai akar.
- Upapohon kiri dan kanan merupakan Binary Search Tree.

2. AVL-Tree (The Height Balance Tree)

AVL-Tree adalah Binary Search Tree dengan upapohon kiri dan kanan dari akar tidak akan berselisih lebih dari satu. AVL-Tree juga merupakan AVL-Tree sendiri, dan setiap simpul di AVL-Tree memiliki faktor keseimbangan yang bernilai lebih tinggi (upapohon kiri lebih tinggi dari kanan), sama tinggi (upapohon kiri lebih rendah dari kanan), dan lebih rendah (upapohon kiri lebih rendah dari kanan)[10].

3. Splay-Tree (The Self-Adjusting Tree)

Splay-Tree adalah salah satu modifikasi binary search tree yang dibuat dengan tujuan khusus. Tujuan utama dari gagasan splay-tree ini adalah untuk membuat pencarian dan pengambilan data lebih mudah, terutama data yang paling sering diakses atau diubah.

Splay-tree berbeda dengan binary search tree dan AVL-Tree karena data baru atau frekuensi akses tinggi berada dekat dengan akar pohon sehingga tidak membutuhkan waktu yang lama untuk mengaksesnya dibandingkan dengan binary search tree dan AVL-Tree yang membuat kita harus menelusuri pohon sampai ke daun karena data baru ditempatkan sebagai daun[10].


### Operasi pada Tree

a. Create: digunakan untuk membentuk binary tree baru yang masih kosong.

b. Clear: digunakan untuk mengosongkan binary tree yang sudah ada atau menghapus semua node pada binary tree.

c. isEmpty: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.

d. Insert: digunakan untuk memasukkan sebuah node kedalam tree.

e. Find: digunakan untuk mencari root, parent, left child, atau right child dari suatu node dengan syarat tree tidak boleh kosong.

f. Update: digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong.

g. Retrive: digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.

h. Delete Sub: digunakan untuk menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.

i. Characteristic: digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.

j. Traverse: digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yakni Pre-Order, In-Order, dan Post-Order.

#### Contoh Program

Source code
```C++
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int nilai;
    vector<Node*> anak;
    vector<Node*> tetangga; // untuk graph

    Node(int nilai) {
        this->nilai = nilai;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() {
        root = nullptr;
    }

    void tambahNode(int nilai) {
        if (root == nullptr) {
            root = new Node(nilai);
        } else {
            tambahNodeRekursif(root, nilai);
        }
    }

    void tambahNodeRekursif(Node* node, int nilai) {
        if (nilai < node->nilai) {
            if (node->anak.size() < 1) {
                node->anak.push_back(new Node(nilai));
            } else {
                tambahNodeRekursif(node->anak[0], nilai);
            }
        } else {
            if (node->anak.size() < 2) {
                if (node->anak.size() == 1) {
                    node->anak.push_back(new Node(nilai));
                } else {
                    node->anak.push_back(nullptr);
                    node->anak.push_back(new Node(nilai));
                }
            } else {
                tambahNodeRekursif(node->anak[1], nilai);
            }
        }
    }

    void tambahEdge(Node* node1, Node* node2) {
        node1->tetangga.push_back(node2);
        node2->tetangga.push_back(node1);
    }

    void cetakTree() {
        cetakTreeRekursif(root);
    }

    void cetakTreeRekursif(Node* node) {
        if (node != nullptr) {
            cout << node->nilai << " ";
            for (Node* child : node->anak) {
                cetakTreeRekursif(child);
            }
        }
    }

    void cetakGraph() {
        cetakGraphRekursif(root);
    }

    void cetakGraphRekursif(Node* node) {
        if (node != nullptr) {
            cout << "Node " << node->nilai << " terhubung dengan: ";
            for (Node* neighbor : node->tetangga) {
                cout << neighbor->nilai << " ";
            }
            cout << endl;
            for (Node* child : node->anak) {
                cetakGraphRekursif(child);
            }
        }
    }

    Node* findNode(int nilai) {
        return findNodeRekursif(root, nilai);
    }

    Node* findNodeRekursif(Node* node, int nilai) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->nilai == nilai) {
            return node;
        }

        for (Node* child : node->anak) {
            Node* found = findNodeRekursif(child, nilai);
            if (found != nullptr) {
                return found;
            }
        }

        return nullptr;
    }
};

int main() {
    Tree tree;

    tree.tambahNode(5);
    tree.tambahNode(3);
    tree.tambahNode(7);
    tree.tambahNode(2);
    tree.tambahNode(4);
    tree.tambahNode(6);
    tree.tambahNode(8);

    Node* node2 = tree.findNode(2);
    Node* node4 = tree.findNode(4);
    Node* node3 = tree.findNode(3);
    Node* node6 = tree.findNode(6);
    Node* node5 = tree.findNode(5);
    Node* node7 = tree.findNode(7);
    Node* node8 = tree.findNode(8);

    tree.tambahEdge(node2, node4);
    tree.tambahEdge(node3, node6);
    tree.tambahEdge(node5, node7);
    tree.tambahEdge(node7, node8);

    cout << "Tree: ";
    tree.cetakTree();
    cout << endl;

    cout << "Graph: " << endl;
    tree.cetakGraph();

    return 0;
}
```

#### Output
![Screenshot 2024-06-21 183459](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/efa87e6a-6cc6-49c8-937a-b03c98c440c4)


#### Interpretasi
Dengan menggunakan kelas "Node" dan "Tree", program ini menjalankan struktur data pohon biner dan graf. Setiap simpul (Node) memiliki nilai, anak-anak (untuk pohon) dan tetangga (untuk graf). Program menambahkan nilai tertentu ke pohon dan mengatur posisinya berdasarkan nilai tersebut. Selain itu, program membentuk graf dengan menambahkan tepi antar simpul. Setelah menambahkan beberapa tepi dan simpul, program mencetak struktur pohon dan graf. Sementara pohon dicetak dalam urutan nilai, graf dicetak dengan menyatakan simpul yang terhubung satu sama lain. Hasilnya menunjukkan struktur pohon dengan urutan nilai 5, 3, 2, 4, 7, 6, 8 dan graf dengan simpul yang terhubung sesuai dengan tepi yang ditambahkan.


### Referensi
[1] Sholeh, I. (2021). Penerapan Decrease And Conquer Untuk Memanajemen Tugas Kuliah Informatika. JURNAL TEKNIK INFORMATIKA DAN SISTEM INFORMASI, 1(2), 1-10.

Available : https://jurtisi.stmikmpb.ac.id/index.php/jurtisi/article/view/13/1 

[2] Nurhadi, M. I., Saputra, R. E., & Setianingsih, C. (2021). Manajemen Dan Kendali Beban Perangkat Elektronik Berbasis Web Dengan Algoritma Priority Queue. eProceedings of Engineering, 8(2).

Available : file:///C:/Users/User/Downloads/14605-Article%20Text-28216-1-10-20210507%20(3).pdf 

[3] B. B. Pangestu, G. S. H. Barata, E. W. Lay, dan M. Alghifari, "Makalah Priority Queue Revisi," FAKULTAS TEKNIK UNIVERSITAS TANJUNGPURAPONTIANAK, 2023.

Available : https://www.scribd.com/document/657230171/Makalah-Priority-Queue-revisi 

[4] Yazdani, Rinaldi Munir. "Cara Mudah Mempelajari Algoritma dan Struktur Data." Jakarta: PT. Elex Media Komputindo, 2019.

Available: https://repository.mercubuana.ac.id/80729/1/Cara%20Mudah%20Mempelajari%20Algoritma%20dan%20Struktur%20Data.pdf

[5] J. Prestiliano. Aplikasi Tabel Hash dalam Pengarsipan dan Pencarian Data. Fakultas Teknologi Informasi Universitas Kristen Satya Wacana, 2019.

Available: (https://repository.uksw.edu/bitstream/123456789/1012/2/ART_Jasson%20Prestiliano_Aplikasi%20tabel%20hash_Full%20text.pdf).

[6] A. Sutrisno, "Pengembangan Sistem Informasi Akademik," Tesis, Departemen Teknik Informatika, Universitas Islam Negeri Sultan Syarif Kasim Riau, Pekanbaru, Indonesia, 2010.

Available: https://repository.uin-suska.ac.id/10894/1/2010_2010111TIF.pdf

[7] A. Firdaus dan B. Lestari, "Analisis Faktor-faktor yang Mempengaruhi Kepuasan Pelanggan di Pasar Online," Tesis, Departemen Manajemen, Universitas Islam Negeri Maulana Malik Ibrahim, Malang, Indonesia, 2024.

Available: http://repository.uin-malang.ac.id/15252/7/15252.pdf

[8] Anggara, F. D. (2009). Studi dan Implementasi Struktur Data Graf. Jurnal Sekolah Teknik Elektro dan Informatika Institut Teknologi Bandung, Bandung.

Available: (https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2008-2009/Makalah2008/Makalah0809-097.pdf)

[9] Agustin, S., Permana, A. Y., Fazri, H. N., Robi, M., & Firmansyah, R. (2022). IMPLEMENTASI STRUKTUR DATA TREE PADA WEB BLOG SEBAGAI MEDIA PEMBELAJARAN. Jurnal Informatika Dan Tekonologi Komputer (JITEK), 2(2), 206-212.

Available: (https://journal.amikveteran.ac.id/index.php/jitek/article/view/316/251).

[10] Akbar, K. S. R. (2006). Penerapan Teori Pohon Dalam Kajian Struktur Data. Insitut Teknologi Bandung.

Available: (https://informatika.stei.itb.ac.id/~rinaldi.munir/Matdis/2006-2007/Makalah/Makalah0607-24.pdf).