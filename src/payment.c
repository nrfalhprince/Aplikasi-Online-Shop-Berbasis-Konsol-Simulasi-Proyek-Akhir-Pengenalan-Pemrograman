#include <stdio.h>
#include "../include/payment.h"
#include "../include/util.h"

int prosesPembayaran(float totalPembayaran) {
    int metode = 0;

    printf("\n========== PEMBAYARAN ==========\n");
    printf("Total yang harus dibayar: Rp %.0f\n", totalPembayaran);
    printf("--------------------------------\n");

    while (metode < 1 || metode > 4) {
        printf("Pilih metode pembayaran:\n");
        printf("1. Transfer Bank\n");
        printf("2. E-Wallet\n");
        printf("3. COD (Bayar di tempat)\n");
        printf("4. Batalkan pembayaran\n");
        printf("Pilihan: ");
        metode = bacaInt();
    }

    if (metode == 4) {
        printf("\nPembayaran dibatalkan.\n");
        return 0;
    }

    if (metode == 3) {
        printf("\nMetode COD dipilih. Siapkan uang pas saat barang tiba.\n");
        printf("Status pembayaran: MENUNGGU (dibayar saat barang diterima)\n");
        return 1;
    }

    // Jika Transfer melalui Bank / E-Wallet terdapat vaildasi nominal jadi salah memasukan nomimal hanya sampai 3 kali percobaan
    printf("\n%s dipilih. Kode pembayaran: %s\n",
           metode == 1 ? "Transfer Bank" : "E-Wallet",
           metode == 1 ? "8801-2026-0001" : "0812-0000-2026");

    for (int percobaan = 1; percobaan <= 3; percobaan++) {
        float nominal;

        printf("Masukkan nominal pembayaran (percobaan %d/3): Rp ", percobaan);
        nominal = bacaFloat();

        if (nominal >= totalPembayaran - 0.5f && nominal <= totalPembayaran + 0.5f) {
            printf("\nPembayaran berhasil! Status pembayaran: LUNAS\n");
            return 1;
        }
        printf("Nominal tidak sesuai dengan total pembayaran!\n");
    }

    printf("\nPembayaran gagal (3x salah input). Pesanan tidak dibuat.\n");
    return 0;
}
