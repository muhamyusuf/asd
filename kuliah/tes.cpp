#include <iostream>
using namespace std;

typedef struct Node* address;

struct Node{
    char karakter;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
    int size = 0;
    bool terenkripsi = false;
    address pass;
};

void createEmpty(List *l){
    address pass = new Node;
    pass->karakter = 'X';
    pass->next = nullptr;
    pass->prev = nullptr;

    (*l).first = nullptr;
    (*l).last = nullptr;
    (*l).pass = pass; 
}

void addLast(List *l, char n){
    address newNode =   new Node();
    newNode->karakter = n;
    newNode->next = nullptr;

    if((*l).first == nullptr){
        newNode->prev = nullptr;
        (*l).first = newNode;
        (*l).last = newNode;

    } else {
        newNode->prev = (*l).last;
        (*l).last->next = newNode;
        (*l).last = newNode;
    }

    (*l).size++;
}

void showPassword(List l, string user){
    if(l.size == 0){
        cout << "Password kosong !";
        return ;
    }

    address current;
    
    cout << "Password : ";

    if(user == "admin"){
        current = l.first;
        while(current != nullptr){
            cout << current->karakter;
            current = current->next; 
        }
    }else if(user == "anonymous"){
        current = l.last;
        while(current != nullptr){
            cout << current->karakter;
            current = current->prev;
        }
    }
    cout << endl;
}

void enkripsi(List *l){
    if((*l).terenkripsi){
        cout << "Password sudah di enkripsi ! ";
    }else{
        address tmp;

        tmp=(*l).last->prev->prev;

        (*l).last->prev->prev = (*l).last->prev->prev->prev;
        (*l).first->next->next->next = (*l).last->prev->prev;
    

        cout << "Password berhasil di enkripsi" << endl;
    }    
}

void deskripsi(List *l){
    if(!(*l).terenkripsi){
        cout << "Password sudah di deskripsi !" << endl;
    }else {
        address temp;
        address curr;

        (*l).pass->prev = (*l).last->prev; 
        (*l).last->prev->next = (*l).pass;
        (*l).last->prev = nullptr;

        curr = (*l).last;
        (*l).last = (*l).pass;
        (*l).pass = curr;

        temp = (*l).last->prev->prev;
        temp->prev = temp->next;
        (*l).last->next = temp;
        temp->prev = (*l).last;
        temp = (*l).last;
        (*l).last->next = nullptr;

        (*l).pass->prev = (*l).last->prev;
        (*l).last->prev->next = (*l).pass;
        (*l).last->prev = nullptr;

        (*l).first = (*l).last->prev->prev;
        (*l).last = (*l).last->prev->prev->prev;

        (*l).first->prev = nullptr;
        (*l).last->next = nullptr;

        (*l).terenkripsi =false;

        cout << "Password berhasil di deskripsi !" << endl;
    }
}

void deletePassword(List *L){
    if((*L).size > 0){
        address temp, curr;
        curr = (*L).first;

        while(curr){
            temp = curr;
            curr = curr->next;
            delete temp;
        }
        (*L).first = nullptr;
        (*L).last = nullptr;
        (*L).size = 0;
        (*L).terenkripsi = false; 

    }
}

void inputPassword(List *L){
    string password;

    do{
        cout << "Masukkan Password (minimal 6 karakter) : ";
        cin >> password;

            if(password.length() < 6){
                cout << "Password anda tidak memenuhi !\n";
            }
    } while (password.length() < 6);

        for(int i = 0; i < password.length(); i++){
            addLast(L,password[i]);
        }

        cout << "Berhasil membuat password baru!\n";
}

void login(string* user, List pass){
    if(*user == "admin"){
        cout << "Anda sudah login!\n";
        return;
    }

    string passInput;
    cout << "Masukkan password (minimal 6 karakter) :  ";
    cin >> passInput;

    if(passInput.length() < 6){
        cout << "Password salah!\n";
    }else {
        address curr = pass.first;
        int counter = 0;

        while (curr){
            if(passInput[counter]!= curr->karakter){
                cout << "Password salah!\n";
                return ;
            }
            curr = curr->next;
            counter++;
        }
        cout << "Password benar, selamat datang!\n";
        *user = "admin";
    }
}

void logout(string* user){
    if(*user == "anonymous"){
        cout << "Anda sudah logout!\n";
    }else{
        cout << "Berhasil logout, selamat tinggal";
        *user = "anonymous";
    }
}


int main(){
    List password;
    createEmpty(&password);

    cout << "Selamat datang di program ADD ON 2"<<endl;
    cout << "Silahkan membuat password baru !\n";
    inputPassword(&password);

    char pilihan;
    string username = "admin";

        do{
        cout << "===============================\n";
        cout << "         PROGRAM ADD ON 2      \n";
        cout << "===============================\n";
        cout << "Username : " << username << endl;
        cout << "===============================\n";
        cout << "1. Login\n";
        cout << "2. Tampilkan password\n";
        cout << "3. Ubah password\n";
        cout << "4. Enkripsi password\n";
        cout << "5. Dekripsi password\n";
        cout << "6. Logout\n";
        cout << "7. Keluar\n";
        cout << "===============================\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;

        switch(pilihan){
        case '1' :
            login(&username, password);
            break;
        case '2' :
            showPassword(password, username);
            break;
        case '3' : 
            deletePassword(&password);
            inputPassword(&password);
            break;
        case '4' :
            enkripsi(&password);
            break;
        case '5' :
            deskripsi(&password);
            break;
        case '6' :
            logout(&username);
            break;
        case '7' :
            cout << "MAACIW DAH MAMPIR !!!";
            break;
        } 
    }while(pilihan != '7');

    
    return 0;
}