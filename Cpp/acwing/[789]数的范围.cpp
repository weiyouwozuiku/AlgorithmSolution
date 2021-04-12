//
// Created by king on 2021/4/9.
//

#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int q[N];

int main() {
    int n, time;
    scanf("%d%d", &n, &time);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    while (time--) {
        int x;
        scanf("%d", &x);
        int l=0,r=n-1;
        while (l<r){
            int mid=l+r>>1;
            if (q[mid]>=x) r=mid;
            else l=mid+1;
        }
        if(q[l]!=x) printf("-1 -1\n");
        else{
            printf("%d ",l);
            l=0,r=n-1;
            while (l<r){
                int mid=l+r+1>>1;
                if(q[mid]<=x) l=mid;
                else r=mid-1;
            }
            printf("%d\n",l);
        }
    }
    return 0;
}