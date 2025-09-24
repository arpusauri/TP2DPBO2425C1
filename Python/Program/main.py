# include detailbarang saja
from DetailBarang import DetailBarang

# dataBarang akan menyimpan semua objek DetailBarang
dataBarang = []

# fungsi untuk menampilkan menu
def tampilkanMenu():
    print("\n")
    print("=====================================")
    print("  SISTEM MANAJEMEN TOKO ELEKTRONIK")
    print("=====================================")
    print("1. TAMPILKAN DATA")
    print("2. TAMBAHKAN DATA")
    print("3. EXIT")
    print("=====================================")

# fungsi untuk menghitung lebar kolom (agar tabel rapi)
def hitungLebarKolom(listBarang):
    header = ["ID", "Kategori", "Deskripsi", "Merk", "Model", "Tahun", "Nama Barang", "Harga", "Stok"]
    lebar = [len(h) for h in header]

    for b in listBarang:
        lebar[0] = max(lebar[0], len(b.get_id_kategori()))
        lebar[1] = max(lebar[1], len(b.get_nama_kategori()))
        lebar[2] = max(lebar[2], len(b.get_deskripsi()))
        lebar[3] = max(lebar[3], len(b.get_merk()))
        lebar[4] = max(lebar[4], len(b.get_model()))
        lebar[5] = max(lebar[5], len(str(b.get_tahun_produksi())))
        lebar[6] = max(lebar[6], len(b.get_nama_barang()))
        lebar[7] = max(lebar[7], len(str(int(b.get_harga()))))
        lebar[8] = max(lebar[8], len(str(b.get_stok())))
    return lebar

# fungsi untuk menampilkan data
def tampilkanData():
    if not dataBarang:
        print("\nData masih kosong.\n")
        return

    lebar = hitungLebarKolom(dataBarang)
    header = ["ID", "Kategori", "Deskripsi", "Merk", "Model", "Tahun", "Nama Barang", "Harga", "Stok"]

    # garis atas
    print("".join("=" * (l+3) for l in lebar))

    # header
    for i, h in enumerate(header):
        print(f"{h:<{lebar[i]+3}}", end="")
    print()

    # garis tengah
    print("".join("=" * (l+3) for l in lebar))

    # isi data
    for b in dataBarang:
        print(f"{b.get_id_kategori():<{lebar[0]+3}}"
              f"{b.get_nama_kategori():<{lebar[1]+3}}"
              f"{b.get_deskripsi():<{lebar[2]+3}}"
              f"{b.get_merk():<{lebar[3]+3}}"
              f"{b.get_model():<{lebar[4]+3}}"
              f"{b.get_tahun_produksi():<{lebar[5]+3}}"
              f"{b.get_nama_barang():<{lebar[6]+3}}"
              f"{int(b.get_harga()):<{lebar[7]+3}}"
              f"{b.get_stok():<{lebar[8]+3}}")
    print()

    # garis bawah
    print("".join("=" * (l+3) for l in lebar))

# fungsi untuk menambah data
def tambahData():
    print("\n=== Input Barang Baru ===")
    id_kategori = input("ID Kategori     : ")
    nama_kategori = input("Nama Kategori   : ")
    deskripsi = input("Deskripsi       : ")
    merk = input("Merk            : ")
    model = input("Model           : ")
    tahun_produksi = int(input("Tahun Produksi  : "))
    nama_barang = input("Nama Barang     : ")
    harga = float(input("Harga           : "))
    stok = int(input("Stok            : "))

    dataBarang.append(
        DetailBarang(id_kategori, nama_kategori, deskripsi,
                     merk, model, tahun_produksi,
                     nama_barang, harga, stok)
    )
    print("\nData berhasil ditambahkan!\n")

# main program
if __name__ == "__main__":
    # data awal
    dataBarang.append(DetailBarang("K001", "Laptop", "Kategori untuk laptop",
                                   "ASUS", "ROG", 2025,
                                   "ASUS ROG Zephyrus G14", 33999000, 19))
    dataBarang.append(DetailBarang("K002", "Smartphone", "Kategori untuk Smartphone/Handphone",
                                   "Samsung", "Galaxy S", 2025,
                                   "Samsung Galaxy S25 Ultra", 18999000, 34))
    dataBarang.append(DetailBarang("K003", "TV", "Kategori untuk televisi",
                                   "Samsung", "The Frame", 2025,
                                   "Samsung The Frame 4K 65\"", 24499000, 28))
    dataBarang.append(DetailBarang("K004", "Kamera", "Kategori untuk kamera",
                                   "Canon", "EOS", 2018,
                                   "Canon EOS 3000D", 6499000, 22))
    dataBarang.append(DetailBarang("K005", "Headset", "Kategori untuk headset/headphone",
                                   "Steelseries", "Arctis", 2022,
                                   "Steelseries Arctis Nova Pro Wireless", 5999000, 12))

    pilihan = 0
    while pilihan != 3:
        tampilkanMenu()
        try:
            pilihan = int(input("Pilih menu: "))
        except ValueError:
            print("Input tidak valid.")
            continue

        if pilihan == 1:
            tampilkanData()
        elif pilihan == 2:
            tambahData()
        elif pilihan == 3:
            print("Keluar dari program.")
        else:
            print("Pilihan tidak valid.")
