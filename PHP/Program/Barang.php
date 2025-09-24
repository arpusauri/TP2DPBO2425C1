<?php
// include file kategori
require_once "Kategori.php";

class Barang extends Kategori { // inheritance class kategori
    // atribut private
    private $merk;
    private $model;
    private $tahunProduksi;

    // constructor
    public function __construct($idKategori = "", $namaKategori = "", $deskripsi = "",
                                $merk = "", $model = "", $tahunProduksi = 0) {
        parent::__construct($idKategori, $namaKategori, $deskripsi); // manggil constructor parent
        $this->merk = $merk;
        $this->model = $model;
        $this->tahunProduksi = $tahunProduksi;
    }

    // getters
    public function getMerk() {
        return $this->merk;
    }
    public function getModel() {
        return $this->model;
    }
    public function getTahunProduksi() {
        return $this->tahunProduksi;
    }

    // settes
    public function setMerk($merk) {
        $this->merk = $merk;
    }
    public function setModel($model) {
        $this->model = $model;
    }
    public function setTahunProduksi($tahunProduksi) {
        $this->tahunProduksi = $tahunProduksi;
    }
}
