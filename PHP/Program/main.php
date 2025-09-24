<?php
// include file detail barang aja
require_once "DetailBarang.php";

// bikin sesssion
session_start();

// reset session lama kalau ada
if (!isset($_SESSION["dataBarang"])) {
    $_SESSION["dataBarang"] = [];

    // bikin data awal
    $_SESSION["dataBarang"][] = new DetailBarang(
        "K001",
        "Laptop",
        "Kategori untuk laptop",
        "ASUS",
        "ROG",
        2025,
        "ASUS ROG Zephyrus G14",
        33999000,
        19,
        "uploads/sample-laptop.jpeg"
    );
    $_SESSION["dataBarang"][] = new DetailBarang(
        "K002",
        "Smartphone",
        "Kategori untuk Smartphone/Handphone",
        "Samsung",
        "Galaxy S",
        2025,
        "Samsung Galaxy S25 Ultra",
        18999000,
        34,
        "uploads/sample-phone.png"
    );
    $_SESSION["dataBarang"][] = new DetailBarang(
        "K003",
        "TV",
        "Kategori untuk televisi",
        "Samsung",
        "The Frame",
        2025,
        "Samsung The Frame 4K 65\"",
        24499000,
        28,
        "uploads/sample-tv.jpeg"
    );
    $_SESSION["dataBarang"][] = new DetailBarang(
        "K004",
        "Kamera",
        "Kategori untuk kamera",
        "Canon",
        "EOS",
        2018,
        "Canon EOS 3000D",
        6499000,
        22,
        "uploads/sample-camera.jpeg"
    );
    $_SESSION["dataBarang"][] = new DetailBarang(
        "K005",
        "Headset",
        "Kategori untuk headset/headphone",
        "Steelseries",
        "Arctis",
        2022,
        "Steelseries Arctis Nova Pro Wireless",
        5999000,
        12,
        "uploads/sample-headset.jpg"
    );
}

// untuk menambah data
if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["tambah"])) {
    $idKategori = trim($_POST["idKategori"]);
    $namaKategori = trim($_POST["namaKategori"]);
    $deskripsi = trim($_POST["deskripsi"]);
    $merk = trim($_POST["merk"]);
    $model = trim($_POST["model"]);
    $tahunProduksi = intval($_POST["tahunProduksi"]);
    $namaBarang = trim($_POST["namaBarang"]);
    $harga = floatval($_POST["harga"]);
    $stok = intval($_POST["stok"]);
    $fotoProduk = "";

    // upload file foto
    if (
        isset($_FILES["fotoProduk"]) &&
        $_FILES["fotoProduk"]["error"] === UPLOAD_ERR_OK
    ) {
        $uploadDir = "uploads/";
        if (!is_dir($uploadDir)) {
            mkdir($uploadDir, 0777, true);
        }
        $fileName = basename($_FILES["fotoProduk"]["name"]);
        $targetFile = $uploadDir . time() . "_" . $fileName;

        if (
            move_uploaded_file($_FILES["fotoProduk"]["tmp_name"], $targetFile)
        ) {
            $fotoProduk = $targetFile;
        }
    }

    $barangBaru = new DetailBarang(
        $idKategori,
        $namaKategori,
        $deskripsi,
        $merk,
        $model,
        $tahunProduksi,
        $namaBarang,
        $harga,
        $stok,
        $fotoProduk
    );

    $_SESSION["dataBarang"][] = $barangBaru;
}

$dataBarang = $_SESSION["dataBarang"];
?>
<!DOCTYPE html>
<html>
<head>
    <title>Sistem Manajemen Toko Elektronik (Inheritance)</title>
    <!-- buat css -->
    <link rel="stylesheet" href="./css/style.css"> 
</head>
<body>
    <div class="header">
        <h1>Sistem Manajemen Toko Elektronik (Inheritance)</h1>
    </div>

    <!-- form section -->
    <div class="form-section">
    <h2>Tambah Data Barang</h2>
    <form method="POST" enctype="multipart/form-data">
        <div class="form-grid">
            <div class="form-group">
                <label>ID Kategori:</label>
                <input type="text" name="idKategori" required>
            </div>

            <div class="form-group">
                <label>Nama Kategori:</label>
                <input type="text" name="namaKategori" required>
            </div>

            <div class="form-group">
                <label>Deskripsi:</label>
                <input type="text" name="deskripsi">
            </div>

            <div class="form-group">
                <label>Merk:</label>
                <input type="text" name="merk" required>
            </div>

            <div class="form-group">
                <label>Model:</label>
                <input type="text" name="model">
            </div>

            <div class="form-group">
                <label>Tahun Produksi:</label>
                <input type="number" name="tahunProduksi">
            </div>

            <div class="form-group">
                <label>Nama Barang:</label>
                <input type="text" name="namaBarang" required>
            </div>

            <div class="form-group">
                <label>Harga:</label>
                <input type="number" step="0.01" name="harga">
            </div>

            <div class="form-group">
                <label>Stok:</label>
                <input type="number" name="stok">
            </div>

            <div class="form-group">
                <label>Foto Produk (Upload File):</label>
                <input type="file" name="fotoProduk" accept="image/*">
            </div>
        </div>

        <!-- button tambah -->
        <button type="submit" class="btn" name="tambah">Tambah</button>
    </form>
</div>

    <!-- table section -->
    <div class="table-section">
        <table class="data-table">
        <h2>Daftar Barang</h2>
        <tr>
            <th>ID Kategori</th>
            <th>Nama Kategori</th>
            <th>Deskripsi</th>
            <th>Merk</th>
            <th>Model</th>
            <th>Tahun Produksi</th>
            <th>Nama Barang</th>
            <th>Harga</th>
            <th>Stok</th>
            <th>Foto Produk</th>
        </tr>
        <!-- looping buat nampilin data -->
        <?php foreach ($dataBarang as $barang): ?>
            <tr>
                <td><?= htmlspecialchars($barang->getIdKategori()) ?></td>
                <td><?= htmlspecialchars($barang->getNamaKategori()) ?></td>
                <td><?= htmlspecialchars($barang->getDeskripsi()) ?></td>
                <td><?= htmlspecialchars($barang->getMerk()) ?></td>
                <td><?= htmlspecialchars($barang->getModel()) ?></td>
                <td><?= htmlspecialchars($barang->getTahunProduksi()) ?></td>
                <td><?= htmlspecialchars($barang->getNamaBarang()) ?></td>
                <td><?= htmlspecialchars($barang->getHarga()) ?></td>
                <td><?= htmlspecialchars($barang->getStok()) ?></td>
                <td>
                    <?php if ($barang->getFotoProduk()): ?>
                        <img src="<?= htmlspecialchars(
                            $barang->getFotoProduk()
                        ) ?>" alt="Foto Produk">
                    <?php else: ?>
                        (Tidak ada foto)
                    <?php endif; ?>
                </td>
            </tr>
        <?php endforeach; ?>
    </table>
    </div>
</body>
</html>
