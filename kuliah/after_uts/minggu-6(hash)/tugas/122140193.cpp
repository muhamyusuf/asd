#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Node {
    int key;
    string value;
    Node* next;
    Node* prev;
};

class HashTable {
    
private:
    static const int tableSize = 10;
    vector<Node*> hashTable;
    
public:
    HashTable() : hashTable(tableSize, nullptr){}
    
    void InitializeHashTable() {
        for (int i = 0; i < tableSize; i++) {
            hashTable[i] = nullptr;
        }
        cout << "Hash Table masih kosong" << endl;
        cout << "---------------------------" << endl;
    }
    
    Node* AllocateNode(int key, const string& value) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    void DeallocateNode(Node* node) {
        delete node;
    }
    
    bool IsEmptyFirst() {
        return hashTable[0] == nullptr;
    }

    void Insert(int key, const string& value) {
        int index = key % tableSize;
        Node* newNode = AllocateNode(key, value);
        
        if (hashTable[index] == nullptr) {
            hashTable[index] = newNode;
        } else {
            newNode->next = hashTable[index];
            hashTable[index]->prev = newNode;
            hashTable[index] = newNode;
        }
        
        cout << "Key : " << key << "\nValue : " << value << "\nBerada di Hash : " << index << endl;
        DisplayHashTable();
    }

    void Delete(int key) {
        int index = key % tableSize;
        
        Node* current = hashTable[index];
        
        while (current != nullptr && current->key != key) {
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "Key " << key << " tidak ditemukan di Hash Table" << endl;
        } else {
            if (current->prev == nullptr) {
                hashTable[index] = current->next;
                if (current->next != nullptr) {
                    current->next->prev = nullptr;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
            }
            
            DeallocateNode(current);
            cout << "Hapus Key " << key << " dari index " << index << endl;
        }
        
        DisplayHashTable();
    }

    void DisplayHashTable() {
        cout << "Hash Table : " << endl;
        cout << "---------------------------" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << "Index-" << i << " : ";
            if (hashTable[i] == nullptr) {
                cout << "Kosong";
            } else {
                Node* current = hashTable[i];
                while (current != nullptr) {
                    cout << "(" << current->key << ", " << current->value << ")";
                    current = current->next;
                    if (current != nullptr) {
                        cout << "->";
                    }
                }
            } 
            cout << endl;
        }
        cout << "---------------------------" << endl;
    }
};

int main() {
    HashTable hashTable;
    
    hashTable.InitializeHashTable();
    
    hashTable.Insert(100, "Joddy");
    hashTable.Insert(101, "Ardi");
    hashTable.Insert(202, "Budi");
    hashTable.Insert(303, "Charly");
    hashTable.Insert(404, "Doddy");
    hashTable.Insert(505, "Edi");
    hashTable.Insert(606, "Farhan");
    hashTable.Insert(707, "Gunawan");
    hashTable.Insert(808, "Harry");
    hashTable.Insert(909, "Indah");
    hashTable.Insert(109, "Inge");
    hashTable.Insert(209, "Ibnu");
    
    cout << "Apakah hash table kosong? " << (hashTable.IsEmptyFirst()? "Yes" : "No") << endl;
    
    hashTable.Delete(205);
    hashTable.Delete(200);

    return 0;
}
