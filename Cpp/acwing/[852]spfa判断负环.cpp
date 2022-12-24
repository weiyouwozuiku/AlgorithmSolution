//
// Created by king on 2022/12/23.
//
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int n, m;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
bool st[N];
// dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
int cnt[N], dist[N];

void add(int a, int b, int x) {
    e[idx] = b;
    w[idx] = x;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa() {
    queue<int> q;
    // 避免出现起点通路上没有负环，因此直接加入所有点
    for (int i = 1; i <= n; ++i) {
        q.push(i);
        st[i] = true;
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > n) return true;
                if (!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    int a, b, x;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &x);
        add(a, b, x);
    }
    if (spfa()) puts("Yes");
    else puts("No");
}