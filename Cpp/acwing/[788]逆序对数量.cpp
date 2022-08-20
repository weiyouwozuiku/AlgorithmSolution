//
// Created by king on 2022/8/20.
//
#include <iostream>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int q[N], tmp[N];

int mergeSort(int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) >> 1, i = l, j = mid, k = 0;
    ll res = mergeSort(l, mid) + mergeSort(mid + 1, r);
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; ++i, ++j) q[i] = tmp[j];
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    printf("%d", mergeSort(0, n - 1));
    return 0;
}