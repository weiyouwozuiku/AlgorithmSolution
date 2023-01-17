//
// Created by king on 2023/1/7.
//
#include <cstdio>

void divide(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            int b = 0;
            while (x % i == 0) {
                x /= i;
                b += 1;
            }
            printf("%d %d\n", i, b);
        }
    }
    if (x > 1) printf("%d 1\n", x);
    puts("");
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        divide(x);
    }
    return 0;
}