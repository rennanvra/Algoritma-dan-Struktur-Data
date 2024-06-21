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