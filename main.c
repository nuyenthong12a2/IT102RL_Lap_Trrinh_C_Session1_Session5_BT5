#include <stdio.h>

#define SO_LUONG_TOI_DA 10

int main(void)
{
    /* Mang chi phi 10 phan tu, ban dau co 4 ca kham */
    int phi_kham[SO_LUONG_TOI_DA] = {150000, 300000, 200000, 500000};
    int so_luong = 4;
    int vi_tri_sua, gia_tri_moi;
    int phi_kham_moi;
    int vi_tri_xoa;
    int tong_chi_phi;
    int i;

    printf("Nhap vi_tri_sua gia_tri_moi phi_kham_moi vi_tri_xoa: ");
    if (scanf("%d %d %d %d", &vi_tri_sua, &gia_tri_moi, &phi_kham_moi, &vi_tri_xoa) != 4) {
        printf("Loi: Du lieu nhap khong hop le!\n");
        return 1;
    }

    /* 1. Tong chi phi 2 ca kham dau tien */
    tong_chi_phi = phi_kham[0] + phi_kham[1];
    printf("Tong chi phi 2 ca dau: %d VND\n", tong_chi_phi);

    /* 2. Cap nhat chi phi tai vi_tri_sua (phai nam trong [0, so_luong - 1]) */
    if (vi_tri_sua < 0 || vi_tri_sua >= so_luong) {
        printf("Loi: Vi tri sua %d khong hop le!\n", vi_tri_sua);
    } else if (gia_tri_moi < 0) {
        printf("Loi: Chi phi moi %d khong hop le!\n", gia_tri_moi);
    } else {
        phi_kham[vi_tri_sua] = gia_tri_moi;
        printf("Sau khi sua vi tri %d: Chi phi moi = %d VND\n", vi_tri_sua, phi_kham[vi_tri_sua]);
    }

    /* 3. Them ca kham moi vao cuoi mang (phai con cho trong) */
    if (so_luong >= SO_LUONG_TOI_DA) {
        printf("Loi: Danh sach da day, khong the them ca kham moi!\n");
    } else if (phi_kham_moi < 0) {
        printf("Loi: Chi phi ca kham moi %d khong hop le!\n", phi_kham_moi);
    } else {
        phi_kham[so_luong] = phi_kham_moi;
        so_luong++;
        printf("Sau khi them ca moi: So luong = %d, Chi phi ca cuoi = %d VND\n",
               so_luong, phi_kham[so_luong - 1]);
    }

    /* 4. Xoa ca kham tai vi_tri_xoa: don cac phan tu sau sang trai 1 vi tri */
    if (vi_tri_xoa < 0 || vi_tri_xoa >= so_luong) {
        printf("Loi: Vi tri xoa %d khong hop le!\n", vi_tri_xoa);
        printf("So luong ca kham giu nguyen: %d\n", so_luong);
    } else {
        for (i = vi_tri_xoa; i < so_luong - 1; i++) {
            phi_kham[i] = phi_kham[i + 1];
        }
        so_luong--;
        if (vi_tri_xoa < so_luong) {
            printf("Sau khi xoa vi tri %d: So luong = %d, Chi phi vi tri %d moi = %d VND\n",
                   vi_tri_xoa, so_luong, vi_tri_xoa, phi_kham[vi_tri_xoa]);
        } else {
            printf("Sau khi xoa vi tri %d: So luong = %d (khong con phan tu tai vi tri nay)\n",
                   vi_tri_xoa, so_luong);
        }
    }

    return 0;
}