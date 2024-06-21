#include <iostream>
#include <unordered_set>

using namespace std;

// Node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node baru ke linked list
void tambahNode(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghapus duplikasi data pada unsorted linked list
void hapusDuplikasi(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return; // Tidak perlu melakukan apapun jika linked list kosong atau hanya memiliki satu node
    }

    unordered_set<int> dataSet; // Set untuk menyimpan data yang telah ditemui

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        // Jika data sudah ada dalam set, hapus node dari linked list
        if (dataSet.find(current->data) != dataSet.end()) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            // Jika data belum ditemukan, tambahkan ke set dan lanjutkan ke node berikutnya
            dataSet.insert(current->data);
            prev = current;
            current = current->next;
        }
    }
}

// Fungsi untuk mencetak linked list
void cetakLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Fungsi untuk menghapus semua node dalam linked list
void hapusLinkedList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Mendefinisikan linked list
    Node* head = nullptr;

    // Menambahkan data ke linked list
    tambahNode(head, 3);
    tambahNode(head, 6);
    tambahNode(head, 2);
    tambahNode(head, 3);
    tambahNode(head, 6);
    tambahNode(head, 5);

    cout << "Linked List sebelum menghapus duplikasi: ";
    cetakLinkedList(head);

    // Menghapus duplikasi data pada linked list
    hapusDuplikasi(head);

    cout << "Linked List setelah menghapus duplikasi: ";
    cetakLinkedList(head);

    // Membersihkan memori
    hapusLinkedList(head);

    return 0;
}
