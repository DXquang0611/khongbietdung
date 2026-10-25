#include <stdio.h>
int nhapDaThuc(int a[], int n)
{
    int i;

    for (i = n - 1; i >= 0; i--) {
        if (scanf("%d", &a[i]) != 1)
            return 0;

        if (a[i] != 0 && a[i] != 1)
            return 0;
    }

    return 1;
}

void inDaThuc(int a[], int bac)
{
    int i, daIn = 0;

    for (i = bac; i >= 0; i--) {
        if (a[i] == 1) {
            if (daIn == 1)
                printf(" + ");

            if (i == 0)
                printf("1");
            else if (i == 1)
                printf("x");
            else
                printf("x^%d", i);

            daIn = 1;
        }
    }

    if (daIn == 0)
        printf("0");
}

int main(void)
{
    int n, i, j;
    int a[8] = {0}, b[8] = {0};
    int p[9] = {0}, c[15] = {0};

    printf("Chon truong GF(2^n), nhap n = 4 hoac 8: ");

    if (scanf("%d", &n) != 1 || (n != 4 && n != 8)) {
        printf("Lua chon khong hop le.\n");
        return 1;
    }

    if (n == 4) {
        p[4] = p[1] = p[0] = 1;
    } else {
        p[8] = p[4] = p[3] = p[1] = p[0] = 1;
    }

    printf("Nhap %d he so A, tu x^%d den x^0 (chi 0 hoac 1):\n",
           n, n - 1);

    if (nhapDaThuc(a, n) == 0) {
        printf("He so khong hop le.\n");
        return 1;
    }

    printf("Nhap %d he so B, tu x^%d den x^0 (chi 0 hoac 1):\n",
           n, n - 1);

    if (nhapDaThuc(b, n) == 0) {
        printf("He so khong hop le.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            c[i + j] = (c[i + j] + a[i] * b[j]) % 2;

    printf("\nA(x) = ");
    inDaThuc(a, n - 1);

    printf("\nB(x) = ");
    inDaThuc(b, n - 1);

    printf("\np(x) = ");
    inDaThuc(p, n);

    printf("\nTich truoc khi lay du = ");
    inDaThuc(c, 2 * n - 2);
    for (i = 2 * n - 2; i >= n; i--) {
        if (c[i] == 1) {
            for (j = 0; j <= n; j++)
                c[i - n + j] = (c[i - n + j] + p[j]) % 2;
        }
    }

    printf("\nKet qua trong GF(2^%d) = ", n);
    inDaThuc(c, n - 1);
    printf("\n");

    return 0;
}