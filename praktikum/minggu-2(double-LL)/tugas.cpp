#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string alamat;
    float ip;

    Mahasiswa* prev;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr;
Mahasiswa* tail = nullptr;

void tambahMahasiswa(string nama, string alamat, float ip);
void searchMahasiswa(string nama);
void printDoubleLinkedList(Mahasiswa* tail);

int main() {
    int n;
    string nama, alamat;
    float ip;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        getline(cin, nama);
        cout << "Alamat: ";
        getline(cin, alamat);
        cout << "IP: ";
        cin >> ip;

        tambahMahasiswa(nama, alamat, ip);
        cin.ignore();
    }

    printDoubleLinkedList(tail);

    cout << endl;

    string nameSearch;

    cout << "Masukkan nama mahasiswa yang ingin dicari: ";
    getline(cin, nameSearch);

    searchMahasiswa(nameSearch);

    return 0;
}

void tambahMahasiswa(string nama, string alamat, float ip) {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nama = nama;
    newMahasiswa->alamat = alamat;
    newMahasiswa->ip = ip;

    newMahasiswa->prev = nullptr;
    newMahasiswa->next = nullptr;

    if (head == nullptr) {
        head = newMahasiswa;
        tail = newMahasiswa;
    }else {
        tail->next = newMahasiswa;
        newMahasiswa->prev = tail;
        tail = newMahasiswa;
    }
}

void searchMahasiswa(string nama) {
    // cek dari tail
    Mahasiswa* current = tail;

    while (current != nullptr) {
        if (current->nama == nama) {
            cout << "Found!" << endl;

            cout << "Nama: " << current->nama << endl;
            cout << "Alamat: " << current->alamat << endl;
            cout << "IP: " << current->ip << endl;
            return;
        }

        current = current->prev;
    }

    cout << "Mahasiswa dengan nama " << nama << " tidak ditemukan." << endl;
}

void printDoubleLinkedList(Mahasiswa* tail) {
    Mahasiswa* current = tail;

    cout<< "\nData semua mahasiswa dari belakang: " << endl;

    while (current != nullptr) {
        cout << "Nama: " << current->nama << endl;
        cout << "Alamat: " << current->alamat << endl;
        cout << "IP: " << current->ip << endl;

        current = current->prev;
    }
}
