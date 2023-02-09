//
// Created by king on 2023/1/15.
//
#include <cstdio>
#include <unordered_map>

const int mod = 1e9 + 7;
typedef long long LL;

void get_divisor(std::unordered_map<int, int> &map, int x) {
    for (int i = 2; i <= x / i; ++i) {
        while (x % i == 0) {
            x /= i;
            map[i] += 1;
        }
    }
    if (x > 1) map[x] += 1;
}

int main() {
    int n, x;
    scanf("%d", &n);
    std::unordered_map<int, int> map;
    LL res = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        get_divisor(map, x);
    }
    for (auto &it: map) {
        int p = it.first, a = it.second;
        LL t = 1;
        while (a--) t = (p * t + 1) % mod;
        res = res * t % mod;
    }
    printf("%lld", res);
    return 0;
}