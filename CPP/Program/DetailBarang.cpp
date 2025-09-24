#include <iostream>
// include file barang
#include "Barang.cpp"

using namespace std;

class DetailBarang : public Barang { // inheritance dari class Barang
    // atribut private
    private:
        string nama_barang;
        double harga;
        int stok;

    public:
        // constructor kosong
        DetailBarang(){}

        // constructor
        DetailBarang(string id_kategori, string nama_kategori, string deskripsi, 
            string merk, string model, int tahun_produksi, 
            string nama_barang, double harga, int stok) : Barang (id_kategori, nama_kategori, deskripsi, merk, model, tahun_produksi){ // manggil constructor parent
            this->nama_barang = nama_barang;
            this->harga = harga;
            this->stok = stok;
        }

        // getter
        string getNamaBarang() const {
            return nama_barang;
        }
        double getHarga() const {
            return harga;
        }
        int getStok() const {
            return stok;
        }

        // setter
        void setNamaBarang(string nama_barang) {
            this->nama_barang = nama_barang;
        }
        void setHarga(double harga) {
            this->harga = harga;
        }
        void setStok(int stok) {
            this->stok = stok;
        }

        // destructor
        ~DetailBarang() { }
};