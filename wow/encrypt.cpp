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

void createEmptyNode(List* l);
void addLast(List *l, char c);
void inputPassword(List *l);

// Menu functions
void changeRole(string *role);
void encrypt(List *l);
void decrypt(List *l);
void showPassword(List l, string user);
void changePassword(List *l);


int main() {
    List password;
    createEmptyNode(&password);

    char choose;
    int rating;
    string role = "admin";

    cout << "Program Encrypt & Decrypt Password\n\n";
    cout << "Silahkan membuat password baru terlebih dahulu!\n\n";

    inputPassword(&password);

    do {
        cout << "\n----------------------\n";
        cout << "Menu\n";
        cout << "Role: " << role << endl;
        cout << "----------------------\n";
        cout << "1. Ubah role\n";
        cout << "2. Enkripsi password\n";
        cout << "3. Dekripsi password\n";
        cout << "4. Tampilkan password\n";
        cout << "5. Ubah password\n";
        cout << "6. Keluar program\n";
        cout << "----------------------\n";
        cout << "Pilih: ";
        cin  >> choose; 

        switch (choose) {
        case '1':
            changeRole(&role);
            break;
        case '2':
            encrypt(&password);
            break;
        case '3':
            decrypt(&password);
            break; 
        case '4':
            showPassword(password, role);
            break;
        case '5':
            changePassword(&password);
            inputPassword(&password);
            break;
        case '6':
            cout<< "Beri Rating(1/10): \n"; cin>>rating;
            cout<< "Terima kasih telah menggunakan program ini! dan memberi rating "<<rating<<endl;
            break;
        default:
            cout << "Pilihan tidak valid, coba lagi!\n";
            break;
        }
    } while (choose != '6');

    return 0;
}

void createEmptyNode(List* l) {
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

        (*l).head = (*l).head->next;
        (*l).head->prev = nullptr; 

        (*l).head->prev = (*l).tail;
        (*l).tail->next = (*l).head; 

        (*l).head = (*l).tail->prev->prev;
        (*l).tail = (*l).tail->prev->prev->prev;

        (*l).head->prev = nullptr;
        (*l).tail->next = nullptr;

        (*l).tail->next = (*l).key;
        (*l).key->prev = (*l).tail;
        (*l).tail = (*l).key;

        (*l).key = tmp;

        (*l).encrypted = true;
        
        cout << "\nPassword berhasil di enkripsi!\n";
    }
}

void decrypt(List* l) {
    if (!(*l).encrypted) {
        cout << "Password sudah di dekripsi!\n";
    } else {
        address tmp;

        tmp = (*l).tail;

        (*l).tail = (*l).tail->prev;
        (*l).tail->next = nullptr;

        (*l).head->prev = (*l).tail;
        (*l).tail->next = (*l).head;

        (*l).head = (*l).tail->prev;
        (*l).tail = (*l).tail->prev->prev;

        (*l).head->prev = nullptr;
        (*l).tail->next = nullptr;

        (*l).head->prev = (*l).key;
        (*l).key->next = (*l).head;
        (*l).head = (*l).key;

        (*l).key = tmp;

        (*l).encrypted = false;

        cout << "\nPassword berhasil di dekripsi!\n";
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

    cout << "Password lama dihapus! input password yang baru\n\n";
}

void inputPassword(List *l) {
    string password;

    do {
        cout << "Masukkan password (minimal 6 karakter): "; cin >> password;

        if(password.length() < 6) {
            cout << "Password anda kurang dari 6 karakter\n";
        }
    } while (password.length() < 6);

    for (int i = 0; i < password.length(); i++) {
        addLast(l, password[i]);
    }

    cout << "Berhasil membuat password baru!\n";
}

void changeRole(string* user) {
    if(*user == "admin"){
        *user = "anonymous";
    }else{
        *user = "admin";
    }
    
    cout<<"Berhasil ganti role!\n";
}