#include <stdio.h>
#include <string.h>
#include "../include/customerDashboard.h"
#include "../include/userManagement.h"
#include "../include/shoppingCart.h"
#include "../include/productCatalog.h"
#include "../include/orderManagement.h"
#include "../include/checkout.h"      // DITAMBAHKAN
#include "../include/payment.h"       // DITAMBAHKAN
#include "../include/util.h"          // DITAMBAHKAN

// ===================== DITAMBAHKAN =====================
// Data keranjang milik customer yang sedang login. Disimpan di sini supaya
// modul keranjang, checkout, dan pesanan memakai data yang sama.
static char *keranjangNama[MAX_KERANJANG];
static int keranjangJumlah[MAX_KERANJANG];
static float keranjangHarga[MAX_KERANJANG];
static int jumlahKeranjang = 0;

// submenu katalog: menghubungkan semua fungsi di productCatalog + tambah ke keranjang
static void menuKatalog() {
    int pilihan;
    do {
        printf("\n===== KATALOG PRODUK =====\n");
        printf("1. Semua produk\n");
        printf("2. Cari produk berdasarkan nama\n");
        printf("3. Filter berdasarkan kategori\n");
        printf("4. Urutkan berdasarkan harga\n");
        printf("5. Stok terbanyak & produk termurah\n");
        printf("6. Hitung ongkir\n");
        printf("7. Tambah produk ke keranjang\n");
        printf("0. Kembali\n");
        printf("Pilih menu: ");
        pilihan = bacaInt();

        switch (pilihan) {
        case 1: tampilSemuaProduk(); break;
        case 2: cariProdukByNama(); break;
        case 3: filterByKategori(); break;
        case 4: urutkanByHarga(); break;
        case 5: tampilStokTerbanyakTermurah(); break;
        case 6: tampilOngkir(); break;
        case 7: {
            int id, jumlah;
            tampilHargaStok();
            printf("Masukkan ID produk (lihat menu 1): ");
            id = bacaInt();
            printf("Jumlah: ");
            jumlah = bacaInt();
            tambahKeKeranjang(keranjangNama, keranjangJumlah, keranjangHarga, &jumlahKeranjang, id, jumlah);
            break;
        }
        case 0: break;
        default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);
}

// Jadi alurnya : checkout -> pembayaran -> pesanan dibuat -> stok berkurang -> keranjang dikosongkan
static void prosesCheckout(float subtotal) {
    float jarak = -1, ongkir, total;

    // memastikan stok masih mencukupi sebelum lanjut
    for (int i = 0; i < jumlahKeranjang; i++) {
        Produk *p = ambilProdukByNama(keranjangNama[i]);
        if (p == NULL || keranjangJumlah[i] > p->stok) {
            printf("Stok %s tidak mencukupi, silakan ubah jumlah di keranjang.\n", keranjangNama[i]);
            return;
        }
    }

    while (jarak < 0) {
        printf("Masukkan jarak pengiriman (km): ");
        jarak = bacaFloat();
    }
    ongkir = jarak * TARIF_ONGKIR_PER_KM;

    total = checkout(keranjangNama, keranjangJumlah, keranjangHarga, jumlahKeranjang, subtotal, ongkir);
    if (total <= 0) {
        return;
    }

    if (!prosesPembayaran(total)) {
        printf("Pesanan belum dibuat. Barang tetap ada di keranjang.\n");
        return;
    }

    // Jika pembayaran berhasil maka buat pesanan dan kurangi stok
    for (int i = 0; i < jumlahKeranjang; i++) {
        int idPesanan = tambahPesanan(users[userAktif].id, keranjangNama[i], keranjangJumlah[i], keranjangHarga[i]);
        if (idPesanan == 0) {
            printf("Gagal membuat pesanan untuk %s (kapasitas pesanan penuh)!\n", keranjangNama[i]);
        } else {
            tambahStokProduk(keranjangNama[i], -keranjangJumlah[i]);
            printf("Pesanan #%d dibuat: %s x%d\n", idPesanan, keranjangNama[i], keranjangJumlah[i]);
        }
    }
    jumlahKeranjang = 0; // mengkosongkan keranjang
    printf("Terima kasih sudah berbelanja! Pantau di menu OrderanKu.\n");
}

// Menghubungkan semua fungsi di orderManagement
static void menuOrderanKu() {
    int pilihan;
    do {
        printf("\n===== ORDERANKU =====\n");
        printf("1. Riwayat transaksi\n");
        printf("2. Status pesanan\n");
        printf("3. Detail pembelian\n");
        printf("4. Batalkan pesanan\n");
        printf("5. Total pengeluaran\n");
        printf("0. Kembali\n");
        printf("Pilih menu: ");
        pilihan = bacaInt();

        switch (pilihan) {
        case 1: tampilRiwayatTransaksiUser(users[userAktif].id); break;
        case 2: tampilStatusPesanan(); break;
        case 3: tampilDetailPembelian(); break;
        case 4: batalkanPesananSaya(users[userAktif].id); break;
        case 5: tampilTotalPengeluaranUser(users[userAktif].id); break;
        case 0: break;
        default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);
}

// fungsi untuk menampilkan dashboard customer
void menuCustomer() {
    int pilihan;

    // validasi hak akses customer
    if (userAktif == -1 || strcmp(users[userAktif].role, "customer") != 0) {
        printf("\nAkses ditolak! Khusus customer.\n");
        return;
    }

    jumlahKeranjang = 0; // DITAMBAHKAN: keranjang dimulai kosong untuk setiap sesi login

    do {
        printf("\n====================================\n");
        printf("          DASHBOARD CUSTOMER\n");
        printf("====================================\n");

        printf("Selamat datang, %s\n", users[userAktif].nama);

        printf("------------------------------------\n");
        printf("1. Katalog Produk\n");
        printf("2. Keranjang Saya\n");
        printf("3. OrderanKu\n");
        printf("4. Profil Saya\n");
        printf("5. Logout\n");
        printf("------------------------------------\n");

        printf("Pilih menu: ");
        pilihan = bacaInt(); // DIUBAH: scanf("%d") macet jika user mengetik huruf

        switch (pilihan) {
        case 1:
            menuKatalog(); // DIUBAH: sebelumnya hanya tampilSemuaProduk()
            break;
        case 2: { // DIISI: sebelumnya kosong
            float subtotal = cart(keranjangNama, keranjangJumlah, keranjangHarga, &jumlahKeranjang);
            if (subtotal > 0) {
                prosesCheckout(subtotal);
            }
            break;
        }
        case 3:
            menuOrderanKu(); // DIUBAH: sebelumnya tampilRiwayatTransaksi() yang minta ID manual
            break;
        case 4:
            tampilkanProfil();
            break;
        case 5:
            logoutUser();
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 5);
}
