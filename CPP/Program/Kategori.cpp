#include <iostream>

using namespace std;

class Kategori{
    // atribut private
    private:
        string id_kategori; // id kategori (string) agar bisa kombinasi
        string nama_kategori;
        string deskripsi;

    public:
        // constructor kosong
        Kategori(){}

        // constructor
        Kategori(string id_kategori, string nama_kategori, string deskripsi){
            this->id_kategori = id_kategori;
            this->nama_kategori = nama_kategori;
            this->deskripsi = deskripsi;
        }

        // getter
        string getIDKategori() const {
            return id_kategori;
        }
        string getNamaKategori() const {
            return nama_kategori;
        }
        string getDeskripsi() const {
            return deskripsi;
        }

        // setter
        void setIDKategori(string id_kategori) {
            this->id_kategori = id_kategori;
        }
        void setNamaKategori(string nama_kategori) {
            this->nama_kategori = nama_kategori;
        }
        void setDeskripsi(string deskripsi) {
            this->deskripsi = deskripsi;
        }

        // destructor
        ~Kategori() { }
};