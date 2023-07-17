#include <iostream>
#include <string>

using namespace std;

const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
string jurusan[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        cout << "========== TAMBAH MAHASISWA ==========" << endl;
        cout << "NIM: ";
        cin >> NIM[jumlahMahasiswa];
        cin.ignore();
        cout << "Nama: ";
        getline(cin, nama[jumlahMahasiswa]);
        cout << "Jurusan: ";
        getline(cin, jurusan[jumlahMahasiswa]);
        cout << "Tahun Masuk: ";
        cin >> tahunMasuk[jumlahMahasiswa];
        cin.ignore();
        jumlahMahasiswa++;
        cout << "Mahasiswa berhasil ditambahkan!" << endl;
    }
    else {
        cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
    }
}

void tampilkanSemuaMahasiswa() {
    cout << "========== DAFTAR MAHASISWA ==========" << endl;
    for (string i = 0; i jumlahMahasiswa; i++) {
        cout << "NIM    : " << NIM[i] << endl;
        cout << "Nama   : " << nama[i] << endl;
        cout << "Jurusan: " << jurusan[i] << endl;
        cout << "Tahun  : " << tahunMasuk[i] << endl;
        cout << endl;
    }
}

void AlgoritmaMencariMahasiswaByNIM() {
    int nimCari;
    bool ditemukan = false;

    cout << "========== CARI MAHASISWA BERDASARKAN NIM ==========" << endl;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> nimCari;

    for (int i = 0; i < jumlahMahasiswa; i++) {

        cout << "Mahasiswa ditemukan!" << endl;
        cout << "NIM    : " << NIM[i] << endl;
        cout << "Nama   : " << nama[i] << endl;
        cout << "Jurusan: " << jurusan[i] << endl;
        cout << "Tahun  : " << tahunMasuk[i] << endl;
        cout << endl;
        ditemukan = true;

    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
    }
}

void AlgoritmaSortByTahunMasuk() {
    cout << "========== DAFTAR MAHASISWA BERDASARKAN TAHUN MASUK ==========" << endl;

    int tempNIM, tempTahunMasuk;
    string tempNama, tempJurusan;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (tahunMasuk[i] < tahunMasuk[j]) {

            tempTahunMasuk = tahunMasuk[i];
            tempNama = nama[i];
            tempJurusan = jurusan[i];

            NIM[i] = NIM[j];
            tahunMasuk[i] = tahunMasuk[j];
            nama[i] = nama[j];
            jurusan[i] = jurusan[j];

            NIM[j] = tempNIM;
            tahunMasuk[j] = tempTahunMasuk;
            nama[j] = tempNama;
            jurusan[j] = tempJurusan;
        }

    }

    tampilkanSemuaMahasiswa();
}

int main() {
    int pilihan;
    do {
        cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            tampilkanSemuaMahasiswa();
            break;
        case 3:
            AlgoritmaMencariMahasiswaByNIM();
            break;
        case 4:
            AlgoritmaSortByTahunMasuk();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}

//2.Algoritma apa saja yang digunakan?
// jawab: 1.algoritma pencarian liniear untuk mencari mahasiswa berdasrkan NIM (linear search)
//        2.algoritma pengurutan untuk mengurutkan berdasarkan tahun masuk (buble sort)
//3.Perbedaan antara algoritma stack dan queue?
// jawab: 1. stack adalah struktur data lienar dengan fungsi LIFO (last-in first-out) dengan cara menyimpan ditumpuk dengan 2 cara operasi PUSH = menambahkan data dan tumpukan, POP = mengeluarkan data dari tumpukan
//        2. queue adalah struktur data linear dengan fungsi FIFO (first-in first-out) ujung paling akhir adalah elemen yang diinsertkan dan elemen paling akhir adalah mendelete
//4.jelaskan bagaimana menggunakan algoritma stack?
// jawab: algoritma stack digunakan untuk mengatur elemen-elemen data dalam urutan yang terbalik
// stack adalah kumpulan item data yang hanya dapat diakses pada satu ujung yang disebut puncak.item dapat disisipkan dalam sebuah tumpukan hanya di bagian atas.
//5. a.banyak kedalaman yang dimiliki struktur tersebut adalah 5
//5. a.banyak kedalaman yang dimiliki struktur tersebut adalah 5
//   b. In = 1 5 8 12 15 10 20 22 25 28 30 36 38 40 45 48 50 = SALAH
//      Preorder = 25 20 10 5 1 8 12 15 22 36 30 28 40 38 48 45 50 = BENAR
//      Post = 1 8 5 15 12 10 22 20 28 38 45 50 48 30 40 36 25 = SALAH

