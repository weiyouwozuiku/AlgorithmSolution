//
// Created by king on 2022/3/20.
//

#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int n, m;
int e[N], ne[N], h[N], idx;
// d表示距离，q表示队列
int d[N], q[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs() {
    memset(d, -1, sizeof d);
    d[1] = 0;
    int hh = 0, tt = 0;
    q[0] = 1;
    while (hh <= tt) {
        // t 当前队列中的x
        int t = q[hh++];
        // i 当前x的连通节点的idx
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] == -1) {
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }
    return d[n];
}

int main() {
    memset(h, -1, sizeof h);
    idx = 0;
    scanf("%d%d", &n, &m);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    printf("%d", bfs());
    return 0;
}