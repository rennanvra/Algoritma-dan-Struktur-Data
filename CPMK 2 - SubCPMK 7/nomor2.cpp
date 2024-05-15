#include <iostream>
#include <queue>

using namespace std;

struct Animal {
  string type; // "cat" atau "dog"
  string name;
  int timestamp;
};

// Deklarasi queue untuk kucing dan anjing
queue<Animal> catQueue;
queue<Animal> dogQueue;

void enqueue(string type, string name, int timestamp) {
  if (type == "cat") {
    catQueue.push({type, name, timestamp});
  } else if (type == "dog") {
    dogQueue.push({type, name, timestamp});
  } else {
    cout << "Tipe hewan tidak valid!" << endl;
  }
}

Animal dequeueAny() {
  if (catQueue.empty() && dogQueue.empty()) {
    cout << "Queue hewan kosong!" << endl;
    return {"", "", -1}; // Animal kosong
  }

  Animal nextAnimal;
  if (!catQueue.empty() && !dogQueue.empty()) {
    nextAnimal = (catQueue.front().timestamp <= dogQueue.front().timestamp) ? catQueue.front() : dogQueue.front();
  } else if (!catQueue.empty()) {
    nextAnimal = catQueue.front();
  } else {
    nextAnimal = dogQueue.front();
  }

  if (nextAnimal.type == "cat") {
    catQueue.pop();
  } else {
    dogQueue.pop();
  }

  return nextAnimal;
}

Animal dequeueDog() {
  if (dogQueue.empty()) {
    cout << "Queue anjing kosong!" << endl;
    return {"", "", -1}; // Animal kosong
  }

  Animal dog = dogQueue.front();
  dogQueue.pop();
  return dog;
}

Animal dequeueCat() {
  if (catQueue.empty()) {
    cout << "Queue kucing kosong!" << endl;
    return {"", "", -1}; // Animal kosong
  }

  Animal cat = catQueue.front();
  catQueue.pop();
  return cat;
}

int main() {
  int choice, timestamp;
  string type, name;

  while (true) {
    cout << "\nMenu Shelter Hewan:" << endl;
    cout << "1. Tambahkan hewan baru" << endl;
    cout << "2. Adopsi hewan tertua (apapun)" << endl;
    cout << "3. Adopsi anjing tertua" << endl;
    cout << "4. Adopsi kucing tertua" << endl;
    cout << "0. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Masukkan tipe hewan (cat/dog): ";
        cin >> type;
        cout << "Masukkan nama hewan: ";
        cin >> name;
        cout << "Masukkan timestamp masuk (angka): ";
        cin >> timestamp;
        enqueue(type, name, timestamp);
        break;

      case 2: {
        Animal adoptedAnimal = dequeueAny();
        if (adoptedAnimal.type != "") {
          cout << "Hewan yang diadopsi: " << adoptedAnimal.type << " - " << adoptedAnimal.name << endl;
        }
        break;
      }

      case 3: {
        Animal adoptedDog = dequeueDog();
        if (adoptedDog.type != "") {
          cout << "Anjing yang diadopsi: " << adoptedDog.name << endl;
        }
        break;
      }

      case 4: {
        Animal adoptedCat = dequeueCat();
        if (adoptedCat.type != "") {
          cout << "Kucing yang diadopsi: " << adoptedCat.name << endl;
        }
        break;
      }

      case 0:
        exit(0);

      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  }

  return 0;
}
