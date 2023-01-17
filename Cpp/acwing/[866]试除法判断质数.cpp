//
// Created by king on 2023/1/7.
//
#include <cstdio>

bool is_prime(int x) {
    if (x < 2)return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n,x;
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        if (is_prime(x)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}