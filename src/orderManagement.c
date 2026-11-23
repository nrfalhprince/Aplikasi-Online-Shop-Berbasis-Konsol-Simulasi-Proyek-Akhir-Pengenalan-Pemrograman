#include <stdio.h>
#include <string.h>
#include "../include/orderManagement.h"
#include "../include/productCatalog.h"
#include "../include/util.h"

static Pesanan daftarPesanan[MAX_PESANAN] = { // Data awal pesanan: id pesanan, id pengguna, nama produk, jumlah, harga satuan, status
    {1, 1, "RAM DDR4 8GB",     2, 350000,  "Selesai"},
    {2, 1, "Mouse Wireless",   1, 120000,  "Dikirim"},
    {3, 1, "Monitor 24 Inch",  1, 1400000, "Diproses"},
    {4, 2, "RTX 3050 6GB",     1, 2500000, "Diproses"},
    {5, 2, "Webcam 1080p",     1, 450000,  "Selesai"},
    {6, 2, "Motherboard B550", 1, 1500000, "Dibatalkan"}
};

static int jumlahPesanan = 6; // Jumlah pesanan yang saat ini ada di daftar

void tampilRiwayatTransaksiUser(int idPengguna){
    int ditemukan = 0; // Penanda: 0 = belum ketemu, 1 = sudah ketemu

    printf("=============Riwayat Transaksi=============\n");

    for (int i = 0; i < jumlahPesanan; i++){ // Menampilkan hanya pesanan milik pengguna yang diinput
        if (daftarPesanan[i].idPengguna == idPengguna){
            printf("Pesanan #%d\n", daftarPesanan[i].idPesanan);
            printf("Nama produk: %s\n", daftarPesanan[i].namaProduk);
            printf("Total: Rp. %.0f\n", daftarPesanan[i].jumlah * daftarPesanan[i].hargaSatuan);
            printf("Status: %s\n", daftarPesanan[i].status);
            printf("----------------------------------------\n");
            ditemukan = 1;
        }
    }

    if (ditemukan == 0){
        printf("Riwayat transaksi tidak ditemukan!\n");
        printf("----------------------------------------\n");
    }
}

// versi asli: meminta ID pengguna secara manual (tetap dipertahankan)
void tampilRiwayatTransaksi(){
    int idPengguna;

    printf("Masukkan ID pengguna: ");
    scanf("%d", &idPengguna);
    printf("----------------------------------------\n");
    tampilRiwayatTransaksiUser(idPengguna);
}

void tampilStatusPesanan(){
    int idPesanan;
    int ditemukan = 0;

    printf("=============Status Pesanan=============\n");
    printf("Masukkan ID pesanan: ");
    scanf("%d", &idPesanan);
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahPesanan; i++){ // Mencari pesanan yang ID-nya sama dengan input
        if (daftarPesanan[i].idPesanan == idPesanan){
            printf("Pesanan #%d\n", daftarPesanan[i].idPesanan);
            printf("Nama produk: %s\n", daftarPesanan[i].namaProduk);
            printf("Status: %s\n", daftarPesanan[i].status);
            printf("----------------------------------------\n");
            ditemukan = 1;
        }
    }

    if (ditemukan == 0){
        printf("Pesanan tidak ditemukan!\n");
        printf("----------------------------------------\n");
    }
}

void tampilDetailPembelian(){
    int idPesanan;
    int ditemukan = 0;

    printf("=============Detail Pembelian=============\n");
    printf("Masukkan ID pesanan: ");
    scanf("%d", &idPesanan);
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahPesanan; i++){
        if (daftarPesanan[i].idPesanan == idPesanan){
            printf("Pesanan #%d\n", daftarPesanan[i].idPesanan);
            printf("ID pengguna: %d\n", daftarPesanan[i].idPengguna);
            printf("Nama produk: %s\n", daftarPesanan[i].namaProduk);
            printf("Jumlah: %d\n", daftarPesanan[i].jumlah);
            printf("Harga satuan: Rp. %.0f\n", daftarPesanan[i].hargaSatuan);
            printf("Total: Rp. %.0f\n", daftarPesanan[i].jumlah * daftarPesanan[i].hargaSatuan);
            printf("Status: %s\n", daftarPesanan[i].status);
            printf("----------------------------------------\n");
            ditemukan = 1;
        }
    }

    if (ditemukan == 0){
        printf("Pesanan tidak ditemukan!\n");
        printf("----------------------------------------\n");
    }
}

// idPengguna = -1 berarti admin (jika admin maka, boleh membatalkan pesanan siapa saja)
static void batalkanPesananCore(int idPengguna){
    int idPesanan;
    int ditemukan = 0;

    printf("=============Batalkan Pesanan=============\n");
    printf("Ketentuan: pesanan hanya dapat dibatalkan jika status masih Diproses\n");
    printf("Masukkan ID pesanan: ");
    scanf("%d", &idPesanan);
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahPesanan; i++){
        if (daftarPesanan[i].idPesanan == idPesanan){
            // DITAMBAHKAN: customer tidak boleh membatalkan pesanan milik orang lain
            if (idPengguna != -1 && daftarPesanan[i].idPengguna != idPengguna){
                continue;
            }
            ditemukan = 1;

            if (strcmp(daftarPesanan[i].status, "Diproses") == 0){ // Hanya status Diproses yang boleh dibatalkan
                strcpy(daftarPesanan[i].status, "Dibatalkan");
                tambahStokProduk(daftarPesanan[i].namaProduk, daftarPesanan[i].jumlah); // DITAMBAHKAN: stok dikembalikan
                printf("Pesanan #%d berhasil dibatalkan!\n", daftarPesanan[i].idPesanan);
            } else if (strcmp(daftarPesanan[i].status, "Dibatalkan") == 0){
                printf("Pesanan sudah dibatalkan sebelumnya!\n");
            } else {
                printf("Pesanan tidak dapat dibatalkan karena status sudah %s!\n", daftarPesanan[i].status);
            }
            printf("----------------------------------------\n");
        }
    }

    if (ditemukan == 0){
        printf("Pesanan tidak ditemukan!\n");
        printf("----------------------------------------\n");
    }
}

void batalkanPesanan(){
    batalkanPesananCore(-1);
}

void batalkanPesananSaya(int idPengguna){
    batalkanPesananCore(idPengguna);
}

void tampilTotalPengeluaranUser(int idPengguna){
    int ditemukan = 0;
    float total = 0; // Menyimpan jumlah pengeluaran, pesanan yang dibatalkan tidak dihitung

    printf("=============Total Pengeluaran=============\n");

    for (int i = 0; i < jumlahPesanan; i++){
        if (daftarPesanan[i].idPengguna == idPengguna){
            ditemukan = 1;
            if (strcmp(daftarPesanan[i].status, "Dibatalkan") != 0){
                total = total + daftarPesanan[i].jumlah * daftarPesanan[i].hargaSatuan;
            }
        }
    }

    if (ditemukan == 1){
        printf("Total pengeluaran: Rp. %.0f\n", total);
        printf("----------------------------------------\n");
    } else {
        printf("Belum ada transaksi untuk pengguna ini!\n");
        printf("----------------------------------------\n");
    }
}

// versi asli: meminta ID pengguna secara manual (tetap dipertahankan)
void tampilTotalPengeluaran(){
    int idPengguna;

    printf("Masukkan ID pengguna: ");
    scanf("%d", &idPengguna);
    printf("----------------------------------------\n");
    tampilTotalPengeluaranUser(idPengguna);
}

// ===================== DITAMBAHKAN =====================
// dipanggil setelah pembayaran berhasil
int tambahPesanan(int idPengguna, const char *namaProduk, int jumlah, float hargaSatuan){
    if (jumlahPesanan >= MAX_PESANAN){
        return 0;
    }

    daftarPesanan[jumlahPesanan].idPesanan = daftarPesanan[jumlahPesanan - 1].idPesanan + 1;
    daftarPesanan[jumlahPesanan].idPengguna = idPengguna;
    strncpy(daftarPesanan[jumlahPesanan].namaProduk, namaProduk, sizeof(daftarPesanan[jumlahPesanan].namaProduk) - 1);
    daftarPesanan[jumlahPesanan].namaProduk[sizeof(daftarPesanan[jumlahPesanan].namaProduk) - 1] = '\0';
    daftarPesanan[jumlahPesanan].jumlah = jumlah;
    daftarPesanan[jumlahPesanan].hargaSatuan = hargaSatuan;
    strcpy(daftarPesanan[jumlahPesanan].status, "Diproses");

    jumlahPesanan++;
    return daftarPesanan[jumlahPesanan - 1].idPesanan;
}

void tampilSemuaPesanan(){
    printf("=============Semua Pesanan=============\n");
    for (int i = 0; i < jumlahPesanan; i++){
        printf("Pesanan #%d | User ID: %d | %s x%d | Total: Rp. %.0f | %s\n",
               daftarPesanan[i].idPesanan, daftarPesanan[i].idPengguna,
               daftarPesanan[i].namaProduk, daftarPesanan[i].jumlah,
               daftarPesanan[i].jumlah * daftarPesanan[i].hargaSatuan,
               daftarPesanan[i].status);
    }
    printf("----------------------------------------\n");
}

void ubahStatusPesanan(){
    int idPesanan, pilihan;
    int ditemukan = 0;

    printf("=============Ubah Status Pesanan=============\n");
    printf("Masukkan ID pesanan: ");
    idPesanan = bacaInt();

    for (int i = 0; i < jumlahPesanan; i++){
        if (daftarPesanan[i].idPesanan == idPesanan){
            ditemukan = 1;

            if (strcmp(daftarPesanan[i].status, "Dibatalkan") == 0 || strcmp(daftarPesanan[i].status, "Selesai") == 0){
                printf("Status pesanan sudah %s dan tidak dapat diubah!\n", daftarPesanan[i].status);
                return;
            }

            printf("Status saat ini: %s\n", daftarPesanan[i].status);
            printf("1. Dikirim\n2. Selesai\nPilih status baru: ");
            pilihan = bacaInt();

            if (pilihan == 1){
                strcpy(daftarPesanan[i].status, "Dikirim");
                printf("Status pesanan #%d diubah menjadi Dikirim.\n", idPesanan);
            } else if (pilihan == 2){
                strcpy(daftarPesanan[i].status, "Selesai");
                printf("Status pesanan #%d diubah menjadi Selesai.\n", idPesanan);
            } else {
                printf("Pilihan tidak valid!\n");
            }
        }
    }

    if (ditemukan == 0){
        printf("Pesanan tidak ditemukan!\n");
    }
}

void tampilLaporanPenjualan(){
    int jmlDiproses = 0, jmlDikirim = 0, jmlSelesai = 0, jmlBatal = 0;
    float pendapatan = 0, tertunda = 0;
    int terlarisIdx = -1, terlarisJumlah = 0;

    for (int i = 0; i < jumlahPesanan; i++){
        float nilai = daftarPesanan[i].jumlah * daftarPesanan[i].hargaSatuan;

        if (strcmp(daftarPesanan[i].status, "Selesai") == 0){
            jmlSelesai++;
            pendapatan += nilai;
        } else if (strcmp(daftarPesanan[i].status, "Dibatalkan") == 0){
            jmlBatal++;
        } else if (strcmp(daftarPesanan[i].status, "Dikirim") == 0){
            jmlDikirim++;
            tertunda += nilai;
        } else {
            jmlDiproses++;
            tertunda += nilai;
        }

        // hitung total terjual untuk produk ini (pesanan batal tidak dihitung)
        if (strcmp(daftarPesanan[i].status, "Dibatalkan") != 0){
            int terjual = 0;
            for (int j = 0; j < jumlahPesanan; j++){
                if (strcmp(daftarPesanan[j].namaProduk, daftarPesanan[i].namaProduk) == 0 &&
                    strcmp(daftarPesanan[j].status, "Dibatalkan") != 0){
                    terjual += daftarPesanan[j].jumlah;
                }
            }
            if (terjual > terlarisJumlah){
                terlarisJumlah = terjual;
                terlarisIdx = i;
            }
        }
    }

    printf("=============Laporan Penjualan=============\n");
    printf("Total pesanan      : %d\n", jumlahPesanan);
    printf("  Diproses         : %d\n", jmlDiproses);
    printf("  Dikirim          : %d\n", jmlDikirim);
    printf("  Selesai          : %d\n", jmlSelesai);
    printf("  Dibatalkan       : %d\n", jmlBatal);
    printf("----------------------------------------\n");
    printf("Pendapatan (Selesai)        : Rp. %.0f\n", pendapatan);
    printf("Pendapatan tertunda (proses): Rp. %.0f\n", tertunda);
    if (terlarisIdx != -1){
        printf("Produk terlaris    : %s (%d terjual)\n", daftarPesanan[terlarisIdx].namaProduk, terlarisJumlah);
    }
    printf("----------------------------------------\n");
}
