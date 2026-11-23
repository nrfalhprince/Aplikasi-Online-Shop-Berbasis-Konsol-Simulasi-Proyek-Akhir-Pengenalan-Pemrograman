#include <stdio.h>
#include <string.h>
#include "../include/customerDashboard.h"
#include "../include/userManagement.h"

// fungsi untuk menampilkan dashboard customer
void menuCustomer() {
    int pilihan;

    // validasi hak akses customer
    if (userAktif == -1 || strcmp(users[userAktif].role, "customer") != 0) {
        printf("\nAkses ditolak! Khusus customer.\n");
        return;
    } do {
        printf("\n====================================\n");
        printf("          DASHBOARD CUSTOMER\n");
        printf("====================================\n");

        printf("Selamat datang, %s\n", users[userAktif].nama);

        printf("------------------------------------\n");
        printf("1. Katalog Produk\n");
        printf("2. Keranjang Saya\n");
        printf("3. OrderanKu\n");
        printf("4. Profil Saya\n");
        printf("5. Logout\n");
        printf("------------------------------------\n");

        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            tampilkanProfil();
            break;
        case 5:
            logoutUser();
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 5);
}