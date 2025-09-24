# include Kategori.py
from Kategori import Kategori

class Barang(Kategori):
    def __init__(self, id_kategori="", nama_kategori="", deskripsi="",
                 merk="", model="", tahun_produksi=0):
        super().__init__(id_kategori, nama_kategori, deskripsi)
        self.__merk = merk
        self.__model = model
        self.__tahun_produksi = tahun_produksi

    # getter
    def get_merk(self):
        return self.__merk
    def get_model(self):
        return self.__model
    def get_tahun_produksi(self):
        return self.__tahun_produksi

    # setter
    def set_merk(self, merk):
        self.__merk = merk
    def set_model(self, model):
        self.__model = model
    def set_tahun_produksi(self, tahun_produksi):
        self.__tahun_produksi = tahun_produksi
