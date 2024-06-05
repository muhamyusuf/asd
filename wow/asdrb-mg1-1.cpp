#include <iostream>
using namespace std;

struct Mahasiswa
{
    string Nama;
    string NIM;
    string Kelas;
    int Nilai;
    Mahasiswa *next;
};

void InsertFirst(Mahasiswa *&head, const string &nama, const string &nim, const string &kelas, int nilai)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->Nama = nama;
    newNode->NIM = nim;
    newNode->Kelas = kelas;
    newNode->Nilai = nilai;
    newNode->next = head;
    head = newNode;
}

void InsertLast(Mahasiswa *&head, const string &nama, const string &nim, const string &kelas, int nilai)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->Nama = nama;
    newNode->NIM = nim;
    newNode->Kelas = kelas;
    newNode->Nilai = nilai;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Mahasiswa *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertMiddle(Mahasiswa *&head, const string &nama, const string &nim, const string &kelas, int nilai)
{
    Mahasiswa *newNode = new Mahasiswa;
    newNode->Nama = nama;
    newNode->NIM = nim;
    newNode->Kelas = kelas;
    newNode->Nilai = nilai;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
        return;
    }

    Mahasiswa *temp = head;
    Mahasiswa *prev = nullptr;

    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    int middle = count / 2;

    temp = head;
    for (int i = 0; i < middle; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = newNode;
    newNode->next = temp;
}

void PrintList(Mahasiswa *head)
{
    Mahasiswa *temp = head;
    while (temp != nullptr)
    {
        cout << "Nama: " << temp->Nama << ", NIM: " << temp->NIM << ", Kelas: " << temp->Kelas << ", Nilai: " << temp->Nilai << endl;
        temp = temp->next;
    }
}

void SearchByNIM(Mahasiswa *head, const string &nim)
{
    Mahasiswa *temp = head;
    bool found = false;
    while (temp != nullptr)
    {
        if (temp->NIM == nim)
        {
            cout << "Data ditemukan:" << endl;
            cout << "Nama: " << temp->Nama << ", NIM: " << temp->NIM << ", Kelas: " << temp->Kelas << ", Nilai: " << temp->Nilai << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found)
    {
        cout << "Data dengan NIM " << nim << " tidak ditemukan." << endl;
    }
}

void SortByNilaiDescending(Mahasiswa *&head)
{
    Mahasiswa *current = head;
    Mahasiswa *index = nullptr;

    if (head == nullptr)
    {
        return;
    }
    else
    {
        while (current != nullptr)
        {
            index = current->next;
            while (index != nullptr)
            {
                if (current->Nilai < index->Nilai)
                {
                    int tempNilai = current->Nilai;
                    string tempNama = current->Nama;
                    string tempNIM = current->NIM;
                    string tempKelas = current->Kelas;

                    current->Nilai = index->Nilai;
                    current->Nama = index->Nama;
                    current->NIM = index->NIM;
                    current->Kelas = index->Kelas;

                    index->Nilai = tempNilai;
                    index->Nama = tempNama;
                    index->NIM = tempNIM;
                    index->Kelas = tempKelas;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void yaHapus(Mahasiswa *&head)
{
    Mahasiswa *current = head;
    Mahasiswa *prev = nullptr;

    while (current != nullptr)
    {
        if (current->Nilai < 50)
        {
            if (prev != nullptr)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                head = current->next;
                delete current;
                current = head;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void menu(Mahasiswa *&head)
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert Middle\n";
        cout << "4. Search by NIM\n";
        cout << "5. Sort by Nilai Descending\n";
        cout << "6. Hapus data dengan nilai UTS < 50\n";
        cout << "7. Print List\n";
        cout << "8. Exit\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string nama, nim, kelas;
            int nilai;
            cout << "Masukkan data mahasiswa:\n";
            cout << "Nama: ";
            cin >> nama;
            cout << "NIM: ";
            cin >> nim;
            cout << "Kelas: ";
            cin >> kelas;
            cout << "Nilai: ";
            cin >> nilai;
            InsertFirst(head, nama, nim, kelas, nilai);
            break;
        }
        case 2:
        {
            string nama, nim, kelas;
            int nilai;
            cout << "Masukkan data mahasiswa:\n";
            cout << "Nama: ";
            cin >> nama;
            cout << "NIM: ";
            cin >> nim;
            cout << "Kelas: ";
            cin >> kelas;
            cout << "Nilai: ";
            cin >> nilai;
            InsertLast(head, nama, nim, kelas, nilai);
            break;
        }
        case 3:
        {
            string nama, nim, kelas;
            int nilai;
            cout << "Masukkan data mahasiswa:\n";
            cout << "Nama: ";
            cin >> nama;
            cout << "NIM: ";
            cin >> nim;
            cout << "Kelas: ";
            cin >> kelas;
            cout << "Nilai: ";
            cin >> nilai;
            InsertMiddle(head, nama, nim, kelas, nilai);
            break;
        }
        case 4:
        {
            string nim;
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> nim;
            SearchByNIM(head, nim);
            break;
        }
        case 5:
        {
            SortByNilaiDescending(head);
            cout << "Data UTS setelah pengurutan:" << endl;
            PrintList(head);
            break;
        }
        case 6:
        {
            yaHapus(head);
            cout << "Data UTS setelah penghapusan:" << endl;
            PrintList(head);
            break;
        }
        case 7:
        {
            cout << "Data UTS:" << endl;
            PrintList(head);
            break;
        }
        case 8:
        {
            cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
        }
        default:
        {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
        }
    } while (choice != 8);
}

int main()
{
    Mahasiswa *UTSList = nullptr;

    InsertLast(UTSList, "Dicky", "122140141", "RB", 40);
    InsertLast(UTSList, "Adrian", "122140139", "RB", 50);

    menu(UTSList);

    return 0;
}
