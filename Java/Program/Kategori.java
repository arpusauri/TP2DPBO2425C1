package Java.Program;

public class Kategori {
    private String idKategori;
    private String namaKategori;
    private String deskripsi;

    public Kategori(String idKategori, String namaKategori, String deskripsi) {
        this.idKategori = idKategori;
        this.namaKategori = namaKategori;
        this.deskripsi = deskripsi;
    }

    // Getters
    public String getIDKategori() { return idKategori; }
    public String getNamaKategori() { return namaKategori; }
    public String getDeskripsi() { return deskripsi; }

    // Setters
    public void setIDKategori(String idKategori) { this.idKategori = idKategori; }
    public void setNamaKategori(String namaKategori) { this.namaKategori = namaKategori; }
    public void setDeskripsi(String deskripsi) { this.deskripsi = deskripsi; }
}
