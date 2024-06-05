#include <iostream>
#include <string>

using namespace std;

struct Node{
    char letter;

    Node *next;
    Node *prev;
};

struct isEncrypted{
    bool encrypted = false;
    char key;
};

Node *createNode(char letter_from_user){
    Node *newNode = new Node();

    newNode->letter = letter_from_user;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

void doubleLinkedList(Node *&head, Node *&tail, char letter_from_user){
    Node *newNode = createNode(letter_from_user);

    if (head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;

        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printPassword(Node *head, Node *tail, string role){
    cout << endl;

    if (role == "admin"){
        // Jika admin yang ingin melihat password, maka print password secara normal
        Node *current = head;

        while (current != nullptr){
            cout << current->letter << " ";

            current = current->next;
        }
    }
    else if (role == "user"){
        // jika bukan admin yang ingin melihat password, maka print password secara terbalik
        Node *current = tail;

        while (current != nullptr){
            cout << current->letter << " ";

            current = current->prev;
        }
    }
    else{
        cout << "Role anda tidak ada!" << endl;
    }

    cout << endl << endl;
}

void encrypt(Node *&head, Node *&tail){
    isEncrypted checkStatus;

    if(checkStatus.encrypted == true){
        cout << "Password sudah dienkripsi!" << endl;
        return;
    }

    Node *current = head;

    head = head->next;
    head->prev = nullptr;

    head->prev = tail;
    tail->next = head;

    head = tail->prev->prev;
    tail = tail->prev->prev->prev;

    head->prev = nullptr;
    tail->next = nullptr;

    checkStatus.encrypted = true;
    doubleLinkedList(head, tail, 'X');

    printPassword(head, tail, "admin");

    cout << "Password berhasil dienkripsi." << endl;

}

void decrypt(Node *&head, Node *&tail){
    Node *current = head;

    while (current->letter != 'X'){
        current = current->next;

        if (current->letter == 'X'){
            tail = current->prev;
            tail->next = nullptr;
            break;
        }
    }

    printPassword(head, tail, "admin");

    cout << "Password berhasil didekripsi." << endl;
}

void sendToLinkedList(Node *&head, Node *&tail, string password){
    for (int i = 0; i < password.length(); i++){
        doubleLinkedList(head, tail, password[i]);
    }
}

int main(){
    Node *head = nullptr;
    Node *tail = nullptr;

    string password, role;
    int choice;

    cout << "Program Encrypt & Decrypt Password" << endl;

    cout << "Masukkan password anda (minimal 6 karakter): ";
    cin >> password;

    while (password.length() < 6){
        cout << "\nPassword anda kurang dari 6 karakter, silahkan ulangi lagi\n"
             << endl;

        cout << "Masukkan password anda (minimal 6 karakter): ";
        cin >> password;
    }

    sendToLinkedList(head, tail, password);

    cout << endl;

    do{
        cout << "=================" << endl;

        cout << "Menu" << endl;
        cout << "1. Encrypt " << endl;
        cout << "2. Decrypt Password" << endl;
        cout << "3. Show Password" << endl;
        cout << "4. Change Password" << endl;
        cout << "5. Exit" << endl;

        cout << "Masukkan pilihan anda: ";
        cin >> choice;

        cout << "=================" << endl;

        switch (choice){
        case 1:
            encrypt(head, tail);
            break;
        case 2:
            decrypt(head, tail);
            break;
        case 3:
            cout << "\napa role anda? (admin/user): ";
            cin >> role;
            printPassword(head, tail, role);
            break;
        case 4:
            cout << "Input new password: ";
            cin >> password;
            break;
        default:
            if (choice == 5){
                cout << "\nTerima kasih telah menggunakan program ini\n"
                     << endl;

                return 0;
            }
            else{
                cout << "\nPilihan anda tidak ada! coba lagi\n"
                     << endl;
            }
            break;
        }
    } while (choice != 5);

    return 0;
}