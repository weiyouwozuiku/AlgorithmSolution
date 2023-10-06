//
// Created by king on 2023/7/6.
//
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1001;
int v[N], w[N];
int f[N][N];
int ff[N];

void twoDimension(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    printf("%d", f[n][m]);
}

void oneDimension(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= v[i]; --j) {
            ff[j] = max(ff[j], ff[j - v[i]] + w[i]);
        }
    }
    printf("%d", ff[m]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &v[i], &w[i]);
    oneDimension(n, m);
    return 0;
}