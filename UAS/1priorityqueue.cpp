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