#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Node {
    string nama_pekerjaan;
    int harga_pekerjaan;
    int hari, bulan, tahun;
    string status_pekerjaan;
    Node* next;
};

struct Stack {
    Node* top;
};

struct Queue {
    Node* front;
    Node* rear;
};

void initStack(Stack& s) {
    s.top = nullptr;
}

void push(Stack& s, Node* pekerjaan) {
    pekerjaan->next = s.top;
    s.top = pekerjaan;
}

void pop(Stack& s) {
    if (s.top == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }
    Node* temp = s.top;
    s.top = s.top->next;
    delete temp;
    cout << "Pekerjaan berhasil di-pop dari stack.\n";
}

void displayStack(Stack s) {
    if (s.top == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }
    Node* temp = s.top;
    while (temp != nullptr) {
        cout << "Nama Pekerjaan: " << temp->nama_pekerjaan << "\n";
        cout << "Harga: " << temp->harga_pekerjaan << "\n";
        cout << "Deadline: " << temp->hari << "/" << temp->bulan << "/" << temp->tahun << "\n";
        cout << "Status: " << temp->status_pekerjaan << "\n\n";
        temp = temp->next;
    }
}

void initQueue(Queue& q) {
    q.front = q.rear = nullptr;
}

void enqueue(Queue& q, Node* pekerjaan) {
    pekerjaan->next = nullptr;
    if (q.rear == nullptr) {
        q.front = q.rear = pekerjaan;
        return;
    }
    q.rear->next = pekerjaan;
    q.rear = pekerjaan;
}

void dequeue(Queue& q) {
    if (q.front == nullptr) {
        cout << "Queue kosong.\n";
        return;
    }
    Node* temp = q.front;
    q.front = q.front->next;
    if (q.front == nullptr) q.rear = nullptr;
    delete temp;
    cout << "Pekerjaan berhasil di-dequeue dari queue.\n";
}

void displayQueue(Queue q) {
    if (q.front == nullptr) {
        cout << "Queue kosong.\n";
        return;
    }
    Node* temp = q.front;
    while (temp != nullptr) {
        cout << "Nama Pekerjaan: " << temp->nama_pekerjaan << "\n";
        cout << "Harga: " << temp->harga_pekerjaan << "\n";
        cout << "Deadline: " << temp->hari << "/" << temp->bulan << "/" << temp->tahun << "\n";
        cout << "Status: " << temp->status_pekerjaan << "\n\n";
        temp = temp->next;
    }
}

void tambahPekerjaan(Node** kepala) {
    Node* node_baru = new Node();
    cout << "Masukkan nama pekerjaan: ";
    cin.ignore();
    getline(cin, node_baru->nama_pekerjaan);
    int harga;
    while (true) {
        cout << "Masukkan harga pekerjaan (integer positif): ";
        cin >> harga;
        if (cin.fail() || harga < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Harga harus berupa angka positif.\n";
        } else {
            node_baru->harga_pekerjaan = harga;
            break;
        }
    }
    while (true) {
        cout << "Masukkan deadline pekerjaan (hari): ";
        cin >> node_baru->hari;
        if (cin.fail() || node_baru->hari <= 0 || node_baru->hari > 31) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid.\n";
        } else break;
    }
    while (true) {
        cout << "Masukkan deadline pekerjaan (bulan): ";
        cin >> node_baru->bulan;
        if (cin.fail() || node_baru->bulan <= 0 || node_baru->bulan > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid.\n";
        } else break;
    }
    while (true) {
        cout << "Masukkan deadline pekerjaan (tahun): ";
        cin >> node_baru->tahun;
        if (cin.fail() || node_baru->tahun < 2023) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid.\n";
        } else break;
    }
    cin.ignore();
    string status;
    do {
        cout << "Masukkan status pekerjaan (On Process/Done): ";
        getline(cin, status);
        if (status != "On Process" && status != "Done") {
            cout << "Status tidak valid.\n";
        }
    } while (status != "On Process" && status != "Done");
    node_baru->status_pekerjaan = status;
    node_baru->next = nullptr;
    if (*kepala == nullptr) {
        *kepala = node_baru;
    } else {
        Node* temp = *kepala;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = node_baru;
    }
    cout << "Pekerjaan berhasil ditambahkan!\n";
}

void tampilkanPekerjaan(Node* kepala) {
    if (kepala == nullptr) {
        cout << "Tidak ada pekerjaan yang tersedia.\n";
        return;
    }
    Node* temp = kepala;
    int nomor = 1;
    while (temp != nullptr) {
        cout << "Pekerjaan #" << nomor++ << "\n";
        cout << "Nama Pekerjaan: " << temp->nama_pekerjaan << "\n";
        cout << "Harga: " << temp->harga_pekerjaan << "\n";
        cout << "Deadline: " << temp->hari << "/" << temp->bulan << "/" << temp->tahun << "\n";
        cout << "Status: " << temp->status_pekerjaan << "\n\n";
        temp = temp->next;
    }
}

int main() {
    Node* daftar_pekerjaan = nullptr;
    Stack pekerjaanStack;
    Queue pekerjaanQueue;
    initStack(pekerjaanStack);
    initQueue(pekerjaanQueue);
    int pilihan;
    do {
        cout << "\nSistem Manajemen Vendor Photography\n";
        cout << "1. Tambah Pekerjaan\n";
        cout << "2. Tampilkan Pekerjaan\n";
        cout << "3. Push ke Stack\n";
        cout << "4. Pop dari Stack\n";
        cout << "5. Tampilkan Stack\n";
        cout << "6. Enqueue ke Queue\n";
        cout << "7. Dequeue dari Queue\n";
        cout << "8. Tampilkan Queue\n";
        cout << "9. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahPekerjaan(&daftar_pekerjaan);
                break;
            case 2:
                tampilkanPekerjaan(daftar_pekerjaan);
                break;
            case 3:
                if (daftar_pekerjaan != nullptr) push(pekerjaanStack, daftar_pekerjaan);
                break;
            case 4:
                pop(pekerjaanStack);
                break;
            case 5:
                displayStack(pekerjaanStack);
                break;
            case 6:
                if (daftar_pekerjaan != nullptr) enqueue(pekerjaanQueue, daftar_pekerjaan);
                break;
            case 7:
                dequeue(pekerjaanQueue);
                break;
            case 8:
                displayQueue(pekerjaanQueue);
                break;
            case 9:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid.\n";
        }
    } while (pilihan != 9);
    return 0;
}
