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