<?php
// include file barang
require_once "Barang.php";

class DetailBarang extends Barang { // inheritance class barang
    // atribut private
    private $namaBarang;
    private $harga;
    private $stok;
    private $fotoProduk; // atribut tambahan buat foto di web

    // constructor
    public function __construct($idKategori = "", $namaKategori = "", $deskripsi = "",
                                $merk = "", $model = "", $tahunProduksi = 0,
                                $namaBarang = "", $harga = 0.0, $stok = 0, $fotoProduk = "") {
        parent::__construct($idKategori, $namaKategori, $deskripsi, $merk, $model, $tahunProduksi); // manggil constructor parent
        $this->namaBarang = $namaBarang;
        $this->harga = $harga;
        $this->stok = $stok;
        $this->fotoProduk = $fotoProduk; // atribut tambahan
    }

    // getters
    public function getNamaBarang() {
        return $this->namaBarang;
    }
    public function getHarga() {
        return $this->harga;
    }
    public function getStok() {
        return $this->stok;
    }
    public function getFotoProduk() {
        return $this->fotoProduk;
    }

    // setters
    public function setNamaBarang($namaBarang) {
        $this->namaBarang = $namaBarang;
    }
    public function setHarga($harga) {
        $this->harga = $harga;
    }
    public function setStok($stok) {
        $this->stok = $stok;
    }
    public function setFoto($fotoProduk) {
        $this->$fotoProduk = $fotoProduk;
    }
}
