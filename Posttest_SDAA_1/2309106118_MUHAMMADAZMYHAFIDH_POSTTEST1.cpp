#include <iostream>
using namespace std;

int hitungKombinasi(int angkaAtas, int angkaBawah) {
    if (angkaBawah == 0 || angkaBawah == angkaAtas) {
        return 1;
    } else {
        return hitungKombinasi(angkaAtas - 1, angkaBawah - 1) + hitungKombinasi(angkaAtas - 1, angkaBawah);
    }
}

void tampilkanSegitigaPascal(int jumlahBaris) {
    for (int nomorBaris = 0; nomorBaris < jumlahBaris; nomorBaris++) {
        for (int nomorKolom = 0; nomorKolom <= nomorBaris; nomorKolom++) {
            cout << hitungKombinasi(nomorBaris, nomorKolom) << " ";
        }
        cout << endl;
    }
}

int main() {
    int tingkatSegitiga = 3;
    tampilkanSegitigaPascal(tingkatSegitiga);
    return 0;
}
