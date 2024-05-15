#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Ukuran maksimum queue

class Queue {
private:
    int front;
    int rear;
    int count;
    int arr[MAX_SIZE];

public:
    // Constructor
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Fungsi untuk menambahkan elemen ke dalam queue (enqueue)
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue penuh!" << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = data;
        count++;
    }

    // Fungsi untuk menghapus elemen dari queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return -1;
        }
        int data = arr[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        return data;
    }

    // Fungsi untuk memeriksa apakah queue kosong
    bool isEmpty() {
        return count == 0;
    }

    // Fungsi untuk memeriksa apakah queue penuh
    bool isFull() {
        return count == MAX_SIZE;
    }

    // Fungsi untuk mendapatkan ukuran queue
    int size() {
        return count;
    }

    // Fungsi untuk melihat elemen di depan queue tanpa menghapusnya (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Fungsi untuk menampilkan elemen-elemen dalam queue
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, data;

    while (true) {
        cout << "\nMenu Operasi Queue:" << endl;
        cout << "1. Tambah (Enqueue)" << endl;
        cout << "2. Hapus (Dequeue)" << endl;
        cout << "3. Lihat Elemen Depan (Peek)" << endl;
        cout << "4. Periksa Apakah Queue Kosong" << endl;
        cout << "5. Periksa Apakah Queue Penuh" << endl;
        cout << "6. Lihat Ukuran Queue" << endl;
        cout << "7. Tampilkan Queue" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data yang ingin ditambahkan: ";
                cin >> data;
                q.enqueue(data);
                break;

            case 2:
                data = q.dequeue();
                if (data != -1) {
                    cout << "Elemen yang dihapus: " << data << endl;
                }
                break;

            case 3:
                data = q.peek();
                if (data != -1) {
                    cout << "Elemen di depan: " << data << endl;
                }
                break;

            case 4:
                if (q.isEmpty()) {
                    cout << "Queue kosong!" << endl;
                } else {
                    cout << "Queue tidak kosong." << endl;
                }
                break;

            case 5:
                if (q.isFull()) {
                    cout << "Queue penuh!" << endl;
                } else {
                    cout << "Queue tidak penuh." << endl;
                }
                break;

            case 6:
                cout << "Ukuran queue: " << q.size() << endl;
                break;

            case 7:
                q.display();
                break;

            case 0:
                exit(0);

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    return 0;
}
