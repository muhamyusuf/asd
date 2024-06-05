#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;

    // Push elemen ke dalam stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Mengakses elemen paling atas
    cout << "Elemen paling atas: " << myStack.top() << endl;

    // print stack
    cout << "Isi stack sebelum menghapus elemen paling atas: ";

    while(!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    } // O(n

    cout << endl;

    // print stack setelah menghapus elemen paling atas
    cout << "Isi stack setelah menghapus elemen paling atas: ";
    

    // Ukuran stack
    cout << "Ukuran stack: " << myStack.size() << endl;

    return 0;
}
