package Java.Program;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    static List<DetailBarang> dataBarang = new ArrayList<>();

    // tampilkan menu
    static void tampilkanMenu() {
        System.out.println();
        System.out.println("=====================================");
        System.out.println("  SISTEM MANAJEMEN TOKO ELEKTRONIK");
        System.out.println("=====================================");
        System.out.println("1. TAMPILKAN DATA");
        System.out.println("2. TAMBAHKAN DATA");
        System.out.println("3. EXIT");
        System.out.println("=====================================");
    }

    // hitung lebar kolom
    static int[] hitungLebarKolom(List<DetailBarang> list) {
        String[] header = {"ID", "Kategori", "Deskripsi", "Merk", "Model",
                           "Tahun", "Nama Barang", "Harga", "Stok"};
        int[] lebar = new int[header.length];
        for (int i = 0; i < header.length; i++) {
            lebar[i] = header[i].length();
        }

        for (DetailBarang b : list) {
            lebar[0] = Math.max(lebar[0], b.getIDKategori().length());
            lebar[1] = Math.max(lebar[1], b.getNamaKategori().length());
            lebar[2] = Math.max(lebar[2], b.getDeskripsi().length());
            lebar[3] = Math.max(lebar[3], b.getMerk().length());
            lebar[4] = Math.max(lebar[4], b.getModel().length());
            lebar[5] = Math.max(lebar[5], String.valueOf(b.getTahunProduksi()).length());
            lebar[6] = Math.max(lebar[6], b.getNamaBarang().length());
            lebar[7] = Math.max(lebar[7], String.valueOf((long)b.getHarga()).length());
            lebar[8] = Math.max(lebar[8], String.valueOf(b.getStok()).length());
        }
        return lebar;
    }

    // tampilkan tabel
    static void tampilkanData() {
        if (dataBarang.isEmpty()) {
            System.out.println("\nData masih kosong.\n");
            return;
        }

        int[] lebar = hitungLebarKolom(dataBarang);

        // garis atas
        for (int l : lebar) {
            for (int i = 0; i < l + 3; i++) System.out.print("=");
        }
        System.out.println();

        // header
        System.out.printf("%-" + (lebar[0] + 3) + "s", "ID");
        System.out.printf("%-" + (lebar[1] + 3) + "s", "Kategori");
        System.out.printf("%-" + (lebar[2] + 3) + "s", "Deskripsi");
        System.out.printf("%-" + (lebar[3] + 3) + "s", "Merk");
        System.out.printf("%-" + (lebar[4] + 3) + "s", "Model");
        System.out.printf("%-" + (lebar[5] + 3) + "s", "Tahun");
        System.out.printf("%-" + (lebar[6] + 3) + "s", "Nama Barang");
        System.out.printf("%-" + (lebar[7] + 3) + "s", "Harga");
        System.out.printf("%-" + (lebar[8] + 3) + "s", "Stok");
        System.out.println();

        // garis tengah
        for (int l : lebar) {
            for (int i = 0; i < l + 3; i++) System.out.print("=");
        }
        System.out.println();

        // data
        for (DetailBarang b : dataBarang) {
            System.out.printf("%-" + (lebar[0] + 3) + "s", b.getIDKategori());
            System.out.printf("%-" + (lebar[1] + 3) + "s", b.getNamaKategori());
            System.out.printf("%-" + (lebar[2] + 3) + "s", b.getDeskripsi());
            System.out.printf("%-" + (lebar[3] + 3) + "s", b.getMerk());
            System.out.printf("%-" + (lebar[4] + 3) + "s", b.getModel());
            System.out.printf("%-" + (lebar[5] + 3) + "d", b.getTahunProduksi());
            System.out.printf("%-" + (lebar[6] + 3) + "s", b.getNamaBarang());
            System.out.printf("%-" + (lebar[7] + 3) + ".0f", b.getHarga());
            System.out.printf("%-" + (lebar[8] + 3) + "d", b.getStok());
            System.out.println();
        }

        // garis bawah
        for (int l : lebar) {
            for (int i = 0; i < l + 3; i++) System.out.print("=");
        }
        System.out.println();
    }

    // tambah data
    static void tambahData(Scanner sc) {
        sc.nextLine(); // clear buffer
        System.out.println("\n=== Input Barang Baru ===");
        System.out.print("ID Kategori     : "); String idKategori = sc.nextLine();
        System.out.print("Nama Kategori   : "); String namaKategori = sc.nextLine();
        System.out.print("Deskripsi       : "); String deskripsi = sc.nextLine();
        System.out.print("Merk            : "); String merk = sc.nextLine();
        System.out.print("Model           : "); String model = sc.nextLine();
        System.out.print("Tahun Produksi  : "); int tahun_produksi = sc.nextInt(); sc.nextLine();
        System.out.print("Nama Barang     : "); String nama_barang = sc.nextLine();
        System.out.print("Harga           : "); double harga = sc.nextDouble();
        System.out.print("Stok            : "); int stok = sc.nextInt();

        dataBarang.add(new DetailBarang(idKategori, namaKategori, deskripsi,
                                        merk, model, tahun_produksi,
                                        nama_barang, harga, stok));
        System.out.println("\nData berhasil ditambahkan!\n");
    }

    public static void main(String[] args) {
        // data awal
        dataBarang.add(new DetailBarang("K001", "Laptop", "Kategori untuk laptop",
                "ASUS", "ROG", 2025,
                "ASUS ROG Zephyrus G14", 33999000, 19));
        dataBarang.add(new DetailBarang("K002", "Smartphone", "Kategori untuk Smartphone/Handphone",
                "Samsung", "Galaxy S", 2025,
                "Samsung Galaxy S25 Ultra", 18999000, 34));
        dataBarang.add(new DetailBarang("K003", "TV", "Kategori untuk televisi",
                "Samsung", "The Frame", 2025,
                "Samsung The Frame 4K 65\"", 24499000, 28));
        dataBarang.add(new DetailBarang("K004", "Kamera", "Kategori untuk kamera",
                "Canon", "EOS", 2018,
                "Canon EOS 3000D", 6499000, 22));
        dataBarang.add(new DetailBarang("K005", "Headset", "Kategori untuk headset/headphone",
                "Steelseries", "Arctis", 2022,
                "Steelseries Arctis Nova Pro Wireless", 5999000, 12));

        Scanner sc = new Scanner(System.in);
        int pilihan;
        do {
            tampilkanMenu();
            System.out.print("Pilih menu: ");
            pilihan = sc.nextInt();

            switch (pilihan) {
                case 1 -> tampilkanData();
                case 2 -> tambahData(sc);
                case 3 -> System.out.println("Keluar dari program.");
                default -> System.out.println("Pilihan tidak valid.");
            }
        } while (pilihan != 3);

        sc.close();
    }
}
