# <h1 align="center">EVALUASI CPMK SEMESTER GENAP</h1>
<p align="center">Renna Novaria W - S1SD 04A - 2311110047</p>

### CPMK 2 - SubCPMK 2
1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

    **Jawab:** 
    
    a. Bubble Sort
    
    **Alur**
    
    Bubble Sort adalah algoritma sorting yang sangat sederhana di mana setiap elemen dalam array dibandingkan dengan elemen tetangganya dan ditukar jika berada dalam urutan yang salah. Proses ini diulangi sampai tidak ada lagi pertukaran yang diperlukan, yang berarti array sudah diurutkan.

    1. Mulai dari elemen pertama dalam array.

    2. Bandingkan elemen saat ini dengan elemen berikutnya.

    3. Jika elemen saat ini lebih besar dari elemen berikutnya, tukar keduanya.

    4. Pindah ke elemen berikutnya dan ulangi langkah 2-3 hingga akhir array.

    5. Ulangi langkah 1-4 untuk n-1 iterasi, di mana n adalah panjang array, atau sampai tidak ada pertukaran dalam satu iterasi (menandakan array sudah terurut).
    
    **Runtime**

    1. **Best Case: O(n)** - Ketika elemen sudah terurut dari awal, tidak ada pertukaran yang dilakukan dan algoritma selesai dalam satu iterasi.

    2. **Worst Case: O(n^2)** - Ketika elemen terurut terbalik, algoritma perlu melakukan n iterasi penuh untuk mengurutkan semua elemen.
    
    b. Selection Sort
    
    **Alur**
    
    Selection Sort adalah algoritma yang berfungsi dengan membagi array menjadi dua bagian: bagian yang diurutkan dan bagian yang tidak diurutkan. Algoritma ini berulang kali memilih elemen terkecil dari bagian yang tidak diurutkan dan memindahkannya ke akhir bagian yang diurutkan.

    1. Mulai dari elemen pertama dalam array.

    2. Temukan elemen terkecil dalam subarray yang tidak diurutkan.

    3. Tukar elemen terkecil dengan elemen pertama dari subarray yang tidak diurutkan.

    4. Pindah ke elemen berikutnya dan ulangi langkah 2-3 hingga seluruh array terurut.
    
    **Runtime**

    1. **Best Case: O(n)** - Ketika elemen sudah terurut dari awal, elemen terkecil selalu berada di posisi yang benar dan tidak ada pertukaran yang dilakukan.

    2. **Worst Case: O(n^2)** - Ketika elemen teracak, algoritma perlu melakukan n iterasi penuh untuk menemukan elemen terkecil dan menukarnya dengan elemen pertama.
    
    c. Merge Sort
    
    **Alur**
    
    Merge Sort adalah algoritma berbasis divide-and-conquer yang membagi array menjadi dua bagian lebih kecil, mengurutkan setiap bagian secara rekursif, dan kemudian menggabungkan (merge) bagian-bagian tersebut untuk membentuk array yang diurutkan.

    1. Jika array memiliki satu elemen atau kurang, kembalikan array tersebut (basis rekursi).

    2. Bagi array menjadi dua subarray sekitar titik tengah.

    3. Urutkan masing-masing subarray dengan memanggil Merge Sort secara rekursif.

    4. Gabungkan dua subarray yang diurutkan menjadi satu array yang diurutkan.
    
    **Runtime**

    1. **Best Case: O(n log n)** - Ketika elemen sudah terurut dari awal, penggabungan dua bagian yang sudah terurut dapat dilakukan dengan cepat.

    2. **Worst Case: O(n log n)** - Ketika elemen teracak, algoritma perlu melakukan pembagian dan penggabungan secara rekursif untuk mengurutkan semua elemen.
    
2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut!

    #### Source code:
    ```C++
    #include <iostream>
    using namespace std;

    // Mengurutkan secara ascending untuk data bertipe numerik bertipe double menggunakan Algoritma Bubble Sort
    void bubble_sort(double arr[], int length) {
        bool not_sorted = true;
        int j=0;
        double tmp;

        while (not_sorted) {
            not_sorted = false;
            j++;
            for (int i = 0; i < length - j; i++){
                if (arr[i] > arr[i + 1]) {
                    tmp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i + 1] = tmp;
                    not_sorted = true;
                }// end of if
            }// end of for loop
        }//end of while loop
    }// end of bubble_sort

    void print_array(double a[], int length) {
        for(int i=0; i<length; i++) {
            cout << a[i] << "\t";
        }
        cout << endl;
    }

    int main() {
        int length = 5;
        double a[] = {10.2, 18.3, 5.2, 39.21, 93.99};

        cout << "Urutkan bilangan sebelum sorting: " << endl;
        print_array(a, length);

        bubble_sort(a, length);

        cout << "\nUrutkan bilangan setelah sorting: " << endl;
        print_array(a, length);
    }
    ```

    #### Output

    ![Screenshot 2024-05-14 191545](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/cd5af56e-b1b4-4595-a1f7-3276f1d0a828)

    #### Interpretasi

    Program di atas adalah contoh dari algoritma Bubble Sort. Program ini mengurutkan array 'a' yang berisi data numerik yang bertipe double secara ascending (terkecil ke terbesar). Pada program tersebut terdapat perulangan `while` dan `for` untuk membandingkan tiap iterasi dan ditukar atau diurutkan. Fungsi `bubble_sort` melakukan pengurutan dengan membandingkan setiap elemen yang berdekatan dan menukarnya jika tidak berada dalam urutan yang benar. Jika tidak, pengurutan dianggap selesai. Variabel `not_sorted` digunakan untuk mengetahui apakah ada pertukaran dalam iterasi tertentu. Array yang telah diurutkan dicetak kembali setelah memanggil `bubble_sort`. Kemudian akan mencetak array sebelum diurutkan dan sesudah diurutkan.

3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 

    #### Source code:
    ```C++
    #include <iostream>
    #include <algorithm>
    #include <string>

    using namespace std;

    // Fungsi untuk mengecek apakah dua string merupakan anagram
    bool areAnagrams(string str1, string str2) {
        // Jika panjang string berbeda, pasti bukan anagram
        if (str1.length() != str2.length()) {
            return false;
        }
        
        // Mengurutkan kedua string
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        
        // Membandingkan kedua string yang sudah diurutkan
        return (str1 == str2);
    }

    int main() {
        string string1, string2;

        // Meminta input dari pengguna
        cout << "Masukkan string pertama: ";
        cin >> string1;
        cout << "Masukkan string kedua: ";
        cin >> string2;
        
        // Mengecek apakah kedua string merupakan anagram dan mencetak hasilnya
        if (areAnagrams(string1, string2)) {
            cout << "Kedua kata tersebut: anagram" << endl;
        } else {
            cout << "Kedua kata tersebut: tidak anagram" << endl;
        }
        
        return 0;
    }
    ```

    #### Output

    ![Screenshot 2024-05-14 200003](https://github.com/rennanvra/Praktikum-3/assets/162097323/d0cc969b-0ad8-4e78-8be0-cb1d3740e487)

    #### Interpretasi

    Program di atas adalah implementasi fungsi untuk memeriksa apakah dua string yang dimasukkan oleh pengguna merupakan anagram. Pertama, dua string dibaca dari input pengguna. Fungsi areAnagrams kemudian mengecek apakah panjang kedua string sama; jika tidak, langsung mengembalikan false. Jika panjangnya sama, karakter-karakter dalam kedua string diurutkan dan dibandingkan. Jika kedua string yang sudah diurutkan tersebut sama, fungsi mengembalikan true, menandakan bahwa kedua string adalah anagram. Hasil ini kemudian dicetak ke layar dengan pesan yang sesuai: "Kedua kata tersebut: anagram" jika mereka adalah anagram, atau "Kedua kata tersebut: tidak anagram" jika bukan.

4.	Tulislah sebuah fungsi program dengan asumsi sebagai berikut: Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut!

    #### Source code:
    ```C++
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    // Fungsi untuk menggabungkan dan mengurutkan dua array terurut
    vector<int> mergeAndSortArrays(const vector<int>& A, const vector<int>& B) {
        // Membuat salinan dari array A
        vector<int> mergedArray = A;

        // Menggabungkan array B ke dalam salinan array A
        mergedArray.insert(mergedArray.end(), B.begin(), B.end());

        // Mengurutkan salinan array A setelah penggabungan
        sort(mergedArray.begin(), mergedArray.end());

        return mergedArray;
    }

    int main() {
        // Array terurut A dengan ruang tambahan
        vector<int> A = {1, 3, 5, 7, 9};

        // Array terurut B
        vector<int> B = {2, 4, 6, 8, 10};

        // Menggabungkan dan mengurutkan array B ke array A
        vector<int> mergedArray = mergeAndSortArrays(A, B);

        // Menampilkan array A
        cout << "Array A: ";
        for (int num : A) {
            cout << num << " ";
        }
        cout << endl;

        // Menampilkan array B
        cout << "Array B: ";
        for (int num : B) {
            cout << num << " ";
        }
        cout << endl;

        // Menampilkan gabungan array
        cout << "Gabungan Array: ";
        for (int num : mergedArray) {
            cout << num << " ";
        }
        cout << endl;

        return 0;
    }
    ```

    #### Output

    ![Screenshot 2024-05-14 201425](https://github.com/rennanvra/Praktikum-3/assets/162097323/a6d17183-0354-4c7f-8a33-9cbe2bcd34ef)

    #### Interpretasi

    Program di atas adalah implementasi dalam bahasa C++ untuk menggabungkan dua array terurut A dan B menjadi satu array terurut, lalu menampilkannya. Fungsi `mergeAndSortArrays` mengambil dua vektor `A` dan `B`, membuat salinan dari array A, menggabungkan array B ke dalam salinan array A, dan mengurutkan salinan array A setelah penggabungan. Di dalam fungsi `main`, dua array terurut A dan B diinisialisasi, kemudian digabungkan dan diurutkan dengan memanggil fungsi `mergeAndSortArrays`. Outputnya akan menampilkan array A, array B, dan gabungan array tersebut.

### CPMK 2 - SubCPMK 3
1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

    **Jawab:** 
    
    a. Binary Search
    
    **Alur**
    
    Dalam binary search, setiap iterasi membagi rentang pencarian menjadi setengahnya, sehingga waktu yang dibutuhkan untuk menemukan elemen akan tumbuh secara logaritmik seiring dengan ukuran array, membuatnya jauh lebih efisien daripada linear search, terutama untuk array yang besar.

    1. Diberikan array terurut, cari elemen tengah array.

    2. Bandingkan elemen tengah dengan elemen yang dicari.

    3. Jika elemen tengah sama dengan elemen yang dicari, kembalikan indeksnya.

    4. Jika elemen yang dicari lebih kecil dari elemen tengah, cari di setengah kiri array.

    5. Jika elemen yang dicari lebih besar dari elemen tengah, cari di setengah kanan array.

    6. Ulangi langkah 2-5 hingga elemen yang dicari ditemukan atau rentang pencarian menjadi kosong.
    
    **Runtime**

    1. **Best Case (Elemen Ditemukan pada Percobaan Pertama)** : O(1) - Algoritma hanya membutuhkan satu kali perbandingan untuk menemukan elemen pada indeks tengah.

    2. **Worst Case (Elemen Tidak Ditemukan)**: O(log n) - Algoritma perlu melakukan pembagian dan penggabungan secara berulang hingga elemen ditemukan atau tidak ditemukan.
    
    b. Linier Search
    
    **Alur**
    
    1. Mulai dari elemen pertama di array.

    2. Lakukan perbandingan antara elemen yang dicari dengan setiap elemen array secara berurutan.

    3. Jika elemen yang dicari ditemukan, kembalikan indeksnya. Jika tidak, lanjutkan ke elemen berikutnya.

    4. Ulangi langkah 2 dan 3 hingga elemen yang dicari ditemukan atau semua elemen telah diperiksa.
    
    **Runtime**

    1. **Best Case (Elemen Ditemukan pada Percobaan Pertama)**: O(1) - Algoritma hanya membutuhkan satu kali perbandingan untuk menemukan elemen pada indeks awal.

    2. **Worst Case (Elemen Tidak Ditemukan)**: O(n) - Algoritma perlu melakukan perbandingan dengan semua elemen dalam array.
    
2.	Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut!

    #### Source code:
    ```C++
    #include <iostream>
    #include <conio.h>
    #include <iomanip>

    using namespace std;

    int cari;

    void selection_sort(int data[], int length) {
        int temp, min, i, j;
        for(i = 0; i < length; i++) {
            min = i;
            for(j = i + 1; j < length; j++) {
                if(data[j] < data[min]) {
                    min=j;
                }
            }
            temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }

    void binarysearch(int data[], int length) {
        int awal, akhir, tengah, b_flag = 0;
        awal = 0;
        akhir = length - 1;
        while (b_flag == 0 && awal <= akhir) {
            tengah = (awal + akhir) / 2;
            if(data[tengah] == cari) {
                b_flag = 1;
                break;
            } else if(data[tengah] < cari)
                awal = tengah + 1;
            else
                akhir = tengah - 1;
        }
        if(b_flag == 1)
            cout<<"\n Data ditemukan pada index ke- " << tengah << endl;
        else
            cout<<"\n Data tidak ditemukan\n";
    }

    int main() {
        int data[7] = {1, 8, 2, 5, 4, 9, 7};
        int length = sizeof(data) / sizeof(data[0]);

        cout << "\t BINARY SEARCH " << endl;
        cout << "\n Data : ";
        // Tampilkan data awal
        for(int x = 0; x<7; x++)
            cout << setw(3) << data[x];
        cout << endl;

        cout << "\n Masukkan data yang ingin Anda cari : ";
        cin >> cari;

        cout << "\n Data diurutkan : ";
        // Urutkan data dengan selection sort
        selection_sort(data, length);

        // Tampilkan data setelah diurutkan
        for(int x = 0; x < 7; x++)
            cout << setw(3) << data[x];
        cout << endl;

        binarysearch(data, length);
        _getche();
        return EXIT_SUCCESS;
    }
    ```

    #### Output

    ![Screenshot 2024-05-14 204326](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/c67971bc-8c9b-4144-a4f2-05ad6cd6dfb1)

    #### Interpretasi

    Program di atas adalah sebuah contoh implementasi algoritma binary search dalam bahasa C++. Program ini memiliki dua bagian utama: pengurutan array menggunakan algoritma selection sort dan pencarian binary search. Pertama, program meminta pengguna untuk memasukkan angka yang ingin dicari dalam array. Kemudian, array yang belum terurut akan diurutkan menggunakan algoritma selection sort, dan hasilnya akan ditampilkan. Setelah itu, program akan melakukan pencarian binary search pada array yang telah diurutkan untuk menemukan angka yang dimasukkan oleh pengguna. Jika angka ditemukan, program akan menampilkan indeksnya. Jika tidak ditemukan, program akan memberikan pesan bahwa angka tersebut tidak ada dalam array.

3.	Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 

    #### Source code:
    ```C++
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    // Fungsi untuk mencari indeks kata yang dicari di dalam array string
    int cariIndeksKata(const vector<string>& arr, const string& kataDicari) {
        int awal = 0;
        int akhir = arr.size() - 1;

        while (awal <= akhir) {
            int tengah = (awal + akhir) / 2;

            // Temukan lokasi pertama kata yang tidak kosong di sebelah kiri
            while (tengah >= 0 && arr[tengah] == "")
                tengah--;

            if (tengah < 0) {
                // Semua elemen di sebelah kiri adalah string kosong
                awal = (awal + akhir) / 2 + 1;
                continue;
            }

            // Bandingkan kata yang dicari dengan kata di tengah
            int hasilPerbandingan = kataDicari.compare(arr[tengah]);

            if (hasilPerbandingan == 0) {
                // Kata ditemukan di tengah array
                return tengah;
            } else if (hasilPerbandingan < 0) {
                // Kata dicari lebih kecil, cari di sebelah kiri
                akhir = tengah - 1;
            } else {
                // Kata dicari lebih besar, cari di sebelah kanan
                awal = tengah + 1;
            }
        }

        // Kata tidak ditemukan dalam array
        return -1;
    }

    int main() {
        vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
        string kataDicari = "bola";

        int indeks = cariIndeksKata(arr, kataDicari);

        if (indeks != -1) {
            cout << "Indeks dari kata \"" << kataDicari << "\" adalah: " << indeks << endl;
        } else {
            cout << "Kata \"" << kataDicari << "\" tidak ditemukan dalam array." << endl;
        }

        return 0;
    }
    ```

    #### Output

    ![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/cc75adde-6af2-46f4-bcad-cd0ee0ca4135)

    #### Interpretasi

    Program di atas adalah sebuah implementasi dalam bahasa C++ untuk mencari indeks dari sebuah kata yang dicari dalam array string yang sudah diurutkan. Fungsi `cariIndeksKata` menggunakan algoritma binary search untuk mencari kata yang dicari di dalam array. Saat menemukan string kosong di tengah array, fungsi akan mencari lokasi pertama kata yang tidak kosong di sebelah kiri. Setelah pencarian selesai, program akan menampilkan indeks dari kata yang dicari jika ditemukan, atau pesan bahwa kata tidak ditemukan dalam array. Dalam contoh yang diberikan, program mencari kata "bola" dalam array yang berisi beberapa string kosong di antaranya, dan menampilkan indeks dari kata "bola" jika ditemukan.

### CPMK 2 - SubCPMK 4
1.	Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct! 

    **Jawab:**

    Struct dalam bahasa C++ merupakan struktur data yang memungkinkan terjadinya pembentukan tipe data baru dengan menggabungkan berbagai macam variabel dengan tipe data berbeda yang tersedia dalam C++. Tipe data yang baru, dapat dibentuk di luar tipe data yang sudah ada dengan menggabungkan beberapa tipe data tersebut sesuai dengan kebutuhan program atau aplikasi yang dirancang. Berbeda dengan larik (array) yang memungkinkan penyimpanan beberapa tipe data yang sama, struct dapat menyimpan dan menggabungkan berbagai variabel dengan tipe data yang berbeda. Struktur, struct, adalah kelas spesial. Secara default, semua anggota sebuah kelas adalah private, sedangkan secara default semua anggota struct adalah public. Dalam C++, Anda mendefinisikan struktur dengan menggunakan katakunci struct.

    #### Source code:
    ```C++
    #include <iostream>
    #include <string>
    using namespace std;

    struct buku {
        string judul_buku;
        string pengarang;
        string penerbit;
        int tebal_halaman;
        double harga_buku;
    };

    int main() {
        buku nama_buku;

        nama_buku.judul_buku = "Bumi";
        nama_buku.pengarang = "Tere Liye";
        nama_buku.penerbit = "Gramedia Pustaka Utama";
        nama_buku.tebal_halaman = 504;
        nama_buku.harga_buku = 95000.0;

        cout << "Judul Buku: " << nama_buku.judul_buku << endl;
        cout << "Pengarang: " << nama_buku.pengarang << endl;
        cout << "Penerbit: " << nama_buku.penerbit << endl;
        cout << "Tebal Halaman: " << nama_buku.tebal_halaman << " halaman" << endl;
        cout << "Harga Buku: Rp" << nama_buku.harga_buku << endl;

        return 0;
    }
    ```

    #### Output

    ![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/6734c6a5-7529-4d2d-8ffe-ff77475a1aea)

    #### Interpretasi

    Program di atas adalah sebuah struktur 'buku' yang berisi data 'judul_buku' yang memberikan informasi mengenai judul buku, 'pengarang' yang memberikan informasi mengenai nama pengarang dari judul buku tersebut, 'penerbit' yang memberikan informasi mengenai penerbit mana yang menerbitkan buku tersebut, 'tebal_halaman' yang memberikan informasi mengenai jumlah atau tebal halaman buku tersebut, dan yang terakhir adalah 'harga_buku; yang memberikan informasi mengenai harga buku tersebut. Kemudian semua informasi di atas akan di simpan di dalam variabel 'nama_buku'. Dan dengan fungsi 'cout' maka program akan menampilkan informasi tersebut.

### CPMK 2 - SubCPMK 5
1.	Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular)  

    #### Source code:
    ```C++
    #include <iostream>
    #include <unordered_set>

    using namespace std;

    // Node untuk linked list
    struct Node {
        int data;
        Node* next;
    };

    // Fungsi untuk menambahkan node baru ke linked list
    void tambahNode(Node*& head, int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Fungsi untuk menghapus duplikasi data pada unsorted linked list
    void hapusDuplikasi(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return; // Tidak perlu melakukan apapun jika linked list kosong atau hanya memiliki satu node
        }

        unordered_set<int> dataSet; // Set untuk menyimpan data yang telah ditemui

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            // Jika data sudah ada dalam set, hapus node dari linked list
            if (dataSet.find(current->data) != dataSet.end()) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                // Jika data belum ditemukan, tambahkan ke set dan lanjutkan ke node berikutnya
                dataSet.insert(current->data);
                prev = current;
                current = current->next;
            }
        }
    }

    // Fungsi untuk mencetak linked list
    void cetakLinkedList(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    // Fungsi untuk menghapus semua node dalam linked list
    void hapusLinkedList(Node*& head) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int main() {
        // Mendefinisikan linked list
        Node* head = nullptr;

        // Menambahkan data ke linked list
        tambahNode(head, 3);
        tambahNode(head, 6);
        tambahNode(head, 2);
        tambahNode(head, 3);
        tambahNode(head, 6);
        tambahNode(head, 5);

        cout << "Linked List sebelum menghapus duplikasi: ";
        cetakLinkedList(head);

        // Menghapus duplikasi data pada linked list
        hapusDuplikasi(head);

        cout << "Linked List setelah menghapus duplikasi: ";
        cetakLinkedList(head);

        // Membersihkan memori
        hapusLinkedList(head);

        return 0;
    }
    ```

    #### Output

    ![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/08365c1a-32e4-4939-ae05-5c9f3bfdc1b6)

    #### Interpretasi

    Program di atas merupakan sebuah program untuk menghapus duplikasi data pada sebuah unsorted linked list. Struct `Node` digunakan untuk merepresentasikan node dalam linked list, dengan dua anggota: `data` untuk menyimpan nilai data dan `next` untuk menunjukkan ke node berikutnya. Fungsi `tambahNode` digunakan untuk menambahkan node baru ke linked list, sementara `cetakLinkedList` digunakan untuk mencetak semua elemen dalam linked list. Fungsi `hapusDuplikasi` adalah fungsi utama yang menggunakan unordered set untuk menyimpan data yang telah ditemui dan menghapus duplikasi saat traversing linked list. Dengan algoritma ini, program dapat secara efisien menghapus duplikasi data dari linked list.

2.	Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

    #### Algoritma
    1. Mulai dari head dan lakukan traversing hingga menemukan node yang ingin dihapus.

    2. Simpan node sebelumnya dari node yang ingin dihapus.

    3. Ubah pointer next dari node sebelumnya untuk melewati node yang akan dihapus dan menunjuk ke node setelahnya.

    4. Hapus node yang ingin dihapus dan bebaskan memori yang digunakan.

    5. Pastikan untuk menangani kasus khusus jika node yang ingin dihapus adalah node pertama.

    #### Source code:
    ```C++
    #include <iostream>

    using namespace std;

    struct Node {
    int data;
    Node* next;
    };

    Node* head = NULL; // Pointer ke head node

    void insertAtBeginning(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    }

    void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    }

    void deleteNodeAtMiddle(int position) {
    if (head == NULL || position < 1) {
        return; // List kosong atau posisi tidak valid
    }

    Node* prevNode = NULL;
    Node* currNode = head;
    int count = 1;

    // Temukan node sebelum node yang dihapus
    while (count < position && currNode != NULL) {
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }

    // Jika node yang dihapus adalah node head
    if (prevNode == NULL) {
        head = currNode->next;
        delete currNode;
        return;
    }

    // Hubungkan node sebelum dan sesudah
    prevNode->next = currNode->next;
    delete currNode;
    }

    int main() {
    insertAtBeginning(5);
    insertAtBeginning(4);
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);

    cout << "Linked list awal: ";
    printList();

    deleteNodeAtMiddle(3); // Menghapus node dengan data 3

    cout << "Linked list setelah penghapusan: ";
    printList();

    return 0;
    }
    ```

    #### Output

    ![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/de3084ad-be04-4be9-af87-5a9c2766a088)

    #### Interpretasi

    Program di atas merupakan sebuah program yang dapat untuk menghapus node di tengah single linked list. Struktur Node digunakan untuk merepresentasikan elemen linked list yang berisi data integer dan pointer ke node berikutnya. Fungsi insertAtBeginning menambahkan node baru di awal linked list, sementara fungsi printList mencetak semua elemen dalam linked list. Fungsi deleteNodeAtMiddle menghapus node pada posisi tertentu dalam linked list. Fungsi main menambahkan beberapa node ke linked list, mencetak linked list awal, menghapus node pada posisi ketiga, dan mencetak linked list setelah penghapusan.

3.	Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom!  

    #### Source code:
    ```C++
    #include <iostream>

    using namespace std;

    struct Node {
    int data;
    Node* next;
    };

    Node* head = NULL; // Pointer ke head node

    void insertAtBeginning(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    }

    void printList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    }

    bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; // Linked list kosong atau hanya memiliki 1 node
    }

    // Temukan node tengah
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse linked list dari node tengah ke belakang
    Node* prev = NULL;
    Node* curr = slow;
    Node* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Bandingkan node di awal dan di akhir
    Node* left = head;
    Node* right = prev;
    while (left != NULL && right != NULL) {
        if (left->data != right->data) {
        return false; // Bukan palindrom
        }
        left = left->next;
        right = right->next;
    }

    return true; // Merupakan palindrom
    }

    int main() {
    int data;

    cout << "Masukkan data untuk linked list (-1 untuk berhenti): ";
    while (cin >> data && data != -1) {
        insertAtBeginning(data);
    }

    cout << "Linked list: ";
    printList();

    bool isPalindromic = isPalindrome(head);
    if (isPalindromic) {
        cout << "Linked list adalah palindrom!" << endl;
    } else {
        cout << "Linked list bukan palindrom." << endl;
    }

    return 0;
    }
    ```

    #### Output

    ![image](https://github.com/rennanvra/Algoritma-dan-Struktur-Data/assets/162097323/a8796969-b4d5-47df-a171-71477642a17f)

    #### Interpretasi

    Program ini memeriksa apakah linked list adalah palindrom. Struktur `Node` merepresentasikan setiap elemen dalam linked list. Fungsi `insertAtBeginning` menambahkan elemen di awal, dan `printList` mencetak semua elemen. Fungsi `isPalindrome` mengecek palindrom dengan mencari node tengah, membalikkan bagian kedua linked list, dan membandingkan elemen dari awal hingga tengah dengan elemen dari tengah hingga akhir. Program menerima input dari pengguna, mencetak linked list, dan menginformasikan apakah linked list tersebut adalah palindrom.

### CPMK 2 - SubCPMK 6
1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

    #### Source code:
    ```C++
    #include <iostream>

    using namespace std;

    #define MAX_SIZE 100 // Ukuran maksimum stack

    struct Node {
    int data;
    Node* next;
    };

    Node* top = NULL; // Pointer ke node teratas stack

    // Fungsi untuk memeriksa apakah stack kosong
    bool isEmpty() {
    return top == NULL;
    }

    // Fungsi untuk memeriksa apakah stack penuh
    bool isFull() {
    return top != NULL && top->next == NULL;
    }

    // Fungsi untuk menambahkan elemen ke stack
    void push(int data) {
    if (isFull()) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    }

    // Fungsi untuk mengambil elemen teratas dari stack
    int pop() {
    if (isEmpty()) {
        cout << "Stack kosong!" << endl;
        return -1;
    }

    int topData = top->data;
    Node* temp = top;
    top = top->next;
    delete temp; // Menghapus node yang dipop
    return topData;
    }

    // Fungsi untuk melihat elemen teratas tanpa menghapusnya
    int peek() {
    if (isEmpty()) {
        cout << "Stack kosong!" << endl;
        return -1;
    }

    return top->data;
    }

    int main() {
    int choice, data;

    while (true) {
        cout << "\nMenu Operasi Stack:" << endl;
        cout << "1. Tambah" << endl;
        cout << "2. Hapus" << endl;
        cout << "3. Lihat" << endl;
        cout << "4. Periksa Apakah Stack Kosong" << endl;
        cout << "5. Periksa Apakah Stack Penuh" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        cin.ignore(); // Membersihkan buffer stdin

        switch (choice) {
        case 1:
            cout << "Masukkan data yang ingin dipush: ";
            cin >> data;
            push(data);
            break;

        case 2:
            data = pop();
            if (data != -1) {
            cout << "Elemen yang dipop: " << data << endl;
            }
            break;

        case 3:
            data = peek();
            if (data != -1) {
            cout << "Elemen teratas: " << data << endl;
            }
            break;

        case 4:
            if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            } else {
            cout << "Stack tidak kosong." << endl;
            }
            break;

        case 5:
            if (isFull()) {
            cout << "Stack penuh!" << endl;
            } else {
            cout << "Stack tidak penuh." << endl;
            }
            break;

        case 0:
            exit(0);

        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
    }
    ```

    #### Output

    ![image](https://github.com/rennanvra/Praktikum-7/assets/162097323/86a5e679-d3fa-4d25-a557-f75f18645131)

    #### Interpretasi

    Program di atas adalah implementasi dari operasi dasar pada struktur data stack dalam bahasa C++. Stack adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Program ini menyediakan operasi push untuk menambahkan elemen baru ke dalam stack, pop untuk menghapus dan mengembalikan elemen teratas, serta peek untuk melihat elemen teratas tanpa menghapusnya. Selain itu, program juga memiliki fungsi isEmpty untuk memeriksa apakah stack kosong, dan isFull untuk memeriksa apakah stack penuh sebelum operasi push dilakukan. Implementasi stack menggunakan struktur data linked list, di mana setiap elemen stack direpresentasikan sebagai node yang terhubung satu sama lain. Setiap operasi dilengkapi dengan pengecekan kondisi untuk memastikan operasi dilakukan dengan benar sesuai aturan stack.

2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty.  

    #### Source code:
    ```C++
    #include <iostream>
    #include <stack>

    using namespace std;

    // Fungsi untuk mengurutkan stack
    void sortStack(stack<int>& s) {
        stack<int> tempStack; // Stack sementara untuk membantu pengurutan

        while (!s.empty()) {
            int topValue = s.top();
            s.pop();

            while (!tempStack.empty() && tempStack.top() > topValue) {
                s.push(tempStack.top());
                tempStack.pop();
            }

            tempStack.push(topValue);
        }

        // Pindahkan isi tempStack ke stack asli
        while (!tempStack.empty()) {
            s.push(tempStack.top());
            tempStack.pop();
        }
    }

    int main() {
        stack<int> s;

        // Masukkan data ke stack
        int data;
        cout << "Masukkan data (-1 untuk berhenti): ";
        while (cin >> data && data != -1) {
            s.push(data);
        }

        cout << "\nStack awal: ";
        stack<int> originalStack = s; // Salin stack untuk ditampilkan
        while (!originalStack.empty()) {
            cout << originalStack.top() << " ";
            originalStack.pop();
        }

        sortStack(s); // Mengurutkan stack

        cout << "\nStack setelah diurutkan: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }

        return 0;
    }
    ```

    #### Output

    ![Screenshot 2024-05-14 232010](https://github.com/rennanvra/Praktikum-7/assets/162097323/ae6f9df1-eb76-4d4b-8033-d6f9fd2c9fc0)

    #### Interpretasi

    Program di atas adalah sebuah program C++ yang mengimplementasikan fungsi untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut atau untuk mengurutkan isi dari sebuah stack. Pertama, program meminta pengguna untuk memasukkan data ke dalam stack. Kemudian, data yang dimasukkan akan ditampilkan sebagai "Stack awal". Selanjutnya, fungsi `sortStack` akan mengurutkan isi dari stack secara ascending, sehingga item dengan nilai terkecil akan berada di bagian atas stack. Setelah diurutkan, isi stack akan ditampilkan kembali sebagai "Stack setelah diurutkan". Algoritma pengurutan yang digunakan adalah algoritma sederhana yang menggunakan satu stack tambahan (`tempStack`) untuk menyimpan nilai-nilai sementara saat mengurutkan. 

### CPMK 2 - SubCPMK 7
1.	Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

    #### Source code:
    ```C++
    #include <iostream>

    using namespace std;

    #define MAX_SIZE 100 // Ukuran maksimum stack

    struct Node {
    int data;
    Node* next;
    };

    Node* top = NULL; // Pointer ke node teratas stack

    // Fungsi untuk memeriksa apakah stack kosong
    bool isEmpty() {
    return top == NULL;
    }

    // Fungsi untuk memeriksa apakah stack penuh
    bool isFull() {
    return top != NULL && top->next == NULL;
    }

    // Fungsi untuk menambahkan elemen ke stack
    void push(int data) {
    if (isFull()) {
        cout << "Stack penuh!" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    }

    // Fungsi untuk mengambil elemen teratas dari stack
    int pop() {
    if (isEmpty()) {
        cout << "Stack kosong!" << endl;
        return -1;
    }

    int topData = top->data;
    Node* temp = top;
    top = top->next;
    delete temp; // Menghapus node yang dipop
    return topData;
    }

    // Fungsi untuk melihat elemen teratas tanpa menghapusnya
    int peek() {
    if (isEmpty()) {
        cout << "Stack kosong!" << endl;
        return -1;
    }

    return top->data;
    }

    int main() {
    int choice, data;

    while (true) {
        cout << "\nMenu Operasi Stack:" << endl;
        cout << "1. Tambah" << endl;
        cout << "2. Hapus" << endl;
        cout << "3. Lihat" << endl;
        cout << "4. Periksa Apakah Stack Kosong" << endl;
        cout << "5. Periksa Apakah Stack Penuh" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        cin.ignore(); // Membersihkan buffer stdin

        switch (choice) {
        case 1:
            cout << "Masukkan data yang ingin dipush: ";
            cin >> data;
            push(data);
            break;

        case 2:
            data = pop();
            if (data != -1) {
            cout << "Elemen yang dipop: " << data << endl;
            }
            break;

        case 3:
            data = peek();
            if (data != -1) {
            cout << "Elemen teratas: " << data << endl;
            }
            break;

        case 4:
            if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            } else {
            cout << "Stack tidak kosong." << endl;
            }
            break;

        case 5:
            if (isFull()) {
            cout << "Stack penuh!" << endl;
            } else {
            cout << "Stack tidak penuh." << endl;
            }
            break;

        case 0:
            exit(0);

        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
    }
    ```

    #### Output

    ![image](https://github.com/rennanvra/Praktikum-7/assets/162097323/86a5e679-d3fa-4d25-a557-f75f18645131)

    #### Interpretasi

    Program di atas adalah implementasi dari operasi dasar pada struktur data stack dalam bahasa C++. Stack adalah struktur data yang mengikuti prinsip LIFO (Last In, First Out), di mana elemen terakhir yang dimasukkan akan menjadi yang pertama dikeluarkan. Program ini menyediakan operasi push untuk menambahkan elemen baru ke dalam stack, pop untuk menghapus dan mengembalikan elemen teratas, serta peek untuk melihat elemen teratas tanpa menghapusnya. Selain itu, program juga memiliki fungsi isEmpty untuk memeriksa apakah stack kosong, dan isFull untuk memeriksa apakah stack penuh sebelum operasi push dilakukan. Implementasi stack menggunakan struktur data linked list, di mana setiap elemen stack direpresentasikan sebagai node yang terhubung satu sama lain. Setiap operasi dilengkapi dengan pengecekan kondisi untuk memastikan operasi dilakukan dengan benar sesuai aturan stack.

2.	Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty.  

    #### Source code:
    ```C++
    #include <iostream>
    #include <stack>

    using namespace std;

    // Fungsi untuk mengurutkan stack
    void sortStack(stack<int>& s) {
        stack<int> tempStack; // Stack sementara untuk membantu pengurutan

        while (!s.empty()) {
            int topValue = s.top();
            s.pop();

            while (!tempStack.empty() && tempStack.top() > topValue) {
                s.push(tempStack.top());
                tempStack.pop();
            }

            tempStack.push(topValue);
        }

        // Pindahkan isi tempStack ke stack asli
        while (!tempStack.empty()) {
            s.push(tempStack.top());
            tempStack.pop();
        }
    }

    int main() {
        stack<int> s;

        // Masukkan data ke stack
        int data;
        cout << "Masukkan data (-1 untuk berhenti): ";
        while (cin >> data && data != -1) {
            s.push(data);
        }

        cout << "\nStack awal: ";
        stack<int> originalStack = s; // Salin stack untuk ditampilkan
        while (!originalStack.empty()) {
            cout << originalStack.top() << " ";
            originalStack.pop();
        }

        sortStack(s); // Mengurutkan stack

        cout << "\nStack setelah diurutkan: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }

        return 0;
    }
    ```

    #### Output

    ![Screenshot 2024-05-14 232010](https://github.com/rennanvra/Praktikum-7/assets/162097323/ae6f9df1-eb76-4d4b-8033-d6f9fd2c9fc0)

    #### Interpretasi

    Program di atas adalah sebuah program C++ yang mengimplementasikan fungsi untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut atau untuk mengurutkan isi dari sebuah stack. Pertama, program meminta pengguna untuk memasukkan data ke dalam stack. Kemudian, data yang dimasukkan akan ditampilkan sebagai "Stack awal". Selanjutnya, fungsi `sortStack` akan mengurutkan isi dari stack secara ascending, sehingga item dengan nilai terkecil akan berada di bagian atas stack. Setelah diurutkan, isi stack akan ditampilkan kembali sebagai "Stack setelah diurutkan". Algoritma pengurutan yang digunakan adalah algoritma sederhana yang menggunakan satu stack tambahan (`tempStack`) untuk menyimpan nilai-nilai sementara saat mengurutkan.