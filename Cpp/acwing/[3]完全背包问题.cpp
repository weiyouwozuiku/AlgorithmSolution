//
// Created by king on 2023/10/5.
//
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1010;
int v[N], w[N], f[N], ff[N][N];

void twoDimension(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k * v[i] <= j; ++k) {
                ff[i][j] = max(ff[i][j], ff[i - 1][j - k * v[i]] + w[i] * k);
            }
        }
    }
    printf("%d", ff[n][m]);
}

void oneDimension(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = v[i]; j <= m; ++j) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    printf("%d", f[m]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)scanf("%d%d", &v[i], &w[i]);
    oneDimension(n, m);
    return 0;
}