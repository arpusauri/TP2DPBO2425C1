package Java.Program;

public class DetailBarang extends Barang {
    private String namaBarang;
    private double harga;
    private int stok;

    public DetailBarang(String idKategori, String namaKategori, String deskripsi,
                        String merk, String model, int tahunProduksi,
                        String namaBarang, double harga, int stok) {
        super(idKategori, namaKategori, deskripsi, merk, model, tahunProduksi);
        this.namaBarang = namaBarang;
        this.harga = harga;
        this.stok = stok;
    }

    // Getters
    public String getNamaBarang() { return namaBarang; }
    public double getHarga() { return harga; }
    public int getStok() { return stok; }

    // Setters
    public void setNamaBarang(String namaBarang) { this.namaBarang = namaBarang; }
    public void setHarga(double harga) { this.harga = harga; }
    public void setStok(int stok) { this.stok = stok; }
}
