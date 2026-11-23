#include <stdio.h>

float checkout(char *items[], int *jumlahPerItem, float *hargaPerItem, int sizeItems, float subtotal, float biayaPengiriman) {

    float totalPembayaran = subtotal + biayaPengiriman;
    int i = 0;

    printf("\n========== DETAIL CHECKOUT ==========\n");

    if (sizeItems == 0) {
        printf("Belum ada barang dalam keranjang.\n");
        return 0.0f;
    }

    printf("\nDaftar pesanan:\n");

    while (i < sizeItems) {
        printf("\nBarang       : %s\n", items[i]);
        printf("Jumlah       : %d\n", jumlahPerItem[i]);
        printf("Harga        : Rp %.0f\n", hargaPerItem[i]);
        printf("Total barang : Rp %.0f\n",
               jumlahPerItem[i] * hargaPerItem[i]);

        i++;
    }

    printf("\n========== TOTAL PEMBAYARAN ==========\n");
    printf("Harga barang : Rp %.0f\n", subtotal);
    printf("Ongkos kirim : Rp %.0f\n", biayaPengiriman);
    printf("--------------------------------------\n");
    printf("Total akhir  : Rp %.0f\n", totalPembayaran);
    printf("======================================\n");

    printf("\nPesanan siap dilanjutkan ke pembayaran.\n");

    return totalPembayaran;
}