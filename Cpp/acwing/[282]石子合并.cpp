//
// Created by king on 2023/10/9.
//
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 310;
int s[N], f[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    // 这里直接从2开始，因为在len=1的情况下，没有代价
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int l = i, r = i + len - 1;
            f[l][r] = 1e9;
            for (int j = l; j < r; ++j) {
                f[l][r] = min(f[l][r], f[l][j] + f[j + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    printf("%d", f[1][n]);
    return 0;
}