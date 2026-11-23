// Dibuat oleh Fazly Mawla Athaya Arifianto
// 21 November 2026
#include <stdio.h>
#include <string.h>
#include "../include/adminDashboard.h"
#include "../include/userManagement.h"

// fungsi menampilkan daftar pengguna aktif
void tampilkanDaftarUser() {
    printf("\n===== DAFTAR PENGGUNA AKTIF =====\n");
    if (jumlahUser <= 1) { // akun admin tidak termasuk
        printf("Tidak ada customer terdaftar.\n");
    } else {
        printf("%-5s %-20s %-15s %-12s\n", "ID", "NAMA", "USERNAME", "STATUS");
        printf("-----------------------------------------------\n");
        // menggunakan operator ternary
        for (int i = 0; i < jumlahUser; i++) {
            if (strcmp(users[i].role, "customer") == 0) {
                printf("%-5d %-20s %-15s %-12s\n", 
                    users[i].id, 
                    users[i].nama, 
                    users[i].username, 
                    users[i].status == 1 
                    ? "Aktif" 
                    : "Nonaktif");
            }
        }
    }
}

// fungsi untuk mengubah status akun user
void ubahStatusUser() {
    int pilihan, id, ditemukan = 0;

    printf("Masukkan ID akun pengguna: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahUser; i++) {
        if (users[i].id == id) {
            if (strcmp(users[i].role, "customer") == 0) {
                ditemukan = 1;

                printf("\nNama Pengguna: %s\n", users[i].nama);
                // gunakan operator ternary untuk mengecek status akun pengguna
                printf("Status saat ini: %s\n", users[i].status == 1 ? "Aktif" : "Nonaktif");

                printf("\n1. Aktifkan akun\n");
                printf("2. Nonaktifkan akun\n");
                printf("Pilih tindakan: ");
                scanf("%d", &pilihan);

                switch (pilihan) {
                case 1:
                    users[i].status = 1;
                    printf("Akun berhasil diaktifkan!\n");
                    break;
                case 2:
                    users[i].status = 0;
                    printf("Akun berhasil dinonaktifkan!\n");
                    break;
                default:
                    printf("Pilihan tidak valid!!\n");
                }
            } else {
                printf("\nAkun tersebut bukan customer!\n");
                ditemukan = 1;
            }
        }
    }
    if (ditemukan == 0) {
        printf("\nID pengguna tidak ditemukan!\n");
    }
}

void menuAdmin() {
    int pilihan;

    // validasi hak admin
    if (userAktif == -1 || strcmp(users[userAktif].role, "admin") != 0) {
        printf("Akses ditolak! Kamu bukan admin!");
    } do {
        printf("\n====================================\n");
        printf("          DASHBOARD ADMIN\n");
        printf("====================================\n");

        printf("Selamat datang, %s!\n", users[userAktif].nama);

        printf("------------------------------------\n");
        printf("1. Daftar Pengguna\n");
        printf("2. Kelola Akun Pengguna\n");
        printf("3. Kelola Produk\n");
        printf("4. Kelola Pesanan\n");
        printf("5. Laporan Penjualan\n");
        printf("6. Logout Admin\n");
        printf("------------------------------------\n");

        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tampilkanDaftarUser();
            break;
        case 2:
            ubahStatusUser();
            break;
        case 3:
            tampilkanDaftarUser();
            break;
        case 4:
            tampilkanDaftarUser();
            break;
        case 5:
            tampilkanDaftarUser();
            break;
        case 6:
            logoutUser();
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 6);
    
}