#include <iostream>

using namespace std;

struct Node {
  int angka;
  Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

Node *initialize(int angka) {
  Node *newNode = new Node;
  newNode->angka = angka;
  newNode->next = nullptr;
  return newNode;
}

void insertFirst(int angka) {
  Node *newNode = initialize(angka);
  if (!head) {
    head = newNode;
    tail = newNode;
    tail->next = head;
  } else {
    newNode->next = head;
    head = newNode;
    tail->next = head;
  }
}

void insertLast(int angka) {
  Node *newNode = initialize(angka);
  if (!head) {
    head = newNode;
    tail = newNode;
    tail->next = head;
  } else {
    newNode->next = head;
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
  Node *prev = nullptr;

  do {
    Node *temp = head;
    bool duplicateFound = false;

    do {
      if (temp != current && temp->angka == current->angka) {
        duplicateFound = true;
        break;
      }
      temp = temp->next;
    } while (temp != head);

    if (duplicateFound) {
      if (current == head) {
        head = current->next;
        tail->next = head;
        delete current;
        current = head;
      } else {
        prev->next = current->next;
        delete current;
        current = prev->next;
      }
    } else {
      prev = current;
      current = current->next;
    }
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
                }while(head != tail);

                cout << "Program berakhir." << endl;
                
                return;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }
}

int main (){
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

    return 0;
}