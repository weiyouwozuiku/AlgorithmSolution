//
// Created by king on 2022/4/12.
//
#include <cstring>
#include <queue>

using namespace std;
int n, m;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], dist[N], idx;
bool st[N];
typedef pair<int, int> PII;

int dijkstra(int index) {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 创建小根堆
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        // 跳过冗余节点
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
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