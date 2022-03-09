//
// Created by king on 2022/3/1.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;

const int N = 110;

int n, m;
// g存储图，d存储每个点到起点的距离
int g[N][N], d[N][N];
// q为bfs过程中的队列存储当前需要访问的节点，pre存储过来的路径
PII q[N * N], pre[N][N];

int bfs() {
    // 初始化d
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    // 初始化队列，由于(0,0)必然放在队列中
    int hh, tt = 0;
    // 给予起点
    q[0] = {0, 0};
    // 上下左右的前进方式向量化表示
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (hh <= tt) {
        auto t = q[hh++];
        int x, y;
        for (int i = 0; i < 4; ++i) {
            x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < n && d[x][y] == -1 && !g[x][y]) {
                pre[x][y] = t;
                q[++tt] = {x, y};
                d[x][y] = d[t.first][t.second] + 1;
            }
        }
    }
    int x = n - 1, y = m - 1;
    while (x || y) {
        printf("(%d,%d) ", x, y);
        auto t = pre[x][y];
        x = t.first, y = t.second;
    }
    // 返回迷宫出口处的路径长度
    return d[n - 1][m - 1];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
    printf("%d", bfs());
    return 0;
}