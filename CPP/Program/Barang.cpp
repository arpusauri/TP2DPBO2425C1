#include <iostream>
// include file kategori
#include "Kategori.cpp"

using namespace std;

class Barang : public Kategori { // inheritance dari class Kategori
    // atribut private
    private:
        string merk;
        string model;
        int tahun_produksi;

    public:
        // constructor kosong
        Barang(){}

        // constructor
        Barang(string id_kategori, string nama_kategori, string deskripsi, 
            string merk, string model, int tahun_produksi) : Kategori(id_kategori, nama_kategori, deskripsi) { // manggil constructor parent
            this->merk = merk;
            this->model = model;
            this->tahun_produksi = tahun_produksi;
        }

        // getter
        string getMerk() const {
            return merk;
        }
        string getModel() const {
            return model;
        }
        int getTahunProduksi() const {
            return tahun_produksi;
        }

        // setter
        void setMerk(string merk) {
            this->merk = merk;
        }
        void setModel(string model) {
            this->model = model;
        }
        void setTahunProduksi(int tahun_produksi) {
            this->tahun_produksi = tahun_produksi;
        }

        // destructor
        ~Barang() { }
};