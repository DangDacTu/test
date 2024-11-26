#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void so_sanh_xau(char *xau1, char *xau2) {
    int len1 = strlen(xau1);
    int len2 = strlen(xau2);
    int max_len = len1 > len2 ? len1 : len2;
    int count = 0;

    printf("Xau 1: %s\n", xau1);
    printf("Xau 2: %s\n", xau2);

    for (int i = 0; i < max_len; i++) {
        if (xau1[i] != xau2[i]) {
            count++;
            if (i < len1) xau1[i] = '#';
            if (i < len2) xau2[i] = '#';
        }
    }

    printf("So ky tu khac nhau: %d\n", count);
    printf("Xau 1 sau khi thay doi: %s\n", xau1);
    printf("Xau 2 sau khi thay doi: %s\n", xau2);
}


void xu_ly_xau(char *xau, int n) {
    int len = strlen(xau);

    if (len > n) {
        for (int i = n; i < len; i++) {
            xau[i] = xau[i + 1];
        }
        xau[len - 1] = '\0';
    } else {
        for (int i = len; i < n; i++) {
            xau[i] = xau[i - len];
        }
        xau[n] = '\0';
    }

    printf("Xau sau khi xu ly: %s\n", xau);
}

int main() {
    char xau1[100], xau2[100], xau3[100];
    int n;

    printf("Nhap xau 1: ");
    fgets(xau1, 100, stdin);
    xau1[strcspn(xau1, "\n")] = '\0';
    printf("Nhap xau 2: ");
    fgets(xau2, 100, stdin);
    xau2[strcspn(xau2, "\n")] = '\0';
    so_sanh_xau(xau1, xau2);

    printf("Nhap xau 3: ");
    fgets(xau3, 100, stdin);
    xau3[strcspn(xau3, "\n")] = '\0';
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    xu_ly_xau(xau3, n);

    return 0;
}
