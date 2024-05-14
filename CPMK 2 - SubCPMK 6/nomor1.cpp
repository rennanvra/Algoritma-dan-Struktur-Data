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
