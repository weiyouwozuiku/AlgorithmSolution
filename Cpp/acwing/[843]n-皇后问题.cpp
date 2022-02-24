//
// Created by king on 2022/2/23.
//

#include <iostream>

using namespace std;
int n;
const int N = 10;
bool col[N], dg[N], udg[N];
char g[N][N];

void dfs(int u) {
    if(u==n){
        for(int i=0;i<n;i++)puts(g[i]);
        puts("");
    } else{
        for (int i = 0; i < n; ++i) {
            if(!col[i]&&!dg[u+i]&&!udg[n-u+i]){
                g[u][i]='Q';
                col[i]=dg[u+i]=udg[n-u+i]= true;
                dfs(u+1);
                col[i]=dg[u+i]=udg[n-u+i]= false;
                g[u][i]='.';
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    // 初始化结果队列
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}