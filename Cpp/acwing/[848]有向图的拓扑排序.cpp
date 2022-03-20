//
// Created by king on 2022/3/20.
//

#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e6 + 10;
// 这里就是常见的邻接表表示方式，d表示入度
int e[N], ne[N], h[N], d[N], q[N], idx, n, m;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a];
    h[a] = idx++;
    d[b]++;
}

bool topsort() {
    int hh = 0, tt = -1;
    // 首先找出入度为0的点
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) q[++tt] = i;
    }
    if (tt == -1) return false;
    while (hh <= tt) {
        // 找到其连通节点，去掉之前的入度检查是否为入度0节点
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j] -= 1;
            if (!d[j]) q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    if (topsort()) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", q[i]);
        }
    } else printf("-1");
    return 0;
}