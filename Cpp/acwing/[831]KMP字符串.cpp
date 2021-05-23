//
// Created by king on 2021/5/13.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
char p[N], s[M];
vector<int> ne;

// brute force暴力枚举算法
// 复杂度为O(n*m)。当n和m为1e5数量级时，算法完全不可用。
void bruteForce(char *S, char *P) {
    int lens = strlen(S), lenp = strlen(P);
    for (int i = 0; i <= lens - lenp; ++i) {
        bool flag = true;
        for (int j = 0; P[j] != '\0'; ++j) {
            if (S[i + j] != P[j]) {
                flag = false;
                break;
            }
        }
        if (flag) printf("%d ", i);
    }
}

// KMP算法
// 复杂度为O(m+n)
void build(const char *pattern) {
    int len = strlen(pattern);
    ne.resize(len + 1);
    for (int i = 0, j = ne[0] = -1; i < len; ne[++i] = ++j) {
        while (~j && pattern[j] != pattern[i]) j = ne[j];
    }
}

vector<int> match(const char *text, const char *pattern) {
    vector<int> res;
    int lenp = strlen(pattern), lent = strlen(text);
    build(pattern);
    for (int i = 0, j = 0; i < lent; ++i) {
        while (j > 0 && text[i] != pattern[j]) j = ne[j];
        if (text[i] == pattern[j]) ++j;
        if (j == lenp) res.push_back(i - lenp + 1), j = ne[j];
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) scanf("%c", &p[i]);
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; ++i) scanf("%c", &s[i]);
    auto res = match(s, p);
    for (auto itor:res) printf("%d ", itor);
    return 0;
}