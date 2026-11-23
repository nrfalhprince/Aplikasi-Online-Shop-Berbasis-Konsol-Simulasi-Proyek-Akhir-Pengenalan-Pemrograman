#include <stdio.h>
#include <string.h>

float cart(char *items[], int *jumlahPerItem, float *hargaPerItem, int *sizeItems){
    while (1){
        if (*sizeItems == 0){
            printf("Keranjang kamu kosong!\n"); // Jika keranjang kosong maka fungsi otomatis keluar dan mengembalikan nilai "0"
            return 0;
        }
        float total = 0.0f;

        printf("=============Keranjang Saya=============\n");
        for (int i = 0; i < *sizeItems; i++){ // Pada for loop ini, akan menampilkan setiap nomor barang, nama barang, jumlahnya di keranjang, harga per item, dan 
            printf("Barang #%d\n", i + 1);   //subtotal untuk masing masing barang
            printf("Nama barang: %s\n", items[i]);        
            printf("Jumlah barang di keranjang: %d\n", jumlahPerItem[i]);        
            printf("Harga per item: Rp. %.0f\n", hargaPerItem[i]);
            printf("Subtotal: Rp. %.0f\n", jumlahPerItem[i] * hargaPerItem[i]);
            printf("----------------------------------------\n");
            total += jumlahPerItem[i] * hargaPerItem[i];
        }
        
        char pilihan = '\0'; // Menentukan pilihan (hanya ada 4 pilihan, jika memilih yang tidak ada dipilihan, maka akan diulang)
        while (pilihan != '1' && pilihan != '2' && pilihan != '3' && pilihan != '4'){
            printf("1. Ubah jumlah barang berdasarkan nomor\n");
            printf("2. Hapus barang\n");
            printf("3. Pergi ke pembayaran\n");
            printf("4. Kembali ke menu\n");
            printf("Pilihan anda: ");
            scanf(" %c", &pilihan);
            printf("----------------------------------------\n");
        }

        switch (pilihan){
            case '1': { // Jika pilihan nomor 1, maka: tentukan dulu barang yang mau diubah jumlahnya berdasarkan nomor dari barangnya
                int num = 0;
        
                while (num > *sizeItems || num < 1){
                    printf("Pilih barang berdasarkan nomor: ");
                    num = bacaInt();
                    printf("----------------------------------------\n");
                }
        
                int jumlahBaru = 0;
        
                while (jumlahBaru <= 0){
                    printf("Pilih jumlah baru: ");
                    jumlahBaru = bacaInt();
                    printf("----------------------------------------\n");
                }

                // Jadi di sini memvalidasi jumlah tidak boleh melebihi stok
                Produk *p = ambilProdukByNama(items[num - 1]);
                if (p != NULL && jumlahBaru > p->stok){
                    printf("Stok tidak cukup! Stok tersedia: %d\n", p->stok);
                    break;
                }
                jumlahPerItem[num - 1] = jumlahBaru;
                break;
            }

            case '2': {
                int numHapus = 0; // Jadi ini akan menghapus barang berdasarkan nomor barangnya, maka dari itu user harus memilih nomor barang yang ingin dihapus

                while (numHapus > *sizeItems || numHapus < 1){
                    printf("Pilih Nomor barang yang ingin dihapus: ");
                    numHapus = bacaInt();
                    printf("----------------------------------------\n");
                }
                (*sizeItems)--;

                for (int i = numHapus - 1; i < *sizeItems; i++){
                    items[i] = items[i + 1];
                    jumlahPerItem[i] = jumlahPerItem[i + 1];
                    hargaPerItem[i] = hargaPerItem[i + 1];
                }

                break;
            }

            case '3':
                printf("Total belanjaan kamu adalah: Rp. %.0f\n", total); // Menampilkan jumlah harga keseluruhan dari masing-masing subtotal
                return total;

            case '4': // jalan keluar dari keranjang tanpa checkout
                return 0;
        }
    }
}

int tambahKeKeranjang(char *items[], int *jumlahPerItem, float *hargaPerItem, int *sizeItems, int idProduk, int jumlah){
    Produk *p = ambilProdukById(idProduk);

    if (p == NULL){
        printf("Produk dengan ID %d tidak ditemukan!\n", idProduk);
        return 0;
    }
    if (jumlah <= 0){
        printf("Jumlah harus lebih dari 0!\n");
        return 0;
    }

    // Jadi pada kode ini, memvalidasi produk jika sudah ada di keranjang maka, cukup tambah jumlahnya
    for (int i = 0; i < *sizeItems; i++){
        if (strcmp(items[i], p->nama) == 0){
            if (jumlahPerItem[i] + jumlah > p->stok){
                printf("Stok tidak cukup! Stok tersedia: %d (sudah ada %d di keranjang)\n", p->stok, jumlahPerItem[i]);
                return 0;
            }
            jumlahPerItem[i] += jumlah;
            printf("Jumlah %s di keranjang menjadi %d.\n", p->nama, jumlahPerItem[i]);
            return 1;
        }
    }

    if (*sizeItems >= MAX_KERANJANG){
        printf("Keranjang penuh (maksimal %d jenis barang)!\n", MAX_KERANJANG);
        return 0;
    }
    if (jumlah > p->stok){
        printf("Stok tidak cukup! Stok tersedia: %d\n", p->stok);
        return 0;
    }

    items[*sizeItems] = p->nama;
    jumlahPerItem[*sizeItems] = jumlah;
    hargaPerItem[*sizeItems] = p->harga;
    (*sizeItems)++;
    printf("%s berhasil ditambahkan ke keranjang.\n", p->nama);
    return 1;
}
