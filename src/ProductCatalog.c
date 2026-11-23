#include <stdio.h>
#include <string.h>
#include "productCatalog.h"

static Produk daftarProduk[MAX_PRODUK] = { // Data awal produk: id, nama, kategori, harga, stok
    {1,  "RAM DDR4 8GB",       "RAM",         350000,  30},
    {2,  "RAM DDR5 16GB",      "RAM",         750000,  18},
    {3,  "RTX 3050 6GB",       "RTX",         2500000, 8},
    {4,  "RTX 4060 8GB",       "RTX",         4800000, 5},
    {5,  "Motherboard B550",   "Motherboard", 1500000, 9},
    {6,  "Motherboard H610",   "Motherboard", 1100000, 12},
    {7,  "Mouse Gaming",       "Mouse",       200000,  40},
    {8,  "Mouse Wireless",     "Mouse",       120000,  50},
    {9,  "Webcam 720p",        "Webcam",      250000,  28},
    {10, "Webcam 1080p",       "Webcam",      450000,  20},
    {11, "Monitor 24 Inch",    "Monitor",     1400000, 10},
    {12, "Monitor 27 Inch",    "Monitor",     2300000, 6}
};

static int jumlahProduk = 12; // Jumlah produk yang saat ini ada di daftar

void tampilSemuaProduk(){
    printf("=============Daftar Produk=============\n");
    for (int i = 0; i < jumlahProduk; i++){ // Menampilkan setiap produk: nomor, nama, kategori, harga, dan stok
        printf("Produk #%d\n", daftarProduk[i].id);
        printf("Nama produk: %s\n", daftarProduk[i].nama);
        printf("Kategori: %s\n", daftarProduk[i].kategori);
        printf("Harga: Rp. %.0f\n", daftarProduk[i].harga);
        printf("Stok: %d\n", daftarProduk[i].stok);
        printf("----------------------------------------\n");
    }
}

void cariProdukByNama(){
    char nama[50];
    int ditemukan = 0; // Penanda: 0 = belum ketemu, 1 = sudah ketemu

    printf("=============Cari Produk=============\n");
    printf("Masukkan nama produk: ");
    scanf(" %[^\n]", nama); // Membaca nama lengkap termasuk spasi
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahProduk; i++){ // Membandingkan nama yang diketik dengan nama setiap produk
        if (strcmp(daftarProduk[i].nama, nama) == 0){
            printf("Produk ditemukan!\n");
            printf("Nama produk: %s\n", daftarProduk[i].nama);
            printf("Kategori: %s\n", daftarProduk[i].kategori);
            printf("Harga: Rp. %.0f\n", daftarProduk[i].harga);
            printf("Stok: %d\n", daftarProduk[i].stok);
            printf("----------------------------------------\n");
            ditemukan = 1;
        }
    }

    if (ditemukan == 0){ // Jika tidak ada yang cocok, tampilkan pesan
        printf("Produk tidak ditemukan!\n");
        printf("----------------------------------------\n");
    }
}

void filterByKategori(){
    char kategori[30];
    int ditemukan = 0;

    printf("=============Filter Kategori=============\n");
    printf("Kategori tersedia: RAM, Motherboard, RTX, Monitor, Mouse, Webcam\n");
    printf("Masukkan kategori: ");
    scanf(" %[^\n]", kategori);
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahProduk; i++){ // Menampilkan hanya produk yang kategorinya sama dengan input
        if (strcmp(daftarProduk[i].kategori, kategori) == 0){
            printf("Nama produk: %s\n", daftarProduk[i].nama);
            printf("Harga: Rp. %.0f\n", daftarProduk[i].harga);
            printf("Stok: %d\n", daftarProduk[i].stok);
            printf("----------------------------------------\n");
            ditemukan = 1;
        }
    }

    if (ditemukan == 0){
        printf("Kategori tidak ditemukan!\n");
        printf("----------------------------------------\n");
    }
}

void tampilHargaStok(){
    printf("=============Harga dan Stok=============\n");
    for (int i = 0; i < jumlahProduk; i++){ // Menampilkan nama, harga, dan stok setiap produk
        printf("Nama produk: %s\n", daftarProduk[i].nama);
        printf("Harga: Rp. %.0f\n", daftarProduk[i].harga);
        printf("Stok: %d\n", daftarProduk[i].stok);
        printf("----------------------------------------\n");
    }
}

void urutkanByHarga(){
    Produk salinan[MAX_PRODUK]; // Salinan array, supaya urutan data asli tidak berubah
    Produk sementara;

    for (int i = 0; i < jumlahProduk; i++){
        salinan[i] = daftarProduk[i];
    }

    for (int i = 0; i < jumlahProduk - 1; i++){ // Bubble sort: harga termurah ke termahal
        for (int j = 0; j < jumlahProduk - i - 1; j++){
            if (salinan[j].harga > salinan[j + 1].harga){
                sementara = salinan[j];
                salinan[j] = salinan[j + 1];
                salinan[j + 1] = sementara;
            }
        }
    }

    printf("=============Urut Harga (Termurah)=============\n");
    for (int i = 0; i < jumlahProduk; i++){
        printf("Nama produk: %s\n", salinan[i].nama);
        printf("Harga: Rp. %.0f\n", salinan[i].harga);
        printf("Stok: %d\n", salinan[i].stok);
        printf("----------------------------------------\n");
    }
}

void tampilStokTerbanyakTermurah(){
    int stokTerbanyak = 0; // Menyimpan posisi produk dengan stok terbanyak
    int termurah = 0;      // Menyimpan posisi produk dengan harga termurah

    for (int i = 1; i < jumlahProduk; i++){ // Membandingkan setiap produk dengan yang sudah tercatat
        if (daftarProduk[i].stok > daftarProduk[stokTerbanyak].stok){
            stokTerbanyak = i;
        }
        if (daftarProduk[i].harga < daftarProduk[termurah].harga){
            termurah = i;
        }
    }

    printf("=============Stok Terbanyak=============\n");
    printf("Nama produk: %s\n", daftarProduk[stokTerbanyak].nama);
    printf("Stok: %d\n", daftarProduk[stokTerbanyak].stok);
    printf("----------------------------------------\n");

    printf("=============Produk Termurah=============\n");
    printf("Nama produk: %s\n", daftarProduk[termurah].nama);
    printf("Harga: Rp. %.0f\n", daftarProduk[termurah].harga);
    printf("----------------------------------------\n");
}
void tampilOngkir(){
    float jarak;

    printf("=============Ongkir Produk=============\n");
    printf("Masukkan jarak pengiriman (km): ");
    scanf("%f", &jarak);
    printf("----------------------------------------\n");

    for (int i = 0; i < jumlahProduk; i++){
        float ongkir = jarak * TARIF_ONGKIR_PER_KM;
        printf("Nama produk: %s\n", daftarProduk[i].nama);
        printf("Harga: Rp. %.0f\n", daftarProduk[i].harga);
        printf("Ongkir: Rp. %.0f\n", ongkir);
        printf("Total: Rp. %.0f\n", daftarProduk[i].harga + ongkir);
        printf("----------------------------------------\n");
    }
}