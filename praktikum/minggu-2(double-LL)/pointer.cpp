#include <iostream>
using namespace std;

int main() {
    int a = 5; // Variabel dengan nilai 5
    int* ptr;  // Pointer ke variabel integer

    cout<<"pointer ptr: "<<ptr<<endl;

    ptr = &a;  // Menginisialisasi pointer dengan alamat variabel 'a'

    cout << "Nilai variabel a: " << a << endl;
    cout << "Alamat variabel a: " << &a << endl;

    cout << "Nilai yang ditunjuk oleh pointer: " << *ptr << endl;
    cout << "Alamat yang ditunjuk oleh pointer: " << ptr << endl;

    // Mengubah nilai melalui pointer
    *ptr = 10;

    cout << "Nilai variabel a setelah diubah melalui pointer: " << a << endl;

    return 0;
}
