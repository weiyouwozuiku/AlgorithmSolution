//
// Created by king on 2021/4/6.
//

#include <iostream>

using namespace std;
const int N = 10000 + 10;
int q[N];

int main() {
    int n, num, min = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &num);
        q[num] += 1;
    }
    for (int i = 0; i < N; i++) {
        if (q[min] < q[i]) min = i;
    }
    printf("%d", min);
    return 0;
}