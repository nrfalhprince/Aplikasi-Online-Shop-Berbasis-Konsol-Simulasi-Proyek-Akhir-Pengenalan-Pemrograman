#include <stdio.h>

float checkout(char *items[], int *jumlahPerItem, float *hargaPerItem, int sizeItems, float subtotal, float biayaPengiriman){
    printf("Barang yang kamu beli:\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < sizeItems; i++){
        printf("#%d. %s: %d X Rp. %.3f = Rp. %.3f\n", i + 1, items[i], jumlahPerItem[i], hargaPerItem[i], jumlahPerItem[i] * hargaPerItem[i]);
    }
    printf("------------------------------------------\n");
    printf("Total belanja: Rp. %.3f\n", subtotal);
    printf("Biaya pengiriman: Rp. %.3f\n", biayaPengiriman);
    printf("Total pembayaran: Rp. %.3f\n", subtotal + biayaPengiriman);
    printf("------------------------------------------\n");
    printf("Estimasi kedatangan barang: 3-5\n");
    return subtotal + biayaPengiriman;
}
