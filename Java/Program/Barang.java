package Java.Program;

public class Barang extends Kategori {
    private String merk;
    private String model;
    private int tahunProduksi;

    public Barang(String idKategori, String namaKategori, String deskripsi,
                  String merk, String model, int tahunProduksi) {
        super(idKategori, namaKategori, deskripsi);
        this.merk = merk;
        this.model = model;
        this.tahunProduksi = tahunProduksi;
    }

    // Getters
    public String getMerk() { return merk; }
    public String getModel() { return model; }
    public int getTahunProduksi() { return tahunProduksi; }

    // Setters
    public void setMerk(String merk) { this.merk = merk; }
    public void setModel(String model) { this.model = model; }
    public void setTahunProduksi(int tahunProduksi) { this.tahunProduksi = tahunProduksi; }
}
