<?php
class Kategori {
    // atribut private
    private $idKategori;
    private $namaKategori;
    private $deskripsi;

    // constructor
    public function __construct($idKategori = "", $namaKategori = "", $deskripsi = "") {
        $this->idKategori = $idKategori;
        $this->namaKategori = $namaKategori;
        $this->deskripsi = $deskripsi;
    }

    // getters
    public function getIdKategori() {
        return $this->idKategori;
    }
    public function getNamaKategori() {
        return $this->namaKategori;
    }
    public function getDeskripsi() {
        return $this->deskripsi;
    }

    // setters
    public function setIdKategori($idKategori) {
        $this->idKategori = $idKategori;
    }
    public function setNamaKategori($namaKategori) {
        $this->namaKategori = $namaKategori;
    }
    public function setDeskripsi($deskripsi) {
        $this->deskripsi = $deskripsi;
    }
}
