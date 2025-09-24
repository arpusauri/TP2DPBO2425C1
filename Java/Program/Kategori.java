package Java.Program;

public class Kategori {
    // atribut private
    private String idKategori;
    private String namaKategori;
    private String deskripsi;

    // constructor
    public Kategori(String idKategori, String namaKategori, String deskripsi) {
        this.idKategori = idKategori;
        this.namaKategori = namaKategori;
        this.deskripsi = deskripsi;
    }

    // getters
    public String getIDKategori() { 
        return idKategori; 
    }
    public String getNamaKategori() { 
        return namaKategori; 
    }
    public String getDeskripsi() { 
        return deskripsi; 
    }

    // setters
    public void setIDKategori(String idKategori) { 
        this.idKategori = idKategori; 
    }
    public void setNamaKategori(String namaKategori) { 
        this.namaKategori = namaKategori; 
    }
    public void setDeskripsi(String deskripsi) { 
        this.deskripsi = deskripsi; 
    }
}
