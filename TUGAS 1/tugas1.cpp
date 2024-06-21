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