//
// Created by king on 2022/12/10.
//

#include <iostream>
#include <cstring>

int n, m;
const int N = 100010;
// p存放记录的拓扑排序
// h记录每个节点连接的点
// d存放每个节点的入度
int p[N], h[N], d[N];
int e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    d[b] += 1;
}

void topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) p[++tt] = i;
    }
    while (hh <= tt) {
        auto it = p[hh++];
        for (int i = h[it]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (!d[j]) p[++tt] = j;
        }
    }
}

int main() {
    memset(h, -1, sizeof h);
    memset(d, 0, sizeof d);
    scanf("%d", &n);
    int x;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        add(i, x);
        while (x != 0) {
            scanf("%d", &x);
            add(i, x);
        }
    }
    topsort();
    for (int i = 0; i < n; ++i) {
        printf("%d ", p[i]);
    }
    return 0;
}