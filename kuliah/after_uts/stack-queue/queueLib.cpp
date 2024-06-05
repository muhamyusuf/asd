#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Enqueue (menambahkan) elemen ke dalam queue
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // Mengakses elemen pertama
    std::cout << "Elemen pertama: " << myQueue.front() << std::endl;

    // Menghapus elemen pertama
    myQueue.pop();

    // Ukuran queue
    std::cout << "Ukuran queue: " << myQueue.size() << std::endl;

    // Mencetak elemen-elemen queue
    std::cout << "Isi queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }

    return 0;
}
