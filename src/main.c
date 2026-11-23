#include <stdio.h>
#include <string.h>
#include "../include/adminDashboard.h"
#include "../include/userManagement.h"
#include "../include/customerDashboard.h"

int main() {
    int pilihan;

    inisialisasiUser();

    do {
        printf("\n==========================================\n");
        printf("   Aplikasi E-Commerce Berbasis Console\n");
        printf("==========================================\n");    

        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. About Us\n");
        printf("4. Exit\n");

        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            registrasiUser();
            break;
        case 2:
            if (loginUser() == 1) {
                if (strcmp(users[userAktif].role, "admin") == 0) {
                    menuAdmin();
                } else {
                    menuCustomer();
                }
            }
            break;
        case 3:
            printf("\nDibuat oleh kelompok 8 dengan sepenuh hati ❤️\n");
            break;
        case 4:
            printf("\nTerimakasih sudah menggunakan aplikasi ini!\n");
            break;
        default:
            printf("\nPilihan tidak valid!\n");
        }
    } while (pilihan != 4);

    return 0;
}