#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk mengurutkan stack
void sortStack(stack<int>& s) {
    stack<int> tempStack; // Stack sementara untuk membantu pengurutan

    while (!s.empty()) {
        int topValue = s.top();
        s.pop();

        while (!tempStack.empty() && tempStack.top() > topValue) {
            s.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(topValue);
    }

    // Pindahkan isi tempStack ke stack asli
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> s;

    // Masukkan data ke stack
    int data;
    cout << "Masukkan data (-1 untuk berhenti): ";
    while (cin >> data && data != -1) {
        s.push(data);
    }

    cout << "\nStack awal: ";
    stack<int> originalStack = s; // Salin stack untuk ditampilkan
    while (!originalStack.empty()) {
        cout << originalStack.top() << " ";
        originalStack.pop();
    }

    sortStack(s); // Mengurutkan stack

    cout << "\nStack setelah diurutkan: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
