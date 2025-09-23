#include <iostream>

using namespace std;

class Kategori{
    private:
        string id;
        string nama;
        string deskripsi;

    public:
        Kategori(){
        }

        Kategori(string id, string nama, string deskripsi){
            this->id = id;
            this->nama = nama;
            this->deskripsi = deskripsi;
        }

        // getter
        string getID() const {
            return id;
        }
        string getNama() const {
            return nama;
        }
        string getDeskripsi() const {
            return deskripsi;
        }

        // setter
        void setID(string id) {
            this->id = id;
        }
        void setNama(string nama) {
            this->nama = nama;
        }
        void setDeskripsi(string deskripsi) {
            this->deskripsi = deskripsi;
        }

        // destructor
        ~Kategori() { }
};