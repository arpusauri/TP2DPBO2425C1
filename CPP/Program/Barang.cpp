#include <iostream>
#include "Kategori.cpp"

using namespace std;

class Barang : public Kategori {
    private:
        string merk;
        string model;
        int tahun_produksi;

    public:
        Barang(){}

        Barang(string id, string nama, string deskripsi, 
            string merk, string model, int tahun_produksi) : Kategori(id, nama, deskripsi) {
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