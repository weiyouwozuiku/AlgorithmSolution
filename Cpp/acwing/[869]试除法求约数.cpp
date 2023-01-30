//
// Created by king on 2023/1/15.
//
#include <cstdio>
#include <vector>

std::vector<int> get_divisors(int x) {
    std::vector<int> result;
    for (int i = 1; i <= x / i; ++i) {
        if (x % i == 0) {
            result.push_back(i);
        }
    }
    int cnt = result.size();
    for (int i = cnt - 1; i >= 0; --i) {
        // 特判不要添加重复的约数
        if (x / result[i] != result[i]) result.push_back(x / result[i]);
    }
    return result;
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        std::vector<int> result = get_divisors(x);
        for (auto &it: result) {
            printf("%d ", it);
        }
        puts("");
    }
}