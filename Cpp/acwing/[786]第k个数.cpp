//
// Created by king on 2021/9/7.
//
/**
 * 本题的解题思路：
 * 直接使用快排的时间复杂度是O(nlogn)
 * 这题可以结合二分与快排的思想，将时间复杂度优化到O(n)
 * 重点在于进行一次快排后，如果第k个数在快排的小于x的部分时，相应的缩小快排空间。同理，另一个区间也是一样
 */
#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int q[N];

int quick_select(int l, int r, int k) {
    //如果当前区间只有一个元素，则其必然是答案
    if (l == r) return q[l];
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j) {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    int sl = j - l + 1;
    if (k <= sl) return quick_select(l, j, k);
    return quick_select(j + 1, r, k - sl);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    printf("%d\n", quick_select(0, n - 1, k));
    return 0;
}