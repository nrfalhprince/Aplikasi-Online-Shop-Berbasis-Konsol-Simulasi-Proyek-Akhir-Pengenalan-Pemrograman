# Aplikasi Online Shop Berbasis Konsol

Aplikasi simulasi toko online (e-commerce) yang dibangun dengan bahasa **C** dan dijalankan lewat konsol (*Command Line Interface*). Aplikasi ini meniru alur dasar platform belanja seperti Shopee, Tokopedia, atau Lazada: mulai dari registrasi akun, melihat katalog, mengisi keranjang, checkout, pembayaran, sampai memantau status pesanan. Toko dikelola oleh seorang admin.

Proyek ini dibuat sebagai tugas akhir mata kuliah **Pengenalan Pemrograman** oleh **Kelompok 8**.

## Anggota Kelompok 8

- Fazly Mawla Athaya Arifianto (26071103379)
- Muhammad Nur Falah (26071102353)
- Natanael Marbun (26071104647)
- Sekar Fadiyah Sakhi (26071103876)

---

## Daftar Isi

1. [Fitur](#fitur)
2. [Struktur Proyek](#struktur-proyek)
3. [Cara Memasang dan Menjalankan](#cara-memasang-dan-menjalankan)
4. [Cara Menggunakan Aplikasi](#cara-menggunakan-aplikasi)
5. [Alur Transaksi](#alur-transaksi)
6. [Penjelasan Modul](#penjelasan-modul)
7. [Keterbatasan](#keterbatasan)
8. [Pengembangan Selanjutnya](#pengembangan-selanjutnya)
9. [Pemecahan Masalah](#pemecahan-masalah)

---

## Fitur

### Customer

| Modul | Fitur |
|---|---|
| Akun | Registrasi (password minimal 8 karakter), login, lihat profil, logout |
| Katalog | Lihat semua produk, cari berdasarkan nama, filter kategori, urutkan berdasarkan harga, lihat stok terbanyak dan produk termurah, hitung ongkir |
| Keranjang | Tambah produk, ubah jumlah, hapus barang, lihat subtotal (jumlah dibatasi oleh stok) |
| Checkout | Hitung total belanja dan ongkos kirim (Rp 1.000 per km), tampilkan rincian pesanan |
| Pembayaran | Transfer Bank, E-Wallet (nominal harus sesuai, maksimal 3 kali percobaan), COD |
| OrderanKu | Riwayat transaksi, status pesanan, detail pembelian, pembatalan pesanan (hanya yang berstatus *Diproses*), total pengeluaran |

### Admin

| Modul | Fitur |
|---|---|
| Daftar pengguna | Lihat semua customer terdaftar |
| Kelola akun | Aktifkan atau nonaktifkan akun customer |
| Kelola produk | Lihat produk, tambah produk baru, ubah harga atau stok |
| Kelola pesanan | Lihat semua pesanan, ubah status (*Dikirim*, *Selesai*), batalkan pesanan |
| Laporan penjualan | Jumlah pesanan per status, pendapatan, dan produk terlaris |

---

## Struktur Proyek

```
Aplikasi-Online-Shop-Berbasis-Konsol-Simulasi-Proyek-Akhir-Pengenalan-Pemrograman/
├── include/                  # File header (.h): deklarasi struct dan fungsi
│   ├── userManagement.h
│   ├── productCatalog.h
│   ├── shoppingCart.h
│   ├── checkout.h
│   ├── payment.h
│   ├── orderManagement.h
│   ├── adminDashboard.h
│   ├── customerDashboard.h
│   └── util.h
├── src/                      # Kode sumber (.c)
│   ├── main.c
│   ├── userManagement.c
│   ├── productCatalog.c
│   ├── shoppingCart.c
│   ├── checkout.c
│   ├── payment.c
│   ├── orderManagement.c
│   ├── adminDashboard.c
│   ├── customerDashboard.c
│   └── util.c
└── README.md
```

---

## Cara Memasang dan Menjalankan

Aplikasi ini tidak perlu diinstal seperti aplikasi biasa. Langkahnya: siapkan *compiler*, unduh kode, ubah kode menjadi program (*compile*), lalu jalankan.

### 1. Siapkan compiler (gcc)

Cek dulu apakah gcc sudah terpasang:

```
gcc --version
```

Jika muncul nomor versi, lanjut ke langkah 2. Jika tidak, pasang sesuai sistem operasi:

**Windows**

1. Unduh dan pasang MSYS2 dari <https://www.msys2.org>.
2. Buka **MSYS2 UCRT64** dari Start Menu, lalu jalankan:
   ```
   pacman -S mingw-w64-ucrt-x86_64-gcc
   ```
3. Tambahkan folder `C:\msys64\ucrt64\bin` ke *PATH* Windows, lalu buka ulang Command Prompt atau PowerShell.
4. Cek dengan `gcc --version`.

Jika kamu memakai Code::Blocks atau Dev-C++, gcc biasanya sudah ikut terpasang bersama aplikasinya.

**Linux (Ubuntu/Debian)**

```
sudo apt update
sudo apt install build-essential
```

**macOS**

```
xcode-select --install
```

### 2. Unduh kode

Pilih salah satu:

- **Unduh ZIP:** di halaman GitHub repositori, klik tombol hijau **Code**, lalu **Download ZIP**, kemudian ekstrak.
- **Git clone:**
  ```
  git clone <URL-repositori-kalian>
  ```

### 3. Masuk ke folder proyek

Masuk ke folder yang berisi `src` dan `include`:

```
cd Aplikasi-Online-Shop-Berbasis-Konsol
```

Di Windows, cara cepatnya: buka folder tersebut di File Explorer, klik kolom alamat, ketik `cmd`, lalu tekan Enter.

### 4. Compile

```
gcc -std=c99 -Wall -Wextra -pedantic src/*.c -o toko
```

Jika berhasil, tidak ada pesan apa pun dan akan muncul file `toko` (di Windows: `toko.exe`). Alternatif jika `make` tersedia:

```
make
```

Jika tanda `*` tidak dikenali oleh terminalmu, tulis semua file secara manual:

```
gcc src/main.c src/util.c src/userManagement.c src/productCatalog.c src/shoppingCart.c src/checkout.c src/payment.c src/orderManagement.c src/adminDashboard.c src/customerDashboard.c -o toko
```

### 5. Jalankan

`./toko`

> Setiap kali kode diubah, ulangi langkah 4 supaya perubahan ikut masuk ke program.

---

## Cara Menggunakan Aplikasi

### Akun bawaan

| Peran | Username | Password |
|---|---|---|
| Admin | `admin` | `admin123` |

Akun customer dibuat sendiri lewat menu **Registrasi** di menu utama (password minimal 8 karakter).

### Contoh penggunaan sebagai customer

1. Menu utama, pilih **1. Registrasi**, isi nama, username, alamat, dan password.
2. Pilih **2. Login** dengan akun tadi.
3. Di dashboard, pilih **1. Katalog Produk**, lalu **7. Tambah produk ke keranjang**. Masukkan ID produk dan jumlahnya.
4. Kembali ke dashboard, pilih **2. Keranjang Saya**. Di sini kamu bisa mengubah jumlah atau menghapus barang. Pilih **3. Pergi ke pembayaran** jika sudah siap.
5. Masukkan jarak pengiriman (km), periksa rincian checkout, lalu pilih metode pembayaran.
6. Setelah pembayaran berhasil, pesanan dibuat dengan status *Diproses*. Pantau lewat **3. OrderanKu**.

### Contoh penggunaan sebagai admin

1. Login dengan akun `admin`.
2. **Kelola Akun Pengguna** untuk mengaktifkan atau menonaktifkan customer.
3. **Kelola Produk** untuk menambah produk atau mengubah harga dan stok.
4. **Kelola Pesanan** untuk mengubah status pesanan dari *Diproses* ke *Dikirim* lalu *Selesai*.
5. **Laporan Penjualan** untuk melihat ringkasan penjualan.

---

## Alur Transaksi

```
Login → Katalog → Tambah ke Keranjang → Keranjang → Checkout (ongkir) → Pembayaran
      → Pesanan dibuat (status Diproses) + stok berkurang → OrderanKu
      → Admin mengubah status (Dikirim → Selesai) → Laporan Penjualan
```

Status pesanan: **Diproses → Dikirim → Selesai**, atau **Dibatalkan**. Pembatalan hanya bisa dilakukan saat status masih *Diproses*, dan stok produk akan dikembalikan.

---

## Penjelasan Modul

| File | Fungsi |
|---|---|
| `main.c` | Titik awal program dan menu utama (Registrasi, Login, Keluar) |
| `userManagement` | Registrasi, login, logout, dan profil pengguna |
| `productCatalog` | Data dan pengelolaan katalog produk |
| `shoppingCart` | Keranjang belanja: tambah, ubah, hapus, hitung subtotal |
| `checkout` | Validasi keranjang dan perhitungan total beserta ongkir |
| `payment` | Simulasi pembayaran (Transfer Bank, E-Wallet, COD) |
| `orderManagement` | Pesanan, status, pembatalan, dan laporan penjualan |
| `adminDashboard` | Menu dan fitur khusus administrator |
| `customerDashboard` | Menu customer dan penghubung antara katalog, keranjang, checkout, pembayaran, dan pesanan |
| `util` | Fungsi bantu pembacaan input angka agar program tidak macet saat user mengetik huruf |

---

## Keterbatasan

- Data disimpan di memori, sehingga semua akun baru, pesanan, dan perubahan produk **hilang** saat program ditutup.
- Password disimpan apa adanya (tanpa enkripsi), cukup untuk keperluan simulasi.
- Satu pesanan mewakili satu jenis produk, dan ongkir belum disimpan di data pesanan.
- Pencarian produk dan filter kategori harus sama persis, termasuk huruf besar/kecil.
- Pembayaran hanya simulasi dan tidak terhubung ke layanan pembayaran sungguhan.

## Pengembangan Yang bisa dilanjutkan

- Menyimpan data ke file agar tidak hilang saat program ditutup.
- Pencarian produk yang tidak peka huruf besar/kecil dan mendukung sebagian kata.
- Menyimpan ongkir dan rincian pembayaran pada data pesanan.
- Menyembunyikan input password dan mengenkripsinya.

---

## Pemecahan Masalah

| Masalah | Penyebab dan solusi |
|---|---|
| `gcc` is not recognized / command not found | Compiler belum terpasang atau belum masuk PATH. Ikuti langkah 1 lalu buka ulang terminal. |
| `No such file or directory` saat compile | Kamu belum berada di folder proyek. Pastikan perintah dijalankan di folder yang berisi `src` dan `include`. |
| `undefined reference to ...` | Ada file `.c` yang tidak ikut ter-compile. Pakai perintah `src/*.c` atau tulis semua file seperti pada langkah 4. |
| Program langsung tertutup di Windows saat di-klik dua kali | Jalankan lewat Command Prompt atau PowerShell supaya tampilan tidak langsung hilang. |
| Tampilan karakter aneh | Gunakan terminal yang mendukung UTF-8, atau abaikan karena tidak memengaruhi fungsi program. |
