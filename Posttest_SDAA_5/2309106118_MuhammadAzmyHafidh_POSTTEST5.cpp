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

// Fungsi getTail untuk mendapatkan tail dari linked list
Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

// Fungsi quick sort untuk sorting descending
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, * cur = head, * tail = pivot;

    while (cur != pivot) {
        if (cur->harga_pekerjaan > pivot->harga_pekerjaan) {
            if ((*newHead) == nullptr) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr) (*newHead) = pivot;
    (*newEnd) = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;
    Node* newHead = nullptr, * newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* tmp = getTail(newHead);
        tmp->next = nullptr;
        newHead = quickSortRecur(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
}

int main() {
    Node* kepala = nullptr;
    int pilihan;
    do {
        cout << "1. Tambah Pekerjaan\n2. Tampilkan Pekerjaan\n3. Urutkan Pekerjaan\n4. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1:
            tambahPekerjaan(&kepala);
            break;
        case 2:
            tampilkanPekerjaan(kepala);
            break;
        case 3:
            quickSort(&kepala);
            cout << "Pekerjaan berhasil diurutkan.\n";
            break;
        case 4:
            cout << "Keluar.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);
    return 0;
}
