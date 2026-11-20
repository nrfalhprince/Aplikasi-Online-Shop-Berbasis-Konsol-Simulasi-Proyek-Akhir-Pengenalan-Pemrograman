#include <stdio.h>

float cart(char *items[], int *jumlahPerItem, float *hargaPerItem, int sizeItems){
    while (1){
        if (sizeItems == 0){
            printf("Keranjang kamu masih kosong!\n"); // Jika keranjang kosong maka fungsi otomatis keluar dan mengembalikan nilai "0"
            return 0;
        }
        float total = 0.0f;

        printf("=============Keranjang Saya=============\n");
        for (int i = 0; i < sizeItems; i++){ // Pada for loop ini, akan menampilkan setiap nomor barang, nama barang, jumlahnya di keranjang, harga per item, dan 
            printf("Barang #%d\n", i + 1);   //subtotal untuk masing masing barang
            printf("Nama barang: %s\n", items[i]);        
            printf("Jumlah barang di keranjang: %d\n", jumlahPerItem[i]);        
            printf("Harga per item: Rp. %.3f\n", hargaPerItem[i]);
            printf("Subtotal: Rp. %.3f\n", jumlahPerItem[i] * hargaPerItem[i]);
            printf("----------------------------------------\n");
            total += jumlahPerItem[i] * hargaPerItem[i];
        }
        
        char pilihan = '\0'; // Menentukan pilihan (hanya ada 2 pilihan, jika memilih yang tidak ada dipilihan, maka akan diulang)
        while (pilihan != '1' && pilihan != '2'){
            printf("1. Ubah jumlah barang berdasarkan nomor\n");
            printf("2. Pergi ke pembayaran\n");
            printf("Pilihan anda: ");
            scanf(" %c", &pilihan);
            printf("----------------------------------------\n");
        }

        if (pilihan == '1'){ // Jika pilihan nomor 1, maka: tentukan dulu barang yang mau diubah jumlahnya berdasarkan nomor dari barangnya 
            int num = 0;

            while (num > sizeItems || num < 1){
                printf("Pilih barang berdasarkan nomor: ");
                scanf("%d", &num);
                printf("----------------------------------------\n");
            }
    
            int jumlahBaru = 0;

            while (jumlahBaru <= 0){
                printf("Pilih jumlah baru: ");
                scanf("%d", &jumlahBaru);
                printf("----------------------------------------\n");
                jumlahPerItem[num - 1] = jumlahBaru;
            }
        }

        else if (pilihan == '2'){
            printf("Total belanjaan kamu adalah: Rp. %.3f\n", total); // Menampilkan jumlah harga keseluruhan dari masing-masing subtotal
            return total;
        }

        else{
            printf("Pilihan mu invalid, mohon untuk mencoba lagi!\n\n"); // Jika pilihan tidak ada di menu, maka akan menampilkan pesan error dan mengulang kembali
        }
    }
}
