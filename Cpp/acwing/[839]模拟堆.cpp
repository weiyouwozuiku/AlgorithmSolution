//
// Created by king on 2022/2/14.
//

#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
// h: 堆数据
// ph[i]: 第k数的堆索引
// hp[i]: 索引i是第hp[i]个插入的数
// len: 堆索引
int h[N], ph[N], hp[N], len;

// 这里的ab都是堆中的索引
void heapSwap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int idx) {
    int t = idx;
    while (t && 2 * t <= len) {
        idx = t;
        if (2 * idx <= len && h[idx * 2] < h[t]) t = 2 * idx;
        if (2 * idx + 1 <= len && h[idx * 2 + 1] < h[t]) t = 2 * idx + 1;
        if (t != idx) heapSwap(idx, t);
        else break;
    }
}

void up(int idx) {
    while (idx >> 1 && h[idx >> 1] > h[idx]) {
        heapSwap(idx, idx / 2);
        idx /= 2;
    }
}

int main() {
    // n: 操作数量
    // x: 操作数
    // m: 第m个数
    int n, x, y, m = 0;
    scanf("%d", &n);
    char op[3];
    while (n--) {
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            scanf("%d", &x);
            ph[++m] = ++len;
            hp[len] = m;
            h[len] = x;
            up(len);
        } else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM")) {
            heapSwap(1, len--);
            down(1);
        } else if (!strcmp(op, "D")) {
            scanf("%d", &x);
            int k = ph[x];
            // 所有heapSwap操作前保存操作变量，因为发生heapSwap之后，索引会变化
            heapSwap(k, len--);
            down(k);
            up(k);
        } else if (!strcmp(op, "C")) {
            scanf("%d%d", &x, &y);
            h[ph[x]] = y;
            down(ph[x]);
            up(ph[x]);
        }
    }
    return 0;
}
