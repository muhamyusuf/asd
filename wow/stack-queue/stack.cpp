#include <iostream>
using namespace std;

#define MAX 50

struct initStack{
    int data[MAX];
    int top;
} Tumpukan;

const int NIM = 146;

void init(){
    Tumpukan.top = -1;
}

bool isEmpty(){
    return Tumpukan.top == -1;
}

bool isFull(){
    return Tumpukan.top == MAX - 1;
}

void Push(int x){
    if (isFull()){
        cout << "\nTumpukan penuh" << endl;
    }else{
        Tumpukan.top++;
        Tumpukan.data[Tumpukan.top] = x;
    }
}

void Pop(){
    if (isEmpty()){
        cout << "\nData kosong\n"<< endl;
    }else{
        Tumpukan.top--;
    }
}

void printStack(){
    int sum = 0; // Variabel untuk menghitung total

    for (int i = Tumpukan.top; i >= 0; i--){
        sum += Tumpukan.data[i];
    }
    
    cout << sum << endl;
}

void eksekusi(int nilai){
    if (nilai >= 70){
        Push(nilai + NIM);

        return;
    }

    if (nilai >= 50){
        Push(nilai);
    }else if (nilai < 50 && !isEmpty()){
        Pop();
    }
}

int main(){
    int nilai[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size = sizeof(nilai) / sizeof(nilai[0]);

    init();

    for (int i = 0; i < size; i++){
        eksekusi(nilai[i]);
    }

    printStack();
    return 0;
}
