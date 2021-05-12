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
        //检查队头是否出队列
        if (hh <= tt && i - k + 1 > s[hh]) ++hh;
        //检查单调队列队尾元素是否大于等于新入队元素
        while (hh <= tt && q[s[tt]] >= q[i]) --tt;
        //新元素入队
        s[++tt] = i;
        if (i >= k - 1) printf("%d ", q[s[hh]]);
    }
    printf("\n");
    //重新初始化
    hh = 0, tt = -1;
    for (int i = 0; i < n; ++i) {
        //检查队头是否出队列
        if (hh <= tt && i - k + 1 > s[hh]) ++hh;
        //检查单调队列队尾元素是否小于等于新入队元素
        while (hh <= tt && q[s[tt]] <= q[i]) --tt;
        //新元素入队
        s[++tt] = i;
        if (i >= k - 1) printf("%d ", q[s[hh]]);
    }
    return 0;
}