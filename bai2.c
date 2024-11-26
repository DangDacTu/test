#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct xemay {
    char hang[31];
    char ma[50];
    char loai[21];
    float dungtich;
    int nam;
    float gia;
};

typedef struct xemay XE;


void nhap_xe(XE *xe) {
    printf("Nhap hang san xuat: ");
    while (1) {
        fgets(xe->hang, 31, stdin);
        xe->hang[strcspn(xe->hang, "\n")] = '\0';
        if (strlen(xe->hang) <= 30) break;
        printf("Hang san xuat khong duoc qua 30 ky tu. Vui long nhap lai: ");
    }

    printf("Nhap loai xe: ");
    while (1) {
        fgets(xe->loai, 21, stdin);
        xe->loai[strcspn(xe->loai, "\n")] = '\0';
        if (strlen(xe->loai) <= 20) break;
        printf("Loai xe khong duoc qua 20 ky tu. Vui long nhap lai: ");
    }

    printf("Nhap dung tich xi-lanh: ");
    while (scanf("%f", &xe->dungtich) != 1 || xe->dungtich <= 0) {
        printf("Dung tich xi-lanh phai la so thuc duong. Vui long nhap lai: ");
        while (getchar() != '\n');
    }

    printf("Nhap nam san xuat: ");
    while (scanf("%d", &xe->nam) != 1 || xe->nam <= 0) {
        printf("Nam san xuat phai la so nguyen duong. Vui long nhap lai: ");
        while (getchar() != '\n');
    }

    printf("Nhap gia ban (trieu VND): ");
    while (scanf("%f", &xe->gia) != 1 || xe->gia <= 0) {
        printf("Gia ban phai la so thuc duong. Vui long nhap lai: ");
        while (getchar() != '\n');
    }
    getchar();
}


void khoi_tao_ma(XE *xe) {
    snprintf(xe->ma, sizeof(xe->ma), "%s.%s.%.0f", xe->hang, xe->loai, xe->dungtich);
}


void sap_xep_gia_tang_dan(XE *ds, int sluong) {
    for (int i = 0; i < sluong - 1; i++) {
        for (int j = i + 1; j < sluong; j++) {
            if (ds[i].gia > ds[j].gia) {
                XE temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}


void in_xe(XE xe, int stt) {
    printf("%d - %s - %d - %.2f\n", stt, xe.ma, xe.nam, xe.gia);
}

void in_danh_sach_xe(XE *ds, int sluong) {
    printf("Stt - Ma - Nam san xuat - Gia\n");
    for (int i = 0; i < sluong; i++) {
        in_xe(ds[i], i + 1);
    }
}


int main() {
    int sluong = 0;
    XE ds[100];
    char chon;

    do {
        printf("Nhap thong tin xe may thu %d:\n", sluong + 1);
        nhap_xe(&ds[sluong]);
        khoi_tao_ma(&ds[sluong]);
        sluong++;
        printf("Nhap tiep thong tin xe may (y/n): ");
        scanf("%c", &chon);
        getchar();
    } while (chon == 'y');

    sap_xep_gia_tang_dan(ds, sluong);
    in_danh_sach_xe(ds, sluong);

    return 0;
}
