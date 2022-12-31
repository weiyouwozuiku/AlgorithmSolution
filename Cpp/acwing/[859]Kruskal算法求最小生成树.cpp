//
// Created by king on 2022/12/31.
//
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200010;
int n, m;
int p[N]; // 并查集的父节点数组

struct Edge {
    int a, b, w;

    const bool operator<(const Edge &edge) const {
        return w < edge.w;
    }
} edges[N];

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
}

int kruskal() {
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) p[i] = i;
    std::sort(edges, edges + m);
    int a, b, w;
    for (int i = 0; i < m; ++i) {
        a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            res += w;
            cnt++;
            p[a] = b;
        }
    }
    if (cnt < n - 1) return 0x3f3f3f3f;
    else return res;
}

int main() {
    int a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    int r = kruskal();
    if (r == 0x3f3f3f3f) puts("impossible");
    else printf("%d", r);
    return 0;
}