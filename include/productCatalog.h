#ifndef PRODUCT_CATALOG_H
#define PRODUCT_CATALOG_H

#define MAX_PRODUK 100
#define TARIF_ONGKIR_PER_KM 1000

typedef struct {
    int id;
    char nama[50];
    char kategori[30];
    float harga;
    int stok;
} Produk;

void tampilSemuaProduk();
void cariProdukByNama();
void filterByKategori();
void tampilHargaStok();
void urutkanByHarga();
void tampilStokTerbanyakTermurah();
void tampilOngkir();

#endif