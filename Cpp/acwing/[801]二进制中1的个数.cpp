//
// Created by king on 2021/4/19.
//
#include <iostream>

using namespace std;
int lowbit(int x){
    return x&-x;
}
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int res=0,x;
        scanf("%d",&x);
        while (x){
            x-=lowbit(x);
            ++res;
        }
        printf("%d ",res);
    }
    return 0;
}
