#include <iostream>
#include "Barang.cpp"

using namespace std;

class DetailBarang : public Barang {
    private:
        string nama_barang;
        double harga;
        int stok;

    public:
        DetailBarang(){}

        DetailBarang(string id, string nama, string deskripsi, 
            string merk, string model, int tahun_produksi, 
            string nama_barang, double harga, int stok) : Barang (id, nama, deskripsi, merk, model, tahun_produksi){
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