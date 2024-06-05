#include <iostream>
using namespace std;

// Struktur data stack sederhana
struct Stack {
    int data[100];
    int top;

    // Inisialisasi stack pada saat pertama kali dibuat
    Stack() {
        top = -1;
    }

    // Fungsi untuk menambahkan data ke stack
    void push(int value) {
        if (top < 27) {
            data[++top] = value;
        } else {
            cout << "Stack penuh." << endl;
        }
    }

    // Fungsi untuk mengambil data dari stack
    int pop() {
        if (top >= 0) {
            return data[top--];
        } else {
            cout << "Stack kosong." << endl;
            return -1; // Nilai khusus yang menunjukkan stack kosong
        }
    }

    // Fungsi untuk mengecek apakah stack kosong atau tidak
    bool isEmpty() {
        return top == -1;
    }
};

// Fungsi untuk mengubah bilangan desimal ke bileran
string decimalToBinary(int decimal) {
    Stack binaryStack;

    // Ambil sisa bagi dari pembagian desimal dengan 2
    while (decimal > 0) {
        binaryStack.push(decimal % 2);

        decimal /= 2;
    }

    string binaryString = "";

    // Ambil data dari stack dan tambahkan ke string
    while (!binaryStack.isEmpty()) {
        binaryString += to_string(binaryStack.pop());
    }

    // Tambahkan padding dengan angka 0 jika kurang dari 8 digit
    while (binaryString.length() < 8) {
        binaryString = "0" + binaryString;
    }

    return binaryString;
}

void divideTwo(string nimString, Stack &stack) {
    int nimInt = stoi(nimString);

    for (int i = 0; i <= nimString.length(); i++) {
        nimInt /= 2;
        
        stack.push(nimInt);
    }
}

void display(Stack &stack) {
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
}

int main() {
    Stack stack;
    string nim, role;
    int choice;

    cout << "Masukkan NIM (9 digit): ";
    cin >> nim;

    if (nim.length() != 9) {
        cout << "NIM harus terdiri dari 9 digit." << endl;
        return 1;
    }

    cout << "Masukkan role (admin/user): ";
    cin >> role;

    int nimInt = stoi(nim);

    while (true) {
        cout << "Menu Program: " << endl;
        cout << "1. Konversi Decimal NIM ke Binary" << endl;
        cout << "2. Bagi 2 NIM" << endl;
        cout << "3. Keluar program" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (role == "admin") {
                    cout << "Representasi biner dari NIM: ";
                    cout << decimalToBinary(nimInt) << endl;
                } else if (role == "user") {
                    cout << "Representasi biner dari NIM: ";
                    while (stack.top < 26) {
                        stack.push(rand() % 2 * 3);
                    }
                }

                display(stack);
                cout << endl << endl;
                break;
            case 2:
                if (role == "admin") {
                    cout << "Hasil pembagian NIM dengan 2: ";
                    divideTwo(nim,stack);
                } else if (role == "user") {
                    cout << "Hasil pembagian NIM dengan 2: ";
                    while (stack.top < 9) {
                        stack.push(rand()/2);
                    }
                }

                display(stack);
                cout << endl << endl;
                break;
            case 3:
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
