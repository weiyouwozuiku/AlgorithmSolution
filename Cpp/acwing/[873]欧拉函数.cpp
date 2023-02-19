//
// Created by king on 2023/1/15.
//
#include <cstdio>

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        int res = x;
        for (int j = 2; j <= x / j; ++j) {
            if (x % j == 0) {
                res = res / j * (j - 1);
                while (x % j == 0) x /= j;
            }
        }
        if (x > 1) res = res / x * (x - 1);
        printf("%d\n", res);
    }
    return 0;
}