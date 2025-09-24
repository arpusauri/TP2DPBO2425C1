# include Barang.py
from Barang import Barang

class DetailBarang(Barang):
    def __init__(self, id_kategori="", nama_kategori="", deskripsi="",
                 merk="", model="", tahun_produksi=0,
                 nama_barang="", harga=0.0, stok=0):
        super().__init__(id_kategori, nama_kategori, deskripsi, merk, model, tahun_produksi)
        self.__nama_barang = nama_barang
        self.__harga = harga
        self.__stok = stok

    # getter
    def get_nama_barang(self):
        return self.__nama_barang
    def get_harga(self):
        return self.__harga
    def get_stok(self):
        return self.__stok

    # setter
    def set_nama_barang(self, nama_barang):
        self.__nama_barang = nama_barang
    def set_harga(self, harga):
        self.__harga = harga
    def set_stok(self, stok):
        self.__stok = stok
