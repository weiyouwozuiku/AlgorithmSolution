//
// Created by king on 2022/4/12.
//
#include <iostream>
#include <cstring>

using namespace std;
int n, m;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], dist[N], idx;
bool st[N];

int dijkstra(int index){


}

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int main() {
    scanf("%d%d", &n, &m);
    // 尚未初始化时，节点都没有链接节点
    memset(h, -1, sizeof h);
    int a, b, c;
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d", dijkstra(1));
    return 0;
}