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