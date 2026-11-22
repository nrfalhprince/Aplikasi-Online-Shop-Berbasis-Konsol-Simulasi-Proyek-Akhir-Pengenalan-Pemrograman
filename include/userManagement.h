#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#define MAX_USER 100

extern User users[MAX_USER];
extern int jumlahUser;
extern int userAktif;

typedef struct {
    int id;
    char username[30];
    char password[30];
    char nama[30];
    char role[30];
    float saldo;
    int status;
} User;

void inisialisasiUser();
void registrasiUser();
int loginUser();
void logoutUser();


#endif