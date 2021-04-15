//
// Created by king on 2021/4/15.
//

#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int q[N];
int s[N];

int main() {
    int n, m;
    s[0] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &q[i]);
        s[i] = s[i - 1] + q[i];
    }
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}