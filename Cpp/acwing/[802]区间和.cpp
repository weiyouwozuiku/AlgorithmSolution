//
// Created by king on 2021/4/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 3 * 1e5 + 10;
typedef pair<int, int> PAIR;
//存放插入与查询信息
vector<PAIR> add, query;
//存放计算区间和的差分数组和前缀和数组
int a[N], s[N];
//alls存放对应索引信息
vector<int> alls;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    int n, m, index, data, l, r;
    scanf("%d%d", &n, &m);
    //step1 将所有用到的位置索引存入alls容器中,将相应的插入信息与查询信息存入add和query中
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &index, &data);
        add.push_back({index, data});
        alls.push_back(index);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    //step2 索引位置去重,此时alls下标就是相应索引映射后的位置
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //step3 插入数据
    for (auto item: add) a[find(item.first)] += item.second;
    //step4 计算前缀和
    for (int i = 1; i <= alls.size(); ++i) s[i] += s[i - 1] + a[i];
    //step5 返回结果
    for (auto item :query) {
        printf("%d\n", s[find(item.second)] - s[find(item.first) - 1]);
    }
    return 0;
}