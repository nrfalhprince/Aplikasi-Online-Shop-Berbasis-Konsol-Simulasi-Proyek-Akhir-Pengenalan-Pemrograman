Aplikasi Online Shop Berbasis Konsol
Aplikasi ini merupakan sebuah proyek untuk memenuhi tugas akhir Pengenalan Pemrograman. Aplikasi Online Shop Berbasis konsol ini mensimulasikan bagaimana cara apklikasi online shop yang nyata seperti Shoppe, Tokopedia, Lazada, dll bekerja.

Anggota kelompok 8:
- Fazly Mawla Athaya Arifianto (26071103379)
- Muhammad Nur Falah (26071102353)
- Natanael Marbun (26071104647)
- Sekar Fadiyah Sakhi (26071103876)

Fitur Aplikasi

1. Manajemen Pengguna (User Management)

- Registrasi akun pengguna baru.
- Login dan autentikasi pengguna.
- Pengelolaan profil pelanggan.
- Identifikasi hak akses berdasarkan peran pengguna (Admin dan Customer).
- Aktivasi dan penonaktifan akun pengguna.

2. Katalog Produk (Product Catalog)

- Menampilkan daftar produk yang tersedia.
- Mencari produk berdasarkan nama.
- Menampilkan produk berdasarkan kategori.
- Melihat harga dan ketersediaan stok produk.
- Pengelolaan produk oleh administrator.

3. Keranjang Belanja (Shopping Cart)

- Menambahkan produk ke keranjang belanja.
- Mengubah jumlah produk yang dibeli.
- Menghapus produk dari keranjang.
- Menghitung subtotal belanja.

4. Sistem Checkout (Checkout System)

- Memvalidasi keranjang belanja sebelum melakukan pemesanan.
- Menghitung total pembelian.
- Menerapkan diskon dan voucher yang tersedia.
- Menghitung biaya pengiriman.
- Membuat rincian pesanan.

5. Sistem Pembayaran (Payment System)

- Simulasi beberapa metode pembayaran.
- Validasi pembayaran.
- Pengelolaan status pembayaran.
- Konfirmasi transaksi.

6. Manajemen Pesanan (Order Management)

- Melihat riwayat pesanan pelanggan.
- Melihat detail transaksi.
- Melacak status pesanan.
- Memperbarui status pesanan oleh administrator.
- Mengelola pembatalan pesanan.

7. Dashboard Administrator (Admin Dashboard)

- Melihat daftar pelanggan yang terdaftar.
- Mengelola akun pengguna.
- Mengelola inventaris produk.
- Mengelola pesanan pelanggan.
- Melihat laporan penjualan.
- Memantau aktivitas toko.

---
Penjelasan Modul (fitur)

"main.c"| Titik awal program dan pengatur navigasi menu aplikasi.
"models.h"| Menyimpan definisi struktur data yang digunakan bersama oleh berbagai modul.
"userManagement"| Mengelola registrasi, login, dan profil pengguna.
"adminDashboard"| Menyediakan fitur pengelolaan khusus administrator.
"productCatalog"| Mengelola katalog dan inventaris produk.
"shoppingCart"| Mengelola keranjang belanja pelanggan.
"checkout"| Menangani validasi pesanan dan perhitungan pembelian.
"payment"| Menangani simulasi proses pembayaran.
"orderManagement"| Mengelola pesanan dan status transaksi.
"database"| Menangani penyimpanan dan pembacaan data aplikasi.
