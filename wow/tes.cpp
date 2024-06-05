#include<iostream>

using namespace std;

typedef struct Node* address;
struct Node {
    char character;
    address next;
    address prev;
};

struct List {
    address head;
    address tail;
    int size = 0;
    bool encrypted = false;
    address key;
};

void createEmptyNode (List* l) {
    address key = new Node;
    key->character = 'X';
    key->next = nullptr;
    key->prev = nullptr;

    (*l).head = nullptr;
    (*l).tail = nullptr;
    (*l).key = key;
}

void addLast(List *l, char c) {
    address newNode = new Node();
    newNode->character = c;
    newNode->next = nullptr;

    if((*l).head == nullptr) {
        newNode->prev = nullptr;
        (*l).head = newNode;
        (*l).tail = newNode;
    } else {
        newNode->prev = (*l).tail;
        (*l).tail->next = newNode;
        (*l).tail = newNode;
    }

    (*l).size++;
}

void showPassword(List l, string user) {
    if (l.size == 0) {
        cout << "Password kosong!\n";
        return;
    }

    address curr;
    
    cout << "Password: ";
    
    if(user == "admin") {
        curr = l.head;
        while (curr) {
            cout << curr->character;
            curr = curr->next;
        }
    } else if (user == "anonymous") {
        curr = l.tail;
        while (curr) {
            cout << curr->character;
            curr = curr->prev;
        }
    }
    cout << endl;
}

void encrypt(List* l) {
    if ((*l).encrypted) {
        cout << "Password sudah di enkripsi!\n";
    } else {
        address tmp;

        tmp = (*l).head;
        (*l).head = (*l).key;
        (*l).key = tmp;

        (*l).head->prev = (*l).tail;
        (*l).tail->next = (*l).head;

        (*l).head = (*l).tail->prev;
        (*l).tail = (*l).tail->prev->prev;

        (*l).head->prev = nullptr;
        (*l).tail->next = nullptr;

        (*l).key->prev = (*l).tail->prev;
        (*l).tail->prev->next = (*l).key;
        (*l).tail->prev = nullptr;

        (*l).encrypted = true;

        cout << "Password berhasil di enkripsi!\n";
    }
}

void decrypt(List* l) {
    if (!(*l).encrypted) {
        cout << "Password sudah di dekripsi!\n";
    } else {
        address tmp;
        (*l).key->prev = (*l).tail->prev;
        (*l).tail->prev->next = (*l).key;
        (*l).tail->prev = nullptr;

        tmp = (*l).tail;
        (*l).tail = (*l).key;
        (*l).key = tmp;

        (*l).head->prev = (*l).tail;
        (*l).tail->next = (*l).head;

        (*l).tail = (*l).head->next;
        (*l).head = (*l).head->next->next;

        (*l).head->prev = nullptr;
        (*l).tail->next = nullptr;

        (*l).encrypted = false;

        cout << "Password berhasil di dekripsi!\n";
    }
}

void changePassword(List *l) {
    if((*l).size > 0) {
        address tmp, curr;
        curr = (*l).head;

        while(curr) {
            tmp = curr;
            curr = curr->next;
            delete tmp;
        }

        (*l).head = nullptr;
        (*l).tail = nullptr;
        (*l).size = 0;
        (*l).encrypted = false;
    }
}

void inputPassword(List *l) {
    string password;

    do {
        cout << "Masukkan password (minimal 6 karakter): ";
        cin >> password;

        if(password.length() < 6) {
            cout << "Password tidak valid!\n";
        }
    } while (password.length() < 6);

    for (int i = 0; i < password.length(); i++) {
        addLast(l, password[i]);
    }

    cout << "Berhasil membuat password baru!\n";
}

void changeRole(string* user, List pass) {
    if (*user == "admin") {
        cout << "Anda sudah login!\n";
        return;
    } 

    string passInput;

    cout << "Masukkan password (minimal 6 karakter): ";
    cin >> passInput;

    if(passInput.length() < 6) {
        cout << "Password salah!\n";
    } else {
        address curr = pass.head;
        int counter = 0;

        while (curr) {
            if(passInput[counter] != curr->character) {
                cout << "Password salah!\n";
                return;
            }
            curr = curr->next;
            counter++;
        }

        cout << "Password benar, selamat datang!\n";
        *user = "admin";
    }
}

void logout(string* user) {
    if(*user == "anonymous") {
        cout << "Anda sudah logout!\n";
    } else {
        cout << "Berhasil logout, selamat tinggal!\n";
        *user = "anonymous";
    }
}

int main() {
    List password;
    createEmptyNode(&password);

    cout << "Selamat datang di program PASSWORD SLEBEW 1.0\n";
    cout << "Silahkan membuat password baru terlebih dahulu!\n";
    inputPassword(&password);

    char choose;
    string username = "anonymous";

    do {
        cout << "\n=====================\n";
        cout << " PASSWORD SLEBEW 1.0\n";
        cout << " Username: " << username << endl;
        cout << "=====================\n";
        cout << "1. Login\n";
        cout << "2. Tampilkan password\n";
        cout << "3. Ubah password\n";
        cout << "4. Enkripsi password\n";
        cout << "5. Dekripsi password\n";
        cout << "6. Logout\n";
        cout << "x. Keluar\n";
        cout << "=====================\n";
        cout << "Pilih: ";
        cin  >> choose; 

        switch (choose) {
        case '1':
            changeRole(&username, password);
            break;
        case '2':
            showPassword(password, username);
            break;
        case '3':
            changePassword(&password);
            inputPassword(&password);
            break; 
        case '4':
            encrypt(&password);
            break;
        case '5':
            decrypt(&password);
            break;
        case '6':
            logout(&username);
            break;
        case 'x':
            cout << "Terima kasih, selamat tinggal :(\n";
            break;
        default:
            cout << "Pilihan tidak valid, coba lagi!\n";
            break;
        }

    } while (choose != 'x');

    return 0;
}