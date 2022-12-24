//
// Created by king on 2022/12/24.
//
#include <cstdio>
#include <algorithm>

const int N = 210, INF = 1e9;
int n, m, k;
int dist[N][N];

void floyd() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int a, b, w;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &w);
        dist[a][b] = std::min(w, dist[a][b]);
    }
    floyd();
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &a, &b);
        if (dist[a][b] > INF >> 1) puts("impossible\n");
        else printf("%d\n", dist[a][b]);
    }
    return 0;
}