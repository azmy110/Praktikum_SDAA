#include <iostream>
#include <string>
#include <limits> // untuk cin.clear() dan cin.ignore()
using namespace std;

// Struktur untuk setiap node dalam linked list
struct Node {
    string nama_pekerjaan;
    int harga_pekerjaan;
    int hari, bulan, tahun;
    string status_pekerjaan;
    Node* next; // Pointer ke node berikutnya
};

// Fungsi untuk menambahkan pekerjaan ke linked list
void tambahPekerjaan(Node** kepala) {
    Node* node_baru = new Node();
    cout << "Masukkan nama pekerjaan: ";
    cin.ignore(); // Mengabaikan karakter sebelumnya
    getline(cin, node_baru->nama_pekerjaan);

    // Validasi input harga (hanya integer)
    int harga;
    while (true) {
        cout << "Masukkan harga pekerjaan (integer positif): ";
        cin >> harga;
        if (cin.fail() || harga < 0) {
            cin.clear(); // Menghapus error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan input yang salah
            cout << "Input tidak valid. Harga harus berupa angka positif.\n";
        } else {
            node_baru->harga_pekerjaan = harga;
            break;
        }
    }

    // Validasi input tanggal
    while (true) {
        cout << "Masukkan deadline pekerjaan (hari): ";
        cin >> node_baru->hari;
        if (cin.fail() || node_baru->hari <= 0 || node_baru->hari > 31) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Hari harus berupa angka antara 1-31.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Masukkan deadline pekerjaan (bulan): ";
        cin >> node_baru->bulan;
        if (cin.fail() || node_baru->bulan <= 0 || node_baru->bulan > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Bulan harus berupa angka antara 1-12.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Masukkan deadline pekerjaan (tahun): ";
        cin >> node_baru->tahun;
        if (cin.fail() || node_baru->tahun < 2023) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Tahun harus berupa angka lebih dari atau sama dengan 2023.\n";
        } else {
            break;
        }
    }

    cin.ignore(); // Menjaga agar buffer bersih sebelum menerima string berikutnya

    // Validasi status pekerjaan
    string status;
    do {
        cout << "Masukkan status pekerjaan (On Process/Done): ";
        getline(cin, status);
        if (status != "On Process" && status != "Done") {
            cout << "Status tidak valid. Coba lagi.\n";
        }
    } while (status != "On Process" && status != "Done");

    node_baru->status_pekerjaan = status;
    node_baru->next = nullptr; // Inisialisasi pointer next ke null

    // Menambahkan node baru di akhir linked list
    if (*kepala == nullptr) {
        *kepala = node_baru; // Jika list kosong, node baru menjadi kepala
    } else {
        Node* temp = *kepala;
        while (temp->next != nullptr) {
            temp = temp->next; // Menavigasi ke akhir list
        }
        temp->next = node_baru; // Menambahkan node baru di akhir
    }

    cout << "Pekerjaan berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan pekerjaan
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
        cout << "Deadline: " << temp->hari << "/" 
             << temp->bulan << "/" << temp->tahun << "\n";
        cout << "Status: " << temp->status_pekerjaan << "\n\n";
        temp = temp->next; // Melanjutkan ke node berikutnya
    }
}

// Fungsi untuk mengubah pekerjaan
void ubahPekerjaan(Node* kepala) {
    int pilihan;
    cout << "Masukkan nomor pekerjaan yang ingin diubah: ";
    cin >> pilihan;

    Node* temp = kepala;
    for (int i = 1; i < pilihan && temp != nullptr; i++) {
        temp = temp->next; // Menavigasi ke node yang diinginkan
    }

    if (temp != nullptr) {
        cout << "Masukkan nama pekerjaan baru: ";
        cin.ignore(); // Menjaga buffer bersih
        getline(cin, temp->nama_pekerjaan);

        // Validasi harga baru
        int harga;
        while (true) {
            cout << "Masukkan harga baru (integer positif): ";
            cin >> harga;
            if (cin.fail() || harga < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Harga harus berupa angka positif.\n";
            } else {
                temp->harga_pekerjaan = harga;
                break;
            }
        }

        // Validasi tanggal baru
        while (true) {
            cout << "Masukkan hari baru: ";
            cin >> temp->hari;
            if (cin.fail() || temp->hari <= 0 || temp->hari > 31) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Hari harus berupa angka antara 1-31.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Masukkan bulan baru: ";
            cin >> temp->bulan;
            if (cin.fail() || temp->bulan <= 0 || temp->bulan > 12) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Bulan harus berupa angka antara 1-12.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Masukkan tahun baru: ";
            cin >> temp->tahun;
            if (cin.fail() || temp->tahun < 2023) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Tahun harus berupa angka lebih dari atau sama dengan 2023.\n";
            } else {
                break;
            }
        }

        cin.ignore(); // Bersihkan buffer sebelum input string

        // Validasi status baru
        string status;
        do {
            cout << "Masukkan status baru (On Process/Done): ";
            getline(cin, status);
            if (status != "On Process" && status != "Done") {
                cout << "Status tidak valid. Coba lagi.\n";
            }
        } while (status != "On Process" && status != "Done");

        temp->status_pekerjaan = status;

        cout << "Pekerjaan berhasil diubah!\n";
    } else {
        cout << "Pekerjaan tidak ditemukan!\n";
    }
}

// Fungsi untuk menghapus pekerjaan
void hapusPekerjaan(Node** kepala) {
    int pilihan;
    cout << "Masukkan nomor pekerjaan yang ingin dihapus: ";
    cin >> pilihan;

    if (*kepala == nullptr) {
        cout << "Tidak ada pekerjaan untuk dihapus.\n";
        return;
    }

    Node* temp = *kepala;
    if (pilihan == 1) { // Jika menghapus pekerjaan pertama
        *kepala = temp->next; // Mengubah kepala ke node berikutnya
        delete temp; // Menghapus node yang sudah tidak dibutuhkan
        cout << "Pekerjaan berhasil dihapus!\n";
        return;
    }

    Node* prev = nullptr;
    for (int i = 1; i < pilihan && temp != nullptr; i++) {
        prev = temp;
        temp = temp->next; // Menavigasi ke node yang diinginkan
    }

    if (temp != nullptr) {
        prev->next = temp->next; // Menghubungkan node sebelumnya dengan node berikutnya
        delete temp; // Menghapus node yang sudah tidak dibutuhkan
        cout << "Pekerjaan berhasil dihapus!\n";
    } else {
        cout << "Pekerjaan tidak ditemukan!\n";
    }
}

int main() {
    Node* daftar_pekerjaan = nullptr; // Kepala dari linked list
    int pilihan;

    do {
        cout << "\nSistem Manajemen Vendor Photography\n";
        cout << "1. Tambah Pekerjaan\n";
        cout << "2. Tampilkan Pekerjaan\n";
        cout << "3. Ubah Pekerjaan\n";
        cout << "4. Hapus Pekerjaan\n";
        cout << "5. Keluar\n";
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
                ubahPekerjaan(daftar_pekerjaan);
                break;
            case 4:
                hapusPekerjaan(&daftar_pekerjaan);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
