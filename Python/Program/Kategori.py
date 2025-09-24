class Kategori:
    def __init__(self, id_kategori="", nama_kategori="", deskripsi=""):
        self.__id_kategori = id_kategori
        self.__nama_kategori = nama_kategori
        self.__deskripsi = deskripsi

    # getter
    def get_id_kategori(self):
        return self.__id_kategori
    def get_nama_kategori(self):
        return self.__nama_kategori
    def get_deskripsi(self):
        return self.__deskripsi

    # setter
    def set_id_kategori(self, id_kategori):
        self.__id_kategori = id_kategori
    def set_nama_kategori(self, nama_kategori):
        self.__nama_kategori = nama_kategori
    def set_deskripsi(self, deskripsi):
        self.__deskripsi = deskripsi
