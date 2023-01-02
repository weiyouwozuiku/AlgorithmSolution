//
// Created by king on 2023/1/1.
//
#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 100010, M = 200010;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int index, int c) {
    color[index] = c;
    for (int i = h[index]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!~color[j]) {
            if (!dfs(j, !c)) return false;
        } else {
            if (color[j] == c) return false;
        }
    }
    return true;
}

bool check() {
    memset(color, -1, sizeof color);
    for (int i = 1; i <= n; ++i) {
        if (!~color[i]) {
            if (!dfs(i, 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        if (a != b) {
            add(a, b), add(b, a);
        }
    }
    if (check()) puts("Yes");
    else puts("No");
    return 0;
}