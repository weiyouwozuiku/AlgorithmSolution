//
// Created by king on 2023/10/7.
//
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 501;
int a[N][N], f[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    // 初始化路径数组
    for (int i = 1; i <= n; ++i)
        // 特别注意这里需要放宽循环，以便f(0,x)和f(i,j)在边界情况下没有初始化
        for (int j = 0; j <= i + 1; ++j)
            f[i][j] = -1e9;
    f[1][1] = a[1][1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        f[n][0] = max(f[n][0], f[n][i]);
    printf("%d", f[n][0]);
    return 0;
}