//
// Created by king on 2022/4/11.
//

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510;
int n, m;
int g[N][N], dist[N];
bool st[N];

int dijkstra(int index) {
    memset(dist, 0x3f, sizeof dist);
    // 起点不能直接放在已遍过的集合中，因为需要起点更新dist，直接跳过起点，将无法更新之后的dist
    dist[index] = 0;
    for (int i = 1; i <= n; ++i) {
        // t为当前在集合中最近的点
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))t = j;
        st[t] = true;
        for (int j = 1; j <= n; ++j) dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main() {
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    int a, b, c;
    while (m--) {
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    printf("%d", dijkstra(1));
    return 0;
}