#include <stdio.h>
#include <string.h>
#include "../include/orderManagement.h"

static Pesanan daftarPesanan[MAX_PESANAN] = { // Data awal pesanan: id pesanan, id pengguna, nama produk, jumlah, harga satuan, status
    {1, 1, "RAM DDR4 8GB",     2, 350000,  "Selesai"},
    {2, 1, "Mouse Wireless",   1, 120000,  "Dikirim"},
    {3, 1, "Monitor 24 Inch",  1, 1400000, "Diproses"},
    {4, 2, "RTX 3050 6GB",     1, 2500000, "Diproses"},
    {5, 2, "Webcam 1080p",     1, 450000,  "Selesai"},
    {6, 2, "Motherboard B550", 1, 1500000, "Dibatalkan"}
};

static int jumlahPesanan = 6; // Jumlah pesanan yang saat ini ada di daftar

void tampilRiwayatTransaksi(){
    int idPengguna;
    int ditemukan = 0; // Penanda: 0 = belum ketemu, 1 = sudah ketemu

    printf("=============Riwayat Transaksi=============\n");
    printf("Masukkan ID pengguna: ");
    scanf("%d", &idPengguna);
    printf("----------------------------------------\n");

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

void batalkanPesanan(){
    int idPesanan;
    int ditemukan = 0;

    printf("=============Batalkan Pesanan=============\n");
    printf("Ketentuan: pesanan hanya dapat dibatalkan jika status masih Diproses\n");
    printf("Masukkan ID pesanan: ");
    scanf("%d", &idPesanan);
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahPesanan; i++){
        if (daftarPesanan[i].idPesanan == idPesanan){
            ditemukan = 1;

            if (strcmp(daftarPesanan[i].status, "Diproses") == 0){ // Hanya status Diproses yang boleh dibatalkan
                strcpy(daftarPesanan[i].status, "Dibatalkan");
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

void tampilTotalPengeluaran(){
    int idPengguna;
    int ditemukan = 0;
    float total = 0; // Menyimpan jumlah pengeluaran, pesanan yang dibatalkan tidak dihitung

    printf("=============Total Pengeluaran=============\n");
    printf("Masukkan ID pengguna: ");
    scanf("%d", &idPengguna);
    printf("----------------------------------------\n");

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
        printf("Pengguna tidak ditemukan!\n");
        printf("----------------------------------------\n");
    }
}