//
// Created by king on 2021/4/18.
//

#include <iostream>

using namespace std;
const int N = 1010;
int a[N][N], s[N][N];

//不同于一维差分数组，二维差分数组中[x1,y1]之后的正方形区域都会+c。
//因此需要将[x1,y2+1]和[x2+1,y1]之后的区域-c,还要给[x2+1,y2+1]+c
void insert(int x1, int y1, int x2, int y2, int c) {
    s[x1][y1] += c;
    s[x1][y2 + 1] -= c;
    s[x2 + 1][y1] -= c;
    s[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            insert(i, j, i, j, a[i][j]);
        }
    }
    int x1, y1, x2, y2, c;
    while (q--) {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        insert(x1, y1, x2, y2, c);
    }
    //需要注意这里是在差分数组的基础上进行前缀和的计算，所以都是+=操作
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%d ", s[i][j]);
        printf("\n");
    }
    return 0;
}