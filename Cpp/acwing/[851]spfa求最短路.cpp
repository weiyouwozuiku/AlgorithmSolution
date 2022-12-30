//
// Created by king on 2022/12/23.
//
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;
int n, m;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], dist[N], idx;
bool st[N];

int spfa(int index) {
    memset(dist, 0x3f, sizeof dist);
    dist[index] = 0;
    queue<int> q;
    st[index] = true;
    q.push(index);
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            auto it = e[i];
            if (dist[it] > dist[t] + w[i]) {
                dist[it] = dist[t] + w[i];
                if (!st[it]) {
                    st[it] = true;
                    q.push(it);
                }
            }
        }
    }
    return dist[n];
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
    int result = spfa(1);
    if (result > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d", result);
    return 0;
}