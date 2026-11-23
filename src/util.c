// scanf("%d") akan looping tanpa henti jika user mengetik huruf.
#include <stdio.h>
#include <stdlib.h>
#include "../include/util.h"

// membaca satu baris tidak kosong, lalu mengubahnya menjadi long
static int bacaBaris(char *buf, int ukuran) {
    while (1) {
        char *p;
        if (fgets(buf, ukuran, stdin) == NULL) {
            exit(0);
        }
        p = buf;
        while (*p == ' ' || *p == '\t') p++;
        if (*p == '\n' || *p == '\r' || *p == '\0') continue;
        return (int)(p - buf);
    }
}

int bacaInt(void) {
    char buf[64], *akhir;
    int awal = bacaBaris(buf, sizeof(buf));
    long nilai = strtol(buf + awal, &akhir, 10);

    if (akhir == buf + awal) return -1;
    while (*akhir == ' ' || *akhir == '\t') akhir++;
    if (*akhir != '\n' && *akhir != '\r' && *akhir != '\0') return -1;
    return (int)nilai;
}

float bacaFloat(void) {
    char buf[64], *akhir;
    int awal = bacaBaris(buf, sizeof(buf));
    float nilai = strtof(buf + awal, &akhir);

    if (akhir == buf + awal) return -1;
    while (*akhir == ' ' || *akhir == '\t') akhir++;
    if (*akhir != '\n' && *akhir != '\r' && *akhir != '\0') return -1;
    return nilai;
}
