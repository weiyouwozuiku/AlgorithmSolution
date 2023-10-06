//
// Created by king on 2023/10/6.
//
#include <cstdio>
#include <algorithm>

using namespace std;
// 这里的数量取决于物品的种数*log(s)
const int N = 25000;
int v[N], w[N], f[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a, b, s, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &a, &b, &s);
        //二进制化将原本的背包数量转成不同类型的物品
        for (int k = 1; k <= s; k *= 2) {
            cnt+=1;
            v[cnt] = a * k, w[cnt] = b * k;
            s -= k;
        }
        if (s > 0) {
            cnt += 1;
            v[cnt] = s * a, w[cnt] = s * b;
        }
    }
    n = cnt;
    for(int i=1;i<=n;++i){
        for(int j=m;j>=v[i];--j){
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    printf("%d",f[m]);
    return 0;
}