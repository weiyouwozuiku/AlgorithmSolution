//
// Created by king on 2022/3/21.
//

#include <iostream>

using namespace std;
int n, m;
const int N = 1e5 + 10;
int e[N], ne[N], h[N];

void add(int x, int y, int z) {

}

int main() {
    scanf("%d%d", &n, &m);
    int x, y, z;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    return 0;
}