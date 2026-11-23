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

// ===== DITAMBAHKAN: fungsi penghubung antar modul =====
int tambahPesanan(int idPengguna, const char *namaProduk, int jumlah, float hargaSatuan); // return ID pesanan, 0 jika penuh
void tampilRiwayatTransaksiUser(int idPengguna);   // riwayat milik 1 pengguna (tanpa input ID manual)
void tampilTotalPengeluaranUser(int idPengguna);   // total pengeluaran 1 pengguna
void batalkanPesananSaya(int idPengguna);          // customer hanya boleh batalkan pesanan miliknya
void tampilSemuaPesanan();                         // admin
void ubahStatusPesanan();                          // admin
void tampilLaporanPenjualan();                     // admin

#endif
