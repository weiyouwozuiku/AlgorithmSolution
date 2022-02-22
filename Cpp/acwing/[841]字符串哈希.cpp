//
// Created by king on 2022/2/19.
//

#include <iostream>

using namespace std;
const int N = 1e5 + 3, P = 131;
// unsigned long long 天然维护了一个64位的2进制数组
typedef unsigned long long ULL;
// p数组表示的是p进制每一位对应的数
// h数组表示对应子串的ASCII码在p进制下对应的数值
// op存放字符串
ULL h[N], p[N];
char op[N];

ULL find(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, m;
    // 这里存op+1的位置存放字符串
    scanf("%d%d%s", &n, &m, op + 1);
    // 表示p进制的0次方
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + op[i];
    }
    int a, b, c, d;
    while (m--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (find(a, b) == find(c, d)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}