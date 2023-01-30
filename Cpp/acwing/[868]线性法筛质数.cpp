//
// Created by king on 2023/1/15.
//
#include <cstdio>

const int N = 1e6 + 10;
// primes[]存储所有素数
int primes[N], cnt;
// st[x]存储x是否被筛掉
bool st[N];

// 埃式筛法
void get_primes(int x) {
    for (int i = 2; i <= x; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i + i; j <= x; j += i) st[j] = true;
        }
    }
}

// 线性筛法
void get_grimes_linear(int x) {
    for(int i=2;i<=x;++i){
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]*i<x;++j){
            st[i*primes[j]]= true;
            if(i% primes[j]==0) break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    get_grimes_linear(n);
    printf("%d", cnt);
    return 0;
}
