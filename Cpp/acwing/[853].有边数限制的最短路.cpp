//
// Created by king on 2022/12/19.
//

#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 510, M = 10010;
int n, m, k;
int dist[N], backup[N];
struct Edge {
    int a, b, w;
} edges[M];

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 这里的k限制了最多能走的边数
    for (int i = 0; i < k; ++i) {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; ++j) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = std::min(dist[b], backup[a] + w);
        }
    }
    return dist[n];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int a, b, x;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edges[i].a, &edges[i].b, &edges[i].w);
    }
    int t = bellman_ford();
    if (t > 0x3f3f3f3f / 2)puts("impossible");
    else printf("%d\n", t);
    return 0;
}


