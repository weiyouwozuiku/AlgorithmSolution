//
// Created by king on 2022/12/29.
//
#include <cstring>
#include <algorithm>
#include <cstdio>

const int N = 510;
int g[N][N], dist[N];
int n, m;
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    // 记录最小生成树的路径之和
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            // 需要注意这里st比较的是j不是t
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        // i=0时 dist刚初始化所有边都是INF
        if (i && dist[t] == 0x3f3f3f3f) return 0x3f3f3f3f;
        if (i) res += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; ++j)dist[j] = std::min(dist[j], g[t][j]);
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    int a, b, w;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = g[b][a] = std::min(g[a][b], w);
    }
    int r = prim();
    if (r == 0x3f3f3f3f) puts("impossible");
    else printf("%d", r);
}