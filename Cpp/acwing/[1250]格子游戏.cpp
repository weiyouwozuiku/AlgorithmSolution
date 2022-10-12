//
// Created by king on 2022/10/12.
//
#include <iostream>

using namespace std;
const int N = 200 * 200 + 10;
int p[N];

int get(int x, int y, int n) {
    return x * n + y;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n * n; ++i)p[i] = i;
    int x, y, a, b, res = 0;
    char op;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> op;
        --x, --y;
        a = get(x, y, n);
        if (op == 'D')b = get(x + 1, y, n);
        else b = get(x, y + 1, n);
        if (find(a) == find(b)) {
            res = i;
            break;
        }
        p[find(a)]= find(b);
    }
    if(res) cout<<res<<endl;
    else puts("draw");
    return 0;
}