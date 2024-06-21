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