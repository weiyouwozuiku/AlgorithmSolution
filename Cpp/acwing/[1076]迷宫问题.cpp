//
// Created by king on 2022/11/29.
//
#include <iostream>
#include <cstring>

using namespace std;
const int N = 1010, M = N * N;
int n;
typedef pair<int, int> PII;
// 注意这的大小  q数组会保存最多所有点的移动信息，需要开辟较大空间
PII q[M], pre[N][N];
int d[N][N], g[N][N];

void bfs() {
    int hh = 0, tt = 0;
    memset(d, -1, sizeof(d));
    d[n - 1][n - 1] = 0;
    q[0] = {n - 1, n - 1};
    const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
    while (hh <= tt) {
        auto t = q[hh++];
        for (int i = 0; i < 4; ++i) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < n && d[x][y] == -1 && g[x][y] == 0) {
                pre[x][y] = t;
                q[++tt] = {x, y};
                d[x][y] = d[t.first][t.second] + 1;
            }
        }
    }
    int x = 0, y = 0;
    while (true) {
        printf("%d %d\n", x, y);
        auto it = pre[x][y];
        if (x == n - 1 && y == n - 1) break;
        x = it.first, y = it.second;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
    bfs();
    return 0;
}
