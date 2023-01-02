//
// Created by king on 2023/1/1.
//
#include <cstdio>
#include <cstring>

int n1, n2, m;
const int N = 510, M = 5e5 + 10;
bool st[N];
int e[M], ne[M], idx, h[N];
int pair[N];

bool find(int index) {
    for (int i = h[index]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            // 当前没有匹配或者可以更换别的匹配
            if (pair[j] == -1 || find(pair[j])) {
                pair[j] = index;
                return true;
            }
        }
    }
    return false;
}

void match() {
    int res = 0;
    for (int i = 1; i <= n1; ++i) {
        // 需要每次清空之前的占位
        memset(st, false, sizeof st);
        if (find(i)) res += 1;
    }
    printf("%d", res);
}

void add(int x, int y) {
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);
    int x, y;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    memset(pair, -1, sizeof pair);
    match();
    return 0;
}