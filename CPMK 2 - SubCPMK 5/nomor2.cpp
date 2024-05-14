#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head = NULL; // Pointer ke head node

void insertAtBeginning(int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

void printList() {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void deleteNodeAtMiddle(int position) {
  if (head == NULL || position < 1) {
    return; // List kosong atau posisi tidak valid
  }

  Node* prevNode = NULL;
  Node* currNode = head;
  int count = 1;

  // Temukan node sebelum node yang dihapus
  while (count < position && currNode != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
    count++;
  }

  // Jika node yang dihapus adalah node head
  if (prevNode == NULL) {
    head = currNode->next;
    delete currNode;
    return;
  }

  // Hubungkan node sebelum dan sesudah
  prevNode->next = currNode->next;
  delete currNode;
}

int main() {
  insertAtBeginning(5);
  insertAtBeginning(4);
  insertAtBeginning(3);
  insertAtBeginning(2);
  insertAtBeginning(1);

  cout << "Linked list awal: ";
  printList();

  deleteNodeAtMiddle(3); // Menghapus node dengan data 3

  cout << "Linked list setelah penghapusan: ";
  printList();

  return 0;
}
