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
        int t = -1; // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; ++j)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))t = j;
        if (t == n) break;
        st[t] = true;
        // 用t更新其他点的距离
        for (int j = 1; j <= n; ++j) dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    // 如果之后是0x3f3f3f3f则表明不是该点无法到达
    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
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