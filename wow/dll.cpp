#include <iostream>

using namespace std;

struct Node {
  int angka;
  
  Node *prev;  // Menunjuk ke node sebelumnya
  Node *next;  // Menunjuk ke node berikutnya
};

Node *head = nullptr;
Node *tail = nullptr;

Node *initialize(int angka) {
  Node *newNode = new Node;
  newNode->angka = angka;
  newNode->prev = nullptr;
  newNode->next = nullptr;
  return newNode;
}

void insertFirst(int angka) {
  Node *newNode = initialize(angka);
  if (!head) {
    head = newNode;
    tail = newNode;
    head->next = head;
    head->prev = head;
  } else {
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

void insertLast(int angka) {
  Node *newNode = initialize(angka);
  if (!head) {
    head = newNode;
    tail = newNode;
    head->next = head;
    head->prev = head;
  } else {
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}

void displayCircularLinkedList() {
  if (!head) {
    cout << "List Kosong" << endl;
    return;
  }
  Node *current = head;
  do {
    cout << current->angka << " -> ";
    current = current->next;
  } while (current != head);
  cout << endl;
}

int countDuplicates() {
  if (!head) {
    return 0;
  }

  Node *current = head;
  int totalCount = 0;

  do {
    int count = 0;
    Node *temp = head;

    do {
      if (temp->angka == current->angka) {
        count++;
      }
      temp = temp->next;
    } while (temp != head);

    if (count > 1) {
      totalCount++;
      cout << "Angka duplikat: " << current->angka << endl;
    }

    current = current->next;
  } while (current != head);

  return totalCount;
}

void removeDuplicates() {
  if (!head) {
    return;
  }

  Node *current = head;
  Node *temp = nullptr;

  do {
    temp = current->next;

    while (temp != head) {
      if (temp->angka == current->angka) {
        Node *del = temp;
        temp = temp->next;
        del->prev->next = del->next;
        del->next->prev = del->prev;
        delete del;
      } else {
        temp = temp->next;
      }
    }

    current = current->next;
  } while (current != head);
}

void menu() {
  int choice;
  int angka;
  int duplicateCount;
  Node* current = nullptr;

  while (true) {
    cout << "\nMenu:" << endl;
    cout << "1. Insert First" << endl;
    cout << "2. Insert Last" << endl;
    cout << "3. Display angka" << endl;
    cout << "4. Count Duplicates" << endl;
    cout << "5. Remove Duplicates" << endl;
    cout << "6. Exit" << endl;

    cout << "Pilih opsi: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Masukkan angka: ";
        cin >> angka;
        insertFirst(angka);
        break;
      case 2:
        cout << "Masukkan angka: ";
        cin >> angka;
        insertLast(angka);
        break;
      case 3:
        displayCircularLinkedList();
        break;
      case 4:
        duplicateCount = countDuplicates();
        cout << "Total duplikat: " << duplicateCount << endl;
        break;
      case 5:
        removeDuplicates();
        cout << "Duplikat dihapus." << endl;
        break;
      case 6:
        // Hapus semua node sebelum program berakhir
        current = head;

        do{
          Node* temp = head;
          head = head->next;
          delete temp;
        } while (head != current);

        return;
      default:
        cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        break;
    }
  }
}

int main() {
  insertFirst(1);
  insertFirst(2);
  insertFirst(1);
  insertFirst(2);
  insertFirst(3);
  insertFirst(4);
  insertFirst(3);
  insertFirst(4);
  insertFirst(5);
  insertFirst(6);

  menu();
}
