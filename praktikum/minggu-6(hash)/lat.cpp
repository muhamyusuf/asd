#include <iostream>
using namespace std;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(H,i) (H)[i].first

typedef int infotype; // Tambahkan definisi infotype
const int MaxEl = 26; // Tambahkan definisi MaxEl

typedef struct Tnode *addressNode;
typedef struct Tnode{
    infotype info; // Ganti string menjadi int
    addressNode next; // Ganti string menjadi addressNode
}Node;

typedef struct THash *addressHash;
typedef struct THash{
    addressNode first;
}Hash;

void createEmptyHash(addressHash HashTable){
    for(int i=0;i<MaxEl;i++){ // Ganti 26 menjadi MaxEl
        First(HashTable,i) = NULL;
    }
}

addressNode NodeAllocation(infotype x){
    addressNode NewNode;

    NewNode = new Node;
    Info(NewNode) = x;
    Next(NewNode) = NULL;

    return NewNode;
}

bool isEmptyFirst(addressNode First_Node){
    return (First_Node == NULL);
}

void NodeDeallocation(addressNode hapus){
    delete hapus;
}

void insertFirst(addressNode *First_Node, infotype x){
    addressNode NewNode = NodeAllocation(x);
    Next(NewNode) = *First_Node;
    *First_Node = NewNode;
}

void insertLast(addressNode *First_Node, infotype x){
    addressNode NewNode = NodeAllocation(x), temp = *First_Node;

    if (*First_Node == NULL) {
        *First_Node = NewNode;
    } else {
        while (Next(temp) != NULL) {
            temp = Next(temp);
        }

        Next(temp) = NewNode;
    }
}

void deleteFirst(addressNode *First_Node){
    addressNode temp;

    temp = *First_Node;
    *First_Node = Next(*First_Node);
    Next(temp) = NULL;

    NodeDeallocation(temp);
}

void deleteAfter(addressNode *Pred){
    addressNode temp;

    temp = Next(*Pred);
    Next(*Pred) = Next(temp);

    NodeDeallocation(temp);
}

void deleteLast(addressNode *First_Node){
    addressNode temp, predTemp;

    predTemp = NULL;
    temp = *First_Node;

    while (Next(temp) != NULL) {
        predTemp = temp;
        temp = Next(temp);
    }

    if (predTemp == NULL) {
        *First_Node = NULL;
    } else {
        deleteAfter(&predTemp);
    }
}

void insertByModFunc(addressHash HashTable, infotype x){
    int index = x % MaxEl;
    addressNode *First_Node = &First(HashTable,index);

    if (isEmptyFirst(*First_Node))
        insertFirst(First_Node, x);
    else
        insertLast(First_Node, x);
}

void printHashTable(addressHash HashTable){
    for (int i = 0; i < MaxEl; i++) {
        addressNode temp = First(HashTable, i);
        cout << "[" << i << "]: ";
        while (temp != NULL) {
            cout << Info(temp) << " -> ";
            temp = Next(temp);
        }
        cout << "NULL" << endl;
    }
}

int main(){
    addressHash HashTable;
    createEmptyHash(HashTable);

    // Contoh penggunaan fungsi insertByModFunc
    insertByModFunc(HashTable, 15);
    insertByModFunc(HashTable, 27);
    insertByModFunc(HashTable, 42);

    // Contoh penggunaan fungsi deleteFirst
    deleteFirst(&First(HashTable, 1));

    // Contoh penggunaan fungsi deleteLast
    deleteLast(&First(HashTable, 0));

    // Contoh penggunaan fungsi insertFirst
    insertFirst(&First(HashTable, 2), 8);

    // Contoh penggunaan fungsi insertLast
    insertLast(&First(HashTable, 0), 33);

    // Contoh penggunaan fungsi printHashTable
    printHashTable(HashTable);

    return 0;
}
