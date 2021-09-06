//
// Created by king on 2021/4/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> PAIR;
vector<PAIR> all;

vector<PAIR> merge(vector<PAIR> &x) {
    vector<PAIR> res;
    sort(x.begin(), x.end());
    int st = -2e9, ed = -2e9;
    for (auto itor:x) {
        if (ed < itor.first) {
            //将上一次结果存入res队列，如果是初始状态，则不存入
            if (st != -2e9)res.push_back({st, ed});
            st = itor.first;
            ed = itor.second;
        } else {
            ed = max(ed, itor.second);
        }

    }
    //将最后一组加入结果集，需要判断st!=-2e9避免传入空数组
    if (st != -2e9) res.push_back({st, ed});
    return res;
}

int main() {
    int n, l, r;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &l, &r);
        all.push_back({l, r});
    }
    printf("%d", merge(all).size());
    return 0;
}