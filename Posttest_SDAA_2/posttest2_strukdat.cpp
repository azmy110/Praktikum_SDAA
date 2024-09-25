#include <iostream>
#include <string>
#include <limits> // untuk cin.clear() dan cin.ignore()
using namespace std;

struct Pekerjaan {
    string nama_pekerjaan;
    int harga_pekerjaan;      // Harga hanya berupa integer
    int hari, bulan, tahun;   // Tanggal dipecah menjadi hari, bulan, tahun
    string status_pekerjaan;  // "On Process" atau "Done"
};

// Fungsi untuk validasi input status pekerjaan
bool validasiStatus(const string& status) {
    return status == "On Process" || status == "Done";
}

// Fungsi untuk menambah pekerjaan dengan validasi input angka
void tambahPekerjaan(Pekerjaan* daftar_pekerjaan, int* jumlah_pekerjaan) {
    cout << "Masukkan nama pekerjaan: ";
    cin.ignore(); // Mengabaikan karakter sebelumnya
    getline(cin, daftar_pekerjaan[*jumlah_pekerjaan].nama_pekerjaan);

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
            daftar_pekerjaan[*jumlah_pekerjaan].harga_pekerjaan = harga;
            break;
        }
    }

    // Validasi input tanggal (hari, bulan, tahun) hanya angka
    while (true) {
        cout << "Masukkan deadline pekerjaan (hari): ";
        cin >> daftar_pekerjaan[*jumlah_pekerjaan].hari;
        if (cin.fail() || daftar_pekerjaan[*jumlah_pekerjaan].hari <= 0 || daftar_pekerjaan[*jumlah_pekerjaan].hari > 31) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Hari harus berupa angka antara 1-31.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Masukkan deadline pekerjaan (bulan): ";
        cin >> daftar_pekerjaan[*jumlah_pekerjaan].bulan;
        if (cin.fail() || daftar_pekerjaan[*jumlah_pekerjaan].bulan <= 0 || daftar_pekerjaan[*jumlah_pekerjaan].bulan > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Bulan harus berupa angka antara 1-12.\n";
        } else {
            break;
        }
    }

    while (true) {
        cout << "Masukkan deadline pekerjaan (tahun): ";
        cin >> daftar_pekerjaan[*jumlah_pekerjaan].tahun;
        if (cin.fail() || daftar_pekerjaan[*jumlah_pekerjaan].tahun < 2023) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Tahun harus berupa angka lebih dari atau sama dengan 2023.\n";
        } else {
            break;
        }
    }

    cin.ignore(); // Menjaga agar buffer bersih sebelum menerima string berikutnya

    // Validasi status pekerjaan (hanya On Process atau Done)
    string status;
    do {
        cout << "Masukkan status pekerjaan (On Process/Done): ";
        getline(cin, status);
        if (!validasiStatus(status)) {
            cout << "Status tidak valid. Coba lagi.\n";
        }
    } while (!validasiStatus(status));
    daftar_pekerjaan[*jumlah_pekerjaan].status_pekerjaan = status;

    (*jumlah_pekerjaan)++;
    cout << "Pekerjaan berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan pekerjaan
void tampilkanPekerjaan(Pekerjaan* daftar_pekerjaan, int jumlah_pekerjaan) {
    if (jumlah_pekerjaan == 0) {
        cout << "Tidak ada pekerjaan yang tersedia.\n";
        return;
    }

    for (int i = 0; i < jumlah_pekerjaan; i++) {
        cout << "Pekerjaan #" << i + 1 << "\n";
        cout << "Nama Pekerjaan: " << daftar_pekerjaan[i].nama_pekerjaan << "\n";
        cout << "Harga: " << daftar_pekerjaan[i].harga_pekerjaan << "\n";
        cout << "Deadline: " << daftar_pekerjaan[i].hari << "/" 
             << daftar_pekerjaan[i].bulan << "/" << daftar_pekerjaan[i].tahun << "\n";
        cout << "Status: " << daftar_pekerjaan[i].status_pekerjaan << "\n\n";
    }
}

// Fungsi untuk mengubah pekerjaan
void ubahPekerjaan(Pekerjaan* daftar_pekerjaan, int jumlah_pekerjaan) {
    int pilihan;
    cout << "Masukkan nomor pekerjaan yang ingin diubah: ";
    cin >> pilihan;

    if (pilihan > 0 && pilihan <= jumlah_pekerjaan) {
        cout << "Masukkan nama pekerjaan baru: ";
        cin.ignore(); // Menjaga buffer bersih
        getline(cin, daftar_pekerjaan[pilihan - 1].nama_pekerjaan);

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
                daftar_pekerjaan[pilihan - 1].harga_pekerjaan = harga;
                break;
            }
        }

        // Validasi tanggal baru
        while (true) {
            cout << "Masukkan hari baru: ";
            cin >> daftar_pekerjaan[pilihan - 1].hari;
            if (cin.fail() || daftar_pekerjaan[pilihan - 1].hari <= 0 || daftar_pekerjaan[pilihan - 1].hari > 31) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Hari harus berupa angka antara 1-31.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Masukkan bulan baru: ";
            cin >> daftar_pekerjaan[pilihan - 1].bulan;
            if (cin.fail() || daftar_pekerjaan[pilihan - 1].bulan <= 0 || daftar_pekerjaan[pilihan - 1].bulan > 12) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Bulan harus berupa angka antara 1-12.\n";
            } else {
                break;
            }
        }

        while (true) {
            cout << "Masukkan tahun baru: ";
            cin >> daftar_pekerjaan[pilihan - 1].tahun;
            if (cin.fail() || daftar_pekerjaan[pilihan - 1].tahun < 2023) {
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
            if (!validasiStatus(status)) {
                cout << "Status tidak valid. Coba lagi.\n";
            }
        } while (!validasiStatus(status));
        daftar_pekerjaan[pilihan - 1].status_pekerjaan = status;

        cout << "Pekerjaan berhasil diubah!\n";
    } else {
        cout << "Pekerjaan tidak ditemukan!\n";
    }
}

// Fungsi untuk menghapus pekerjaan
void hapusPekerjaan(Pekerjaan* daftar_pekerjaan, int* jumlah_pekerjaan) {
    int pilihan;
    cout << "Masukkan nomor pekerjaan yang ingin dihapus: ";
    cin >> pilihan;

    if (pilihan > 0 && pilihan <= *jumlah_pekerjaan) {
        for (int i = pilihan - 1; i < *jumlah_pekerjaan - 1; i++) {
            daftar_pekerjaan[i] = daftar_pekerjaan[i + 1];
        }
        (*jumlah_pekerjaan)--;
        cout << "Pekerjaan berhasil dihapus!\n";
    } else {
        cout << "Pekerjaan tidak ditemukan!\n";
    }
}

int main() {
    const int max_pekerjaan = 100;
    Pekerjaan daftar_pekerjaan[max_pekerjaan];
    int jumlah_pekerjaan = 0;
    int pilihan;

    do {
        cout << "\nSistem Manajemen Vendor Photography\n";
        cout << "1. Tambah Pekerjaan\n";
        cout << "2. Tampilkan Daftar Pekerjaan\n";
        cout << "3. Ubah Pekerjaan\n";
        cout << "4. Hapus Pekerjaan\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if(cin.fail()) {
            cin.clear(); // Menghapus kesalahan input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter tidak valid
            cout << "Input tidak valid. Silakan masukkan angka.\n";
            continue;
        }

        switch (pilihan) {
            case 1:
                tambahPekerjaan(daftar_pekerjaan, &jumlah_pekerjaan);
                break;
            case 2:
                tampilkanPekerjaan(daftar_pekerjaan, jumlah_pekerjaan);
                break;
            case 3:
                ubahPekerjaan(daftar_pekerjaan, jumlah_pekerjaan);
                break;
            case 4:
                hapusPekerjaan(daftar_pekerjaan, &jumlah_pekerjaan);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
