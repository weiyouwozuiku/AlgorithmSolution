//
// Created by king on 2021/5/6.
//

#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int stk[N], top = -1;

int main() {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        while (top != -1 && stk[top] >= x) --top;
        if (top != -1) printf("%d ", stk[top]);
        else printf("-1 ");
        //注意，需要将当前数字压入栈中
        stk[++top] = x;
    }
    return 0;
}