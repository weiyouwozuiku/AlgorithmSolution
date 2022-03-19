//
// Created by king on 2022/3/10.
//

#include <iostream>
#include <cstring>

using namespace std;
int n;
const int N = 100010, M = N * 2;
// h记录了图里面所有节点的尾指针
// idx表示e和ne中当前使用
int h[N], e[M], ne[M], idx;
// st记录每条边的情况
bool st[N];
int ans = N;

//链表头插法
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 以u为根的子树大小
int dfs(int u) {
    // 表示这条边已经被搜索过了
    st[u] = true;
    // sum：当前这个节点及其子树中所有节点的数量
    // res：当前这个节点之外所有子节点的数量
    int sum = 1, res = 0;
    // 遍历这个节点的所有连通节点
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = max(s, res);
            sum += s;
        }
    }
    res = max(n - sum, res);
    ans = min(ans, res);
    return sum;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}