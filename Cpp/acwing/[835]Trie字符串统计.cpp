//
// Created by king on 2021/5/28.
//

#include <iostream>

using namespace std;
const int N = 1e5 + 1;
// s存放的trie数，横坐标为所有字符串个数，纵坐标为每个字符串的字符
// cnt存放相应节点作为叶子节点的次数
// idx记录当前处理的s数组行数
int s[N][26], cnt[N], idx;
char op, str[N];

void insert(const char *str) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!s[p][u]) s[p][u] = ++idx;
        p = s[p][u];
    }
    ++cnt[p];
}

int query(const char *str) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int u = str[i] - 'a';
        if (!s[p][u]) return 0;
        p = s[p][u];
    }
    return cnt[p];
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        scanf("%c", &op);
        getchar();
        scanf("%s", &str);
        getchar();
        if (op == 'I') insert(str);
        if (op == 'Q') printf("%d\n",query(str));
    }
    return 0;
}