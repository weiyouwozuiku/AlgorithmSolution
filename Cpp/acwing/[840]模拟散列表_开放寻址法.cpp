//
// Created by king on 2022/2/19.
//
#include<iostream>
#include<cstring>

using namespace std;
const int N = 2e5 + 3;
const int Max = 0x3f3f3f3f;
// h是存放数据对应的key
int h[N];

// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find(int value) {
    // 保证获取的余数是整数，如果直接计算或者直接+N计算都会导致余数为负数
    int k = (value % N + N) % N;
    while (h[k] != Max && h[k] != value) {
        ++k;
        if (k == N) k = 0;
    }
    return k;
}

int main() {
    memset(h, 0x3f, sizeof h);
    int n, x;
    scanf("%d", &n);
    char op[2];
    while (n--) {
        scanf("%s%d", op, &x);
        if (op[0] == 'I') {
            h[find(x)] = x;
        } else {
            if (h[find(x)] != Max) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

