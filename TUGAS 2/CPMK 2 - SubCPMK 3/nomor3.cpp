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
