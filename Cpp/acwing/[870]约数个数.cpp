//
// Created by king on 2023/1/15.
//
#include <cstdio>
#include <unordered_map>

typedef long long LL;
const int mod = 1e9 + 7;

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
    LL res = 1;
    std::unordered_map<int, int> divisors;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        get_divisor(divisors, x);
    }
    for (auto &it: divisors) {
        res = (it.second + 1) * res % mod;
    }
    printf("%lld", res);
    return 0;
}