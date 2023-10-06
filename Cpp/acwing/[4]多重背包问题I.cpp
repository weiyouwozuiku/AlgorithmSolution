//
// Created by king on 2023/10/5.
//
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 110;
int v[N], w[N], s[N], ff[N][N];

void twoDimension(int n, int m) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; ++k) {
                ff[i][j] = max(ff[i][j], ff[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }
    printf("%d", ff[n][m]);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)scanf("%d%d%d", &v[i], &w[i], &s[i]);
    twoDimension(n, m);
    return 0;
}