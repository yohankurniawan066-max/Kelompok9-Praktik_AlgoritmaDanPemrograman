#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_TUGAS = 5;

bool isValidNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void inputTugas(string tugas[MAX_TUGAS][4], int& jumlah_tugas) {
    if (jumlah_tugas < MAX_TUGAS) {
        // Input Nama Tugas
        string nama_tugas;
        cout << "Masukkan nama tugas ke-" << jumlah_tugas + 1 << ": ";
        cin.ignore();
        getline(cin, nama_tugas);
        if (nama_tugas.empty()) {
            cout << "Nama tugas tidak boleh kosong!" << endl;
            return;
        }
        tugas[jumlah_tugas][0] = nama_tugas;

        // Input Mata Kuliah
        string mata_kuliah;
        cout << "Masukkan mata kuliah ke-" << jumlah_tugas + 1 << ": ";
        getline(cin, mata_kuliah);
        if (mata_kuliah.empty()) {
            cout << "Mata kuliah tidak boleh kosong!" << endl;
            return;
        }
        tugas[jumlah_tugas][1] = mata_kuliah;

        // Input Deadline (dalam jumlah hari)
        string deadline_str;
        cout << "Masukkan deadline (dalam hari) tugas ke-" << jumlah_tugas + 1 << ": ";
        cin >> deadline_str;
        
        if (!isValidNumber(deadline_str)) {
            cout << "Masukkan jumlah hari dalam angka!" << endl;
            return;
        }

        tugas[jumlah_tugas][2] = deadline_str;
        tugas[jumlah_tugas][3] = "belum selesai";
        jumlah_tugas++;
    } else {
        cout << "Sudah mencapai batas tugas maksimal!" << endl;
    }
}

void tampilkanSemuaTugas(string tugas[MAX_TUGAS][4], int jumlah_tugas) {
    if (jumlah_tugas == 0) {
        cout << "Tidak ada tugas yang dimasukkan." << endl;
        return;
    }

    cout << "\n===== Daftar Tugas =====\n";
    for (int i = 0; i < jumlah_tugas; i++) {
        cout << "----------------------------------------------------------\n";
        cout << "Nama Tugas  : " << tugas[i][0] << endl;
        cout << "Mata Kuliah : " << tugas[i][1] << endl;
        cout << "Deadline    : " << tugas[i][2] << " hari" << endl;
        cout << "Status      : " << tugas[i][3] << endl;
        cout << "----------------------------------------------------------\n";
    }
}

void urutkanDeadline(string tugas[MAX_TUGAS][4], int jumlah_tugas) {
    for (int i = 0; i < jumlah_tugas - 1; i++) {
        for (int j = i + 1; j < jumlah_tugas; j++) {
            if (stoi(tugas[i][2]) > stoi(tugas[j][2])) {
                for (int k = 0; k < 4; k++) {
                    swap(tugas[i][k], tugas[j][k]);
                }
            }
        }
    }
}

void tugasTerdekat(string tugas[MAX_TUGAS][4], int jumlah_tugas) {
    if (jumlah_tugas == 0) {
        cout << "Tidak ada tugas yang dimasukkan." << endl;
        return;
    }

    cout << "\n===== Tugas yang diurutkan berdasarkan deadline terdekat =====\n";
    for (int i = 0; i < jumlah_tugas; i++) {
        cout << "----------------------------------------------------------\n";
        cout << "Nama Tugas  : " << tugas[i][0] << endl;
        cout << "Mata Kuliah : " << tugas[i][1] << endl;
        cout << "Deadline    : " << tugas[i][2] << " hari" << endl;
        cout << "Status      : " << tugas[i][3] << endl;
        cout << "----------------------------------------------------------\n";
    }
}

void menuUtama(string tugas[MAX_TUGAS][4], int& jumlah_tugas) {
    int pilihan;
    do {
        cout << "\n===== Menu Utama =====\n";
        cout << "1. Input Tugas\n";
        cout << "2. Tampilkan Semua Tugas\n";
        cout << "3. Urutkan Tugas Berdasarkan Deadline\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputTugas(tugas, jumlah_tugas);
                break;
            case 2:
                tampilkanSemuaTugas(tugas, jumlah_tugas);
                break;
            case 3:
                urutkanDeadline(tugas, jumlah_tugas);
                tugasTerdekat(tugas, jumlah_tugas);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 4);
}

int main() {
    string tugas[MAX_TUGAS][4];
    int jumlah_tugas = 0;
    menuUtama(tugas, jumlah_tugas);

    return 0;
}
