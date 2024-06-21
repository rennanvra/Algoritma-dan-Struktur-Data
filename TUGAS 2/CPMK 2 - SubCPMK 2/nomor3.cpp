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
