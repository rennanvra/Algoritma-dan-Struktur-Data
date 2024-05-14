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

bool isPalindrome(Node* head) {
  if (head == NULL || head->next == NULL) {
    return true; // Linked list kosong atau hanya memiliki 1 node
  }

  // Temukan node tengah
  Node* slow = head;
  Node* fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Reverse linked list dari node tengah ke belakang
  Node* prev = NULL;
  Node* curr = slow;
  Node* next;
  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  // Bandingkan node di awal dan di akhir
  Node* left = head;
  Node* right = prev;
  while (left != NULL && right != NULL) {
    if (left->data != right->data) {
      return false; // Bukan palindrom
    }
    left = left->next;
    right = right->next;
  }

  return true; // Merupakan palindrom
}

int main() {
  int data;

  cout << "Masukkan data untuk linked list (-1 untuk berhenti): ";
  while (cin >> data && data != -1) {
    insertAtBeginning(data);
  }

  cout << "Linked list: ";
  printList();

  bool isPalindromic = isPalindrome(head);
  if (isPalindromic) {
    cout << "Linked list adalah palindrom!" << endl;
  } else {
    cout << "Linked list bukan palindrom." << endl;
  }

  return 0;
}
