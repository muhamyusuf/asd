#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Node{
    int key;
    string value;
    Node* next;
    Node* prev;
};

class HashTable{
    
private:
    static const int tableSize = 10;
    vector<Node*> table;
    
public:
    HashTable() : table(tableSize, nullptr){}
    
    void CreateEmptyHash(){
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
        cout<<"Hash Table masih kosong"<<endl;
        cout<<"---------------------------"<<endl;
    }
    
    Node* NodeAllocation(int key, const string& value){
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        return newNode;
    }

    void NodeDeallocation(Node* node){
        delete node;
    }
    
    bool IsEmptyFirst(){
        return table[0] == nullptr;
    }

    void Insert(int key, const string& value){
        int index = key % tableSize;
        Node* newNode = NodeAllocation(key, value);
        
        if(table[index] == nullptr){
            table[index] = newNode;
        } else {
            newNode->next = table[index];
            table[index]->prev = newNode;  // Tambahkan pointer prev pada node sebelumnya
            table[index] = newNode;
        }
        
        cout<<"Key : "<<key<<"\nvalue : "<<value<<"\nberada di Hash : "<<index<<endl;
        Display();
    }

    void Delete(int key){
        int index = key %tableSize;
        
        Node* current = table[index];
        
        while(current != nullptr && current->key != key){
            current = current->next;
        }
        
        if(current == nullptr){
            cout<<"Key "<<key<<" tidak ditemukan di Hash Table"<<endl;
        } else {
            if(current->prev == nullptr){
                table[index] = current->next;
                if (current->next != nullptr) {
                    current->next->prev = nullptr;
                }
            } else {
                current->prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
            }
            
            NodeDeallocation(current);
            cout<<"Hapus Key "<<key<<" dari index "<<index<<endl;
        }
        
        Display();
    }

    void Display(){
        cout<<"Hash Table : "<<endl;
        cout<<"---------------------------"<<endl;
        for (int i = 0; i < tableSize; i++) {
            cout<<"Index-"<<i<<" : ";
            if(table[i] == nullptr){
                cout<<"Kosong";
            } else {
                Node* current = table[i];
                while (current != nullptr){
                    cout<<"("<<current->key <<", "<< current->value <<")";
                    current = current->next;
                    if(current != nullptr){
                        cout<<"->";
                    }
                }
            } 
            cout<<endl;
        }
        cout<<"---------------------------"<<endl;
    }
};

int main(){
    HashTable hashTable;
    
    hashTable.CreateEmptyHash();
    
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
    
    
    cout<<"Apakah hash table kosong? "<<(hashTable.IsEmptyFirst()? "Yes" : "No")<<endl;
    
    hashTable.Delete(205);
    hashTable.Delete(200);

    return 0;
}
