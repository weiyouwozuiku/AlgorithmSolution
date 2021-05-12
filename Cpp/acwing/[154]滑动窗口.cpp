//
// Created by king on 2021/5/10.
//

#include <iostream>

using namespace std;
const int N = 1e6 + 10;
//q数组负责记录提供的数据，s数组负责记录q数组对应元素的索引
int q[N], s[N];
//hh表示单调队列的头部，tt表示单调队列的尾部
int hh = 0, tt = -1;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && i - k + 1 > s[hh]) ++hh;
        while (hh <= tt && q[s[tt]] >= q[i]) --tt;
        s[++tt] = i;
        if (i >= k - 1) printf("%d ", q[s[hh]]);
    }
    printf("\n");
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        if (hh <= tt && i - k + 1 > s[hh]) ++hh;
        while (hh <= tt && q[s[tt]] <= q[i]) --tt;
        s[++tt] = i;
        if (i >= k - 1) printf("%d ", q[s[hh]]);
    }
    return 0;
}