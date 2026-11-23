#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#define MAX_KERANJANG 20

float cart(char *items[], int *jumlahPerItem, float *hargaPerItem, int *sizeItems);
int tambahKeKeranjang(char *items[], int *jumlahPerItem, float *hargaPerItem, int *sizeItems, int idProduk, int jumlah);

#endif
