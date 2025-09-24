package Java.Program;

public class Barang extends Kategori { 
    // inheritance dari class Kategori
    // atribut private
    private String merk;
    private String model;
    private int tahunProduksi;

    // constructor
    public Barang(String idKategori, String namaKategori, String deskripsi,
                  String merk, String model, int tahunProduksi) {
        super(idKategori, namaKategori, deskripsi); // manggil constructor parent
        this.merk = merk;
        this.model = model;
        this.tahunProduksi = tahunProduksi;
    }

    // getters
    public String getMerk() { 
        return merk; 
    }
    public String getModel() { 
        return model; 
    }
    public int getTahunProduksi() { 
        return tahunProduksi; 
    }

    // setters
    public void setMerk(String merk) { 
        this.merk = merk; 
    }
    public void setModel(String model) { 
        this.model = model; 
    }
    public void setTahunProduksi(int tahunProduksi) { 
        this.tahunProduksi = tahunProduksi; 
    }
}
