#include <stdio.h>

int main() {
    int a[2], b[2] = {0};
    scanf("%d %d", &a[0], &a[1]);
    scanf("%d %d", &b[0], &b[1]);

    int a2[2], b2[2], c[2] = {0};

    a2[0] = a[0] * b[1];
    a2[1] = a[1] * b[1];
    b2[0] = b[0] * a[1];
    b2[1] = b[1] * a[1];

    c[0] = a2[0] + b2[0];
    c[1] = a2[1];

    int num1 = c[0], num2 = c[1];

    while (num1 != num2) {
        if (num1 > num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
    }

    if (num1 == 1) {
        printf("%d %d", c[0], c[1]);
    } else {
        c[0] /= num1;
        c[1] /= num1;
        printf("%d %d", c[0], c[1]);
    }

    return 0;
}
