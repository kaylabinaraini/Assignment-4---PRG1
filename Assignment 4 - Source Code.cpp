#include <iostream>
using namespace std;

// Mencari indeks pertama kemunculan target (-1 jika tidak ada)
int cariIndeksPertama(int data[], int n, int target) {
    int kiri = 0, kanan = n - 1, hasil = -1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (data[tengah] == target) {
            hasil = tengah;      // simpan, lalu cari lagi ke kiri
            kanan = tengah - 1;
        } else if (data[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return hasil;
}

// Mencari indeks terakhir kemunculan target (-1 jika tidak ada)
int cariIndeksTerakhir(int data[], int n, int target) {
    int kiri = 0, kanan = n - 1, hasil = -1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (data[tengah] == target) {
            hasil = tengah;      // simpan, lalu cari lagi ke kanan
            kiri = tengah + 1;
        } else if (data[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return hasil;
}

// Menghitung jumlah kemunculan target
int hitungData(int data[], int n, int target) {
    int pertama = cariIndeksPertama(data, n, target);
    if (pertama == -1) return 0;  // data tidak ada
    int terakhir = cariIndeksTerakhir(data, n, target);
    return terakhir - pertama + 1;
}

int main() {
    int data[] = {2, 4, 4, 4, 5, 7, 7, 9, 20};  // harus terurut
    int n = sizeof(data) / sizeof(data[0]);
    int target;

    cout << "Masukkan data yang dicari: ";
    cin >> target;

    int jumlah = hitungData(data, n, target);
    cout << "Data " << target << " muncul sebanyak " << jumlah << " kali" << endl;
    return 0;
}
