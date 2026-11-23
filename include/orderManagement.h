#ifndef ORDER_MANAGEMENT_H
#define ORDER_MANAGEMENT_H

#define MAX_PESANAN 100

typedef struct {
    int idPesanan;
    int idPengguna;
    char namaProduk[50];
    int jumlah;
    float hargaSatuan;
    char status[20];
} Pesanan;

void tampilRiwayatTransaksi();
void tampilStatusPesanan();
void tampilDetailPembelian();
void batalkanPesanan();
void tampilTotalPengeluaran();

#endif