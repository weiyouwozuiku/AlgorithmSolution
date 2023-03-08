//
// Created by king on 2023/3/4.
//
#include <cstring>
#include <iostream>

using namespace std;
char nums[101][101];
int r, c;
bool st[101][101];
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    st[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 0 && tx < r && ty >= 0 && ty < c && st[tx][ty] == false && nums[tx][ty] == '1') dfs(tx, ty);
    }
}

int query() {
    memset(st, 0, sizeof st);
    int res = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (!st[i][j] && nums[i][j] == '1') {
                res += 1;
                dfs(i, j);
            }
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":" << endl;
        cin >> r >> c;
        for (int j = 0; j < r; ++j) cin >> nums[j];
        int n;
        cin >> n;
        char op;
        while (n--) {
            cin >> op;
            if (op == 'M') {
                int x, y, z;
                cin >> x >> y >> z;
                nums[x][y] = '0' + z;
            }
            if (op == 'Q') cout << query() << endl;
        }
    }
    return 0;
}