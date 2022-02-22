//
// Created by king on 2022/2/23.
//

#include <iostream>

using namespace std;
int n;
const int N = 10;
int path[N];
bool log[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) printf("%d ", path[i]);
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (!log[i]) {
                log[i] = true;
                path[u] = i;
                dfs(u + 1);
                log[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}