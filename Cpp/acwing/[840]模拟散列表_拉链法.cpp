//
// Created by king on 2022/2/16.
//
#include<iostream>
#include<cstring>

using namespace std; 
const int N = 1e5 + 3;
int h[N], e[N], ne[N], idx;

void insert(int value) {
    // 保证获取的余数是整数，如果直接计算或者直接+N计算都会导致余数为负数
    int k = (value % N + N) % N;
    e[idx] = value;
    // 这里会将保存原本位置元素的索引，最后必然是-1，保证了能结束循环
    // 因此整个链表只能采用头插法，而不能尾插，那样会更麻烦
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int value) {
    int k = (value % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == value) return true;
    }
    return false;
}

int main() {
    memset(h, -1, sizeof h);
    memset(ne,-1,sizeof ne);
    int n, x;
    scanf("%d", &n);
    char op[2];
    while (n--) {
        scanf("%s%d", op, &x);
        if (op[0] == 'I') {
            insert(x);
        } else {
            if (find(x)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

