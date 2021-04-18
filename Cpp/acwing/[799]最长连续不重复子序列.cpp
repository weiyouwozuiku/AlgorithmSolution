//
// Created by king on 2021/4/18.
//

#include <iostream>

using namespace std;
const int N = 1e6 + 10;
//数组q记录题目信息，数组s记录下标数字出现的次数
int q[N], s[N];

int main() {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    //j在前，i在后
    //当s[q[i]]>1时说明有重复数字，此时，j向后移动至q[i]第一次出现的位置的后一个，此过程中将所有j经过的数字对应的s[q[j]]--
    for (int i = 0, j = 0; i < n; ++i) {
        ++s[q[i]];
        while (s[q[i]] > 1) --s[q[j++]];
        res = i - j + 1 > res ? i - j + 1 : res;
    }
    printf("%d", res);
    return 0;
}