#ifndef USER_MANAGEMENT.H
#define USER_MANAGEMENT.H

#define MAX_USER 100

typedef struct {
    int id;
    char username[30];
    char password[30];
    char nama[30];
    char role[30];
    float saldo;
    int status;
} User;

int loginUser();

#endif