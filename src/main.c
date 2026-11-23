#include <stdio.h>
#include <string.h>
#include "../include/userManagement.h"
#include "../include/adminDashboard.h"
#include "../include/customerDashboard.h"
#include "../include/util.h"

int main() {
    int pilihan;

    inisialisasiUser(); // membuat akun admin bawaan

    do {
        printf("\n====================================\n");
        printf("     ONLINE SHOP BERBASIS KONSOL\n");
        printf("====================================\n");
        printf("1. Registrasi\n");
        printf("2. Login\n");
        printf("3. Keluar\n");
        printf("------------------------------------\n");
        printf("Pilih menu: ");
        pilihan = bacaInt();

        switch (pilihan) {
        case 1:
            registrasiUser();
            break;
        case 2:
            if (loginUser()) {
                // arahkan ke dashboard sesuai role
                if (strcmp(users[userAktif].role, "admin") == 0) {
                    menuAdmin();
                } else {
                    menuCustomer();
                }
            }
            break;
        case 3:
            printf("Terima kasih telah menggunakan aplikasi ini!\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 3);

    return 0;
}
