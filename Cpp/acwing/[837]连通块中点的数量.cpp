//
// Created by king on 2022/2/12.
//

#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int s[N], sizeTable[N];

int find(int idx) {
    if (s[idx] != idx) s[idx] = find(s[idx]);
    return s[idx];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        s[i] = i;
        sizeTable[i] = 1;
    }
    char op[3];
    int a, b;
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d", &a, &b);
            // 注意这里可能会同一个数内节点合并，这会导致sizeTable被多加节点，需要特判这种情况
            if (find(a) != find(b)) {
                // 需要注意这里加树和加元素相反
                sizeTable[find(b)] += sizeTable[find(a)];
                s[find(a)] = find(b);
            }
        } else {
            if (op[1] == '1') {
                scanf("%d%d", &a, &b);
                if (find(a) == find(b)) printf("Yes\n");
                else printf("No\n");
            } else {
                scanf("%d", &a);
                printf("%d\n", sizeTable[find(a)]);
            }
        }
    }
    return 0;
}