#include <iostream>
#include <string>
using namespace std;

struct AnggotaKeluarga
{
    string Nama;
    char JenisKelamin;
    int Usia;
    string Pekerjaan;
    AnggotaKeluarga *next;
};

// Fungsi untuk memasukkan anggota keluarga di awal list
void InsertFirst(AnggotaKeluarga *&head, string Nama, char JenisKelamin, int Usia, string Pekerjaan)
{
    AnggotaKeluarga *newNode = new AnggotaKeluarga;
    newNode->Nama = Nama;
    newNode->JenisKelamin = JenisKelamin;
    newNode->Usia = Usia;
    newNode->Pekerjaan = Pekerjaan;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk memasukkan anggota keluarga setelah anggota tertentu
void InsertAfter(AnggotaKeluarga *prevNode, string Nama, char JenisKelamin, int Usia, string Pekerjaan)
{
    if (prevNode == nullptr)
    {
        cout << "Node sebelumnya tidak ditemukan." << endl;
        return;
    }
    AnggotaKeluarga *newNode = new AnggotaKeluarga;
    newNode->Nama = Nama;
    newNode->JenisKelamin = JenisKelamin;
    newNode->Usia = Usia;
    newNode->Pekerjaan = Pekerjaan;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Fungsi untuk memasukkan anggota keluarga di akhir list
void InsertLast(AnggotaKeluarga *&head, string Nama, char JenisKelamin, int Usia, string Pekerjaan)
{
    AnggotaKeluarga *newNode = new AnggotaKeluarga;
    newNode->Nama = Nama;
    newNode->JenisKelamin = JenisKelamin;
    newNode->Usia = Usia;
    newNode->Pekerjaan = Pekerjaan;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    AnggotaKeluarga *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
}

// Fungsi untuk mencetak daftar anggota keluarga
void PrintList(AnggotaKeluarga *head)
{
    AnggotaKeluarga *current = head;
    while (current != nullptr)
    {
        cout << "Nama: " << current->Nama << ", Jenis Kelamin: " << current->JenisKelamin
             << ", Usia: " << current->Usia << ", Pekerjaan: " << current->Pekerjaan << endl;
        current = current->next;
    }
}

// Fungsi untuk menggabungkan dua list dan mengurutkannya berdasarkan usia
AnggotaKeluarga *MergeAndSortLists(AnggotaKeluarga *list1, AnggotaKeluarga *list2)
{
    AnggotaKeluarga *mergedList = nullptr;

    while (list1 != nullptr || list2 != nullptr)
    {
        AnggotaKeluarga *temp = nullptr;

        if (list1 == nullptr)
        {
            temp = list2;
            list2 = list2->next;
        }
        else if (list2 == nullptr)
        {
            temp = list1;
            list1 = list1->next;
        }
        else if (list1->Usia > list2->Usia)
        {
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp = list2;
            list2 = list2->next;
        }

        temp->next = mergedList;
        mergedList = temp;
    }

    return mergedList;
}

// Fungsi untuk mencari dan menampilkan data orang yang sudah bekerja dan berjenis kelamin laki-laki
void SearchAndPrintMaleWorking(AnggotaKeluarga *head)
{
    AnggotaKeluarga *current = head;
    bool found = false;

    while (current != nullptr)
    {
        if (current->JenisKelamin == 'L' && current->Pekerjaan != "")
        {
            cout << "Nama: " << current->Nama << ", Jenis Kelamin: " << current->JenisKelamin
                 << ", Usia: " << current->Usia << ", Pekerjaan: " << current->Pekerjaan << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Tidak ditemukan anggota keluarga laki-laki yang sudah bekerja." << endl;
    }
}

// Fungsi untuk mencari dan menampilkan data orang yang belum bekerja
void SearchAndPrintUnemployed(AnggotaKeluarga *head)
{
    AnggotaKeluarga *current = head;
    bool found = false;

    while (current != nullptr)
    {
        if (current->Pekerjaan == "")
        {
            cout << "Nama: " << current->Nama << ", Jenis Kelamin: " << current->JenisKelamin
                 << ", Usia: " << current->Usia << ", Pekerjaan: " << current->Pekerjaan << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Tidak ditemukan anggota keluarga yang belum bekerja." << endl;
    }
}

// Fungsi untuk melakukan inversi dari penggabungan data, kemudian tampilkan hasilnya
void ReverseList(AnggotaKeluarga *&head)
{
    AnggotaKeluarga *prev = nullptr;
    AnggotaKeluarga *current = head;
    AnggotaKeluarga *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// Fungsi "delete" untuk menghapus data yang ingin dihapus oleh user
void DeleteNode(AnggotaKeluarga *&head, string Nama)
{
    AnggotaKeluarga *temp = head;
    AnggotaKeluarga *prev = nullptr;

    // Jika data yang ingin dihapus berada di awal list
    if (temp != nullptr && temp->Nama == Nama)
    {
        head = temp->next;
        delete temp;
        return;
    }

    // Mencari data yang ingin dihapus
    while (temp != nullptr && temp->Nama != Nama)
    {
        prev = temp;
        temp = temp->next;
    }

    // Jika data yang ingin dihapus tidak ditemukan
    if (temp == nullptr)
    {
        cout << "Data tidak ditemukan." << endl;
        return;
    }

    // Menghapus data yang ditemukan
    prev->next = temp->next;
    delete temp;
}

void SortByAge(AnggotaKeluarga *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        // Tidak perlu mengurutkan jika daftar kosong atau hanya memiliki satu elemen
        return;
    }

    AnggotaKeluarga *current, *nextNode;
    bool swapped;

    do
    {
        swapped = false;
        current = head;
        while (current->next != nullptr)
        {
            nextNode = current->next;
            if (current->Usia < nextNode->Usia)
            {
                // Tukar posisi jika usia saat ini kurang dari usia berikutnya
                swap(current->Nama, nextNode->Nama);
                swap(current->JenisKelamin, nextNode->JenisKelamin);
                swap(current->Usia, nextNode->Usia);
                swap(current->Pekerjaan, nextNode->Pekerjaan);
                swapped = true;
            }
            current = nextNode;
        }
    } while (swapped);
}

// Fungsi untuk menampilkan menu
void ShowMenu(AnggotaKeluarga *&List1, AnggotaKeluarga *&List2)
{
    int choice;
    string Nama;
    AnggotaKeluarga *mergedList = MergeAndSortLists(List1, List2); // Gabungkan dan urutkan list di awal

    do
    {
        cout << "\nMenu:" << endl;
        cout << "1. Tampilkan data anggota keluarga laki-laki yang sudah bekerja" << endl;
        cout << "2. Tampilkan data anggota keluarga yang belum bekerja" << endl;
        cout << "3. Inversi penggabungan data" << endl;
        cout << "4. Hapus data" << endl;
        cout << "5. Sorting dari umur terbesar" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nData anggota keluarga laki-laki yang sudah bekerja:" << endl;
            SearchAndPrintMaleWorking(mergedList);
            break;
        case 2:
            cout << "\nData anggota keluarga yang belum bekerja:" << endl;
            SearchAndPrintUnemployed(mergedList);
            break;
        case 3:
            cout << "\nInversi penggabungan data:" << endl;
            ReverseList(mergedList);
            PrintList(mergedList);
            break;
        case 4:
            cout << "\nHapus data:" << endl;
            cout << "Masukkan nama anggota keluarga yang ingin dihapus: ";
            cin >> Nama;
            DeleteNode(mergedList, Nama);
            cout << "Data berhasil dihapus." << endl;
            cout << "Data terbaru:" << endl;
            PrintList(mergedList);
            break;
        case 5:
            cout << "\nSorting dari umur terbesar:" << endl;
            SortByAge(mergedList);
            PrintList(mergedList);
            break;
        case 6:
            cout << "\nTerima kasih telah menggunakan program ini." << endl;
            break;
        default:
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
    } while (choice != 6);
}

int main()
{
    AnggotaKeluarga *List1 = nullptr;
    AnggotaKeluarga *List2 = nullptr;

    // Menambahkan anggota keluarga ke List1
    InsertFirst(List1, "Anton", 'L', 50, "Polisi");
    InsertLast(List1, "Dhea", 'W', 14, "Pelajar");
    InsertLast(List1, "Hadi", 'L', 20, "Mahasiswa");
    InsertLast(List1, "Wira", 'L', 25, "TNI");
    InsertLast(List1, "Mikha", 'W', 17, "Pelajar");

    // Menambahkan anggota keluarga ke List2
    InsertFirst(List2, "Surti", 'W', 47, "Guru");
    InsertLast(List2, "Dila", 'W', 16, "Pelajar");
    InsertLast(List2, "Dirga", 'L', 21, "Mahasiswa");
    InsertLast(List2, "Rudi", 'L', 10, "Pelajar");
    InsertLast(List2, "Lia", 'W', 13, "Pelajar");

    // Menampilkan List1 dan List2
    cout << "List1 (Keluarga Anton):" << endl;
    PrintList(List1);

    cout << "\nList2 (Keluarga Surti):" << endl;
    PrintList(List2);

    // Menampilkan menu
    ShowMenu(List1, List2);

    return 0;
}
