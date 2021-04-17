//
// Created by king on 2021/4/17.
//

#include <iostream>

using namespace std;
const int N = 1e6 + 10;
// q数组为原数组,b数组为差分数组
int q[N], b[N];
void insert(int l,int r,int c){
    b[l]+=c;
    b[r+1]-=c;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &q[i]);
        //step1 构造差分数组
        insert(i,i,q[i]);
    }
    //step2 更新差分数组信息
    int l,r,c;
    while (m--) {
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    //step3 更新前缀和
    //此处的b数组成为前缀和数组
    for(int i=1;i<=n;i++) {
        b[i]+=b[i-1];
        printf("%d ",b[i]);
    }
    return 0;
}