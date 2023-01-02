//
// Created by king on 2023/1/2.
//
#include <cstdio>
#include <cstring>

const int N = 2e4 + 10, M = 2e5 + 10;
int n, m;
int e[M], ne[M], idx, h[N], w[M];
int color[N];

void add(int x, int y, int c) {
    e[idx] = y;
    w[idx] = c;
    ne[idx] = h[x];
    h[x] = idx++;
}

bool dfs(int index, int c, int mid) {
    color[index] = c;
    for (int i = h[index]; ~i; i = ne[i]) {
        int j = e[i];
        if (w[i] <= mid) continue;
        if (color[j] == -1) {
            if (!dfs(j, !c, mid)) return false;
        } else if (color[j] == c) return false;
    }
    return true;
}

bool check(int mid) {
    memset(color, -1, sizeof color);
    for (int i = 1; i <= n; ++i) {
        if (!~color[i]) {
            if (!dfs(i, 0, mid)) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h,-1,sizeof h);
    int x, y, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w), add(y, x, w);
    }
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid))r = mid;
        else l = mid + 1;
    }
    printf("%d", l);
    return 0;
}