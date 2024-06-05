#include <iostream>
#include <string>
using namespace std;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(H, i) (H)[i].first

typedef string infotype;
const int MaxEl = 26;

typedef struct Tnode *addressNode;
typedef struct Tnode
{
    infotype info;
    addressNode next;
} Node;

typedef struct THash *addressHash;
typedef struct THash
{
    addressNode first;
} Hash;

void createEmptyHash(addressHash HashTable)
{
    for (int i = 0; i < MaxEl; i++)
    {
        First(HashTable, i) = NULL;
    }
}

addressNode NodeAllocation(infotype x)
{
    addressNode NewNode;

    NewNode = new Node;
    Info(NewNode) = x;
    Next(NewNode) = NULL;

    return NewNode;
}

bool isEmptyFirst(addressNode First_Node)
{
    return (First_Node == NULL);
}

void NodeDeallocation(addressNode hapus)
{
    delete hapus;
}

void insertFirst(addressNode *First_Node, infotype x)
{
    addressNode NewNode = NodeAllocation(x);
    Next(NewNode) = *First_Node;
    *First_Node = NewNode;
}

void insertLast(addressNode *First_Node, infotype x)
{
    addressNode NewNode = NodeAllocation(x), temp = *First_Node;

    if (*First_Node == NULL)
    {
        *First_Node = NewNode;
    }
    else
    {
        while (Next(temp) != NULL)
        {
            temp = Next(temp);
        }

        Next(temp) = NewNode;
    }
}

void deleteFirst(addressNode *First_Node)
{
    if (*First_Node != NULL)
    {
        addressNode temp;

        temp = *First_Node;
        *First_Node = Next(*First_Node);
        Next(temp) = NULL;

        NodeDeallocation(temp);
    }
}

void deleteAfter(addressNode *Pred)
{
    if (*Pred != NULL && Next(*Pred) != NULL)
    {
        addressNode temp;

        temp = Next(*Pred);
        Next(*Pred) = Next(temp);

        NodeDeallocation(temp);
    }
}

void deleteLast(addressNode *First_Node)
{
    if (*First_Node != NULL)
    {
        addressNode temp, predTemp;

        predTemp = NULL;
        temp = *First_Node;

        while (Next(temp) != NULL)
        {
            predTemp = temp;
            temp = Next(temp);
        }

        if (predTemp == NULL)
        {
            *First_Node = NULL;
        }
        else
        {
            deleteAfter(&predTemp);
        }
    }
}

void insertByModFunc(addressHash HashTable, infotype x)
{
    int index = x[0] - 'a'; // Menggunakan huruf pertama sebagai indeks
    addressNode *First_Node = &First(HashTable, index);

    if (isEmptyFirst(*First_Node))
    {
        insertFirst(First_Node, x);
    }
    else
    {
        insertLast(First_Node, x);
    }
}

void printHashTable(addressHash HashTable)
{
    for (int i = 0; i < MaxEl; i++)
    {
        addressNode temp = First(HashTable, i);
        cout << "[" << i << "]: ";

        while (temp != NULL)
        {
            cout << Info(temp) << " -> ";
            temp = Next(temp);
        }
        cout << "NULL" << endl;
    }
}

int main(){
    addressHash HashTable;
    HashTable = new Hash[MaxEl];
    createEmptyHash(HashTable);

    insertByModFunc(HashTable, "Budi");
    insertByModFunc(HashTable, "Siti");
    insertByModFunc(HashTable, "Rahmat");

    deleteFirst(&First(HashTable, 1));

    deleteLast(&First(HashTable, 0));

    insertFirst(&First(HashTable, 2), "Anita");

    insertLast(&First(HashTable, 0), "Joko");

    printHashTable(HashTable);

    delete[] HashTable;

    return 0;
}

