//
// Created by king on 2023/1/15.
//
#include <cstdio>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n;
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        printf("%d\n", gcd(a, b));
    }
    return 0;
}