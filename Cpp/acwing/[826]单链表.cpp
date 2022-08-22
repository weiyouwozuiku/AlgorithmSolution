//
// Created by king on 2021/4/23.
//

#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int e[N], ne[N];
// 这里其实完成了初始化的操作
int idx = 0, head = -1;

void insertFromHead(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insert(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void pop(int k) {
    ne[k] = ne[ne[k]];
}

int main() {
    int m;
    char method;
    scanf("%d", &m);
    while (m--) {
        getchar();
        scanf("%c", &method);
        if (method == 'H') {
            int x;
            scanf("%d", &x);
            insertFromHead(x);
        }
        if (method == 'D') {
            int k;
            scanf("%d", &k);
            if (!k) head = ne[head];
            else pop(k - 1);
        }
        if (method == 'I') {
            int k, x;
            scanf("%d%d", &k, &x);
            insert(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
    return 0;
}