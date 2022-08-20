//
// Created by king on 2022/8/20.
//
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    for (int i = 0, j = m - 1; i < n; ++i) {
        while (j >= 0 && a[i] + b[j] > k) j -= 1;
        if (a[i] + b[j] == k) {
            printf("%d %d", i, j);
            break;
        }
    }
    return 0;
}