#include <iostream>
#include <iomanip>
#include <vector>
#include "DetailBarang.cpp"   // pastikan ada Kategori.cpp, Barang.cpp, DetailBarang.cpp

using namespace std;

vector<DetailBarang> dataBarang;

// fungsi untuk menampilkan menu awal
void tampilkanMenu() {
    cout << "\n";
    cout << "=====================================" << endl;
    cout << "  SISTEM MANAJEMEN TOKO ELEKTRONIK" << endl;
    cout << "=====================================" << endl;
    cout << "1. TAMPILKAN DATA" << endl;
    cout << "2. TAMBAHKAN DATA" << endl;
    cout << "3. EXIT" << endl;
    cout << "=====================================" << endl;
}

// fungsi untuk menghitung lebar kolom
vector<int> hitungLebarKolom(const vector<DetailBarang>& list) {
    vector<int> lebar = {
        (int)string("ID").size(),
        (int)string("Kategori").size(),
        (int)string("Deskripsi").size(),
        (int)string("Merk").size(),
        (int)string("Model").size(),
        (int)string("Tahun").size(),
        (int)string("Nama Barang").size(),
        (int)string("Harga").size(),
        (int)string("Stok").size()
    };

    for (auto &b : list) {
        lebar[0] = max(lebar[0], (int)b.getID().size());
        lebar[1] = max(lebar[1], (int)b.getNama().size());
        lebar[2] = max(lebar[2], (int)b.getDeskripsi().size());
        lebar[3] = max(lebar[3], (int)b.getMerk().size());
        lebar[4] = max(lebar[4], (int)b.getModel().size());
        lebar[5] = max(lebar[5], (int)to_string(b.getTahunProduksi()).size());
        lebar[6] = max(lebar[6], (int)b.getNamaBarang().size());
        lebar[7] = max(lebar[7], (int)to_string((long long)b.getHarga()).size());
        lebar[8] = max(lebar[8], (int)to_string(b.getStok()).size());
    }

    return lebar;
}

// fungsi untuk menampilkan tabel data
void tampilkanData() {
    if (dataBarang.empty()) {
        cout << "\nData masih kosong.\n";
        return;
    }

    vector<int> lebar = hitungLebarKolom(dataBarang);

    // garis atas
    for (int l : lebar) cout << setw(l + 3) << setfill('=') << "";
    cout << setfill(' ') << "\n";

    // header
    cout << left << setw(lebar[0] + 3) << "ID"
         << setw(lebar[1] + 3) << "Kategori"
         << setw(lebar[2] + 3) << "Deskripsi"
         << setw(lebar[3] + 3) << "Merk"
         << setw(lebar[4] + 3) << "Model"
         << setw(lebar[5] + 3) << "Tahun"
         << setw(lebar[6] + 3) << "Nama Barang"
         << setw(lebar[7] + 3) << "Harga"
         << setw(lebar[8] + 3) << "Stok"
         << endl;

    // garis tengah
    for (int l : lebar) cout << setw(l + 3) << setfill('=') << "";
    cout << setfill(' ') << "\n";

    // data
    for (auto &b : dataBarang) {
        cout << left << setw(lebar[0] + 3) << b.getID()
             << setw(lebar[1] + 3) << b.getNama()
             << setw(lebar[2] + 3) << b.getDeskripsi()
             << setw(lebar[3] + 3) << b.getMerk()
             << setw(lebar[4] + 3) << b.getModel()
             << setw(lebar[5] + 3) << b.getTahunProduksi()
             << setw(lebar[6] + 3) << b.getNamaBarang()
             << setw(lebar[7] + 3) << fixed << setprecision(0) << b.getHarga()
             << setw(lebar[8] + 3) << b.getStok()
             << endl;
    }

    // garis bawah
    for (int l : lebar) cout << setw(l + 3) << setfill('=') << "";
    cout << setfill(' ') << "\n";
}

// fungsi untuk menambahkan data baru
void tambahData() {
    string id, nama, deskripsi, merk, model, nama_barang;
    int tahun_produksi, stok;
    double harga;

    cout << "\n=== Input Barang Baru ===\n";
    cin.ignore();
    cout << "ID Kategori     : "; getline(cin, id);
    cout << "Nama Kategori   : "; getline(cin, nama);
    cout << "Deskripsi       : "; getline(cin, deskripsi);
    cout << "Merk            : "; getline(cin, merk);
    cout << "Model           : "; getline(cin, model);
    cout << "Tahun Produksi  : "; cin >> tahun_produksi;
    cin.ignore();
    cout << "Nama Barang     : "; getline(cin, nama_barang);
    cout << "Harga           : "; cin >> harga;
    cout << "Stok            : "; cin >> stok;

    dataBarang.push_back(DetailBarang(id, nama, deskripsi, merk, model, tahun_produksi,
                                      nama_barang, harga, stok));
    cout << "\nData berhasil ditambahkan!\n";
}

int main() {
    // data awal
    dataBarang.push_back(DetailBarang("K001", "Laptop", "Elektronik untuk komputasi",
                                      "ASUS", "ROG Strix", 2023,
                                      "ASUS ROG Strix G15", 22000000, 5));
    dataBarang.push_back(DetailBarang("K002", "Smartphone", "Elektronik untuk komunikasi",
                                      "Samsung", "Galaxy S23", 2023,
                                      "Samsung Galaxy S23 Ultra", 18000000, 10));
    dataBarang.push_back(DetailBarang("K003", "TV", "Elektronik hiburan",
                                      "LG", "OLED C2", 2022,
                                      "LG OLED55C2", 15000000, 4));
    dataBarang.push_back(DetailBarang("K004", "Kamera", "Elektronik fotografi",
                                      "Canon", "EOS R5", 2021,
                                      "Canon EOS R5 Mirrorless", 60000000, 2));
    dataBarang.push_back(DetailBarang("K005", "Headphone", "Elektronik audio",
                                      "Sony", "WH-1000XM5", 2022,
                                      "Sony WH-1000XM5", 6000000, 7));

    int pilihan;
    do {
        tampilkanMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanData(); break;
            case 2: tambahData(); break;
            case 3: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);

    return 0;
}
