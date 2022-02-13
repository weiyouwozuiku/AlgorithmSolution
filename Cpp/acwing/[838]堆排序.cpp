//
// Created by king on 2022/2/13.
//

#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int s[N], len;

void down(int idx) {
    int min = idx;
    if (2 * idx <= len && s[2 * idx] < s[min]) min = 2 * idx;
    if (2 * idx + 1 <= len && s[2 * idx + 1] < s[min]) min = 2 * idx + 1;
    if (idx != min) {
        swap(s[idx], s[min]);
        down(min);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    len = n;
    // 建堆
    for (int i = n >> 1; i; i--) down(i);
    while (m--) {
        printf("%d ", s[1]);
        s[1] = s[len--];
        down(1);
    }
    return 0;
}