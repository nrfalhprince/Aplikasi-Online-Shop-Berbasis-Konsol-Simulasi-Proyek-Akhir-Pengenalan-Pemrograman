// Dibuat oleh Fazly Mawla Athaya Arifianto
// 20 November 2026

#include <stdio.h>
#include <string.h>
#include "../include/userManagement.h"

int jumlahUser = 0, userAktif = -1;
User users[MAX_USER];

// inisialisasi akun admin sebagai test case
void inisialisasiUser() {
    users[0].id = 1;
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin123");
    strcpy(users[0].nama, "Admin");
    strcpy(users[0].role, "admin");
    strcpy(users[0].alamat, "Jl. HR Subrantas NO.123");
    users[0].status = 1;

    jumlahUser = 1;
}

// fungsi buat registrasi akun user
void registrasiUser() {
    char username[30], nama[30], password[30], alamat[100];
    int cekUsername;

    // cek jumlah akun user yang terdaftar
    if (jumlahUser >= MAX_USER) {
        printf("Jumlah user melebihi kapasitas!");
    } else {
        printf("\n===== REGISTRASI USER =====\n");

        printf("Nama lengkap: ");
        scanf(" %29[^\n]", nama);

        printf("Username: ");
        scanf("%29s", username);

        printf("Alamat: ");
        scanf(" %99[^\n]", alamat);
    }

    // cek jika ada username yang sama
    for (int i = 0; i < jumlahUser; i++) {
        if (strcmp(users[i].username, username) == 0) {
            cekUsername = 1;
        }
    }

    if (cekUsername == 1) {
        printf("\nUsername telah digunakan!\n");
    } else {
        printf("Buat password: ");
        scanf("%29s", password);
        
        // panjang password tidak boleh kurang dari 8 char
        if (strlen(password) < 8) {
            printf("\nPassword minimal 8 karakter!\n");
        // jika panjang password sudah 8 karakter maka simpan semua inputan
        } else {
            users[jumlahUser].id = jumlahUser + 1;
            strcpy(users[jumlahUser].nama, nama);
            strcpy(users[jumlahUser].username, username);
            strcpy(users[jumlahUser].alamat, alamat);
            strcpy(users[jumlahUser].password, password);
            strcpy(users[jumlahUser].role, "customer");
            users[jumlahUser].status = 1;

            jumlahUser++;
            printf("\nRegistrasi berhasil!\n");
        }
    }
}

// fungsi buat login user
int loginUser() {
    char username[30], password[30];

    printf("Username : ");
    scanf("%29s", username);

    printf("Password : ");
    scanf("%29s", password);

    for (int i = 0; i < jumlahUser; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (strcmp(users[i].password, password) == 0) {
                if (users[i].status == 1) {
                    userAktif = i;
                    printf("\nLogin berhasil!");
                    printf("\nSelamat datang, %s!\n", users[i].nama);
                    return 1;
                } else {
                    printf("\nAkun tidak aktif!");
                    return 0;
                }
            } else {
                printf("\nPassword salah!");
                return 0;
            }
        }
    }
    printf("\nUsername tidak ditemukan!\n");
    return 0;
}

// fungsi untuk logout akun user
void logoutUser() {
    if (userAktif != -1) {
        printf("Logout berhasil. Sampai jumpa, %s!\n", users[userAktif].nama);
        userAktif = -1;
    }
}

// fungsi untuk menampilkan profil akun pengguna
void tampilkanProfil() {
    if (userAktif == -1) {
        printf("Silahkan login terlebih dahulu.\n");
    } else {
        printf("\n===== PROFIL PENGGUNA =====");

        printf("ID: %d\n", users[userAktif].id);
        printf("Nama: %s\n", users[userAktif].nama);
        printf("Usernam: %s\n", users[userAktif].username);
        printf("Alamat: %s\n", users[userAktif].alamat);
        printf("Role: %s\n", users[userAktif].role);
        printf("Status: %d\n", users[userAktif].status);
    }
}