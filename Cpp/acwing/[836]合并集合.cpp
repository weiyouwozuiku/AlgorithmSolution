//
// Created by king on 2022/2/12.
//

#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int s[N];

// 返回idx的根节点+路径压缩
int find(int idx) {
    if (idx != s[idx]) s[idx] = find(s[idx]);
    return s[idx];
}

int main() {
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    char op[2];
    for (int i = 1; i <= n; i++) s[i] = i;
    while (m--) {
        scanf("%s%d%d", &op, &a, &b);
        if (op[0] == 'M') s[find(a)] = find(b);
        else {
            if (find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
