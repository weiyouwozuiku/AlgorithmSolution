//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
// 
// 
// Related Topics 数组 回溯算法 
// 👍 525 👎 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    //key为数字，value为出现次数
    unordered_map<int, int> cnt;
    //结果集合
    vector<vector<int>> ans;
    //路径
    vector<int> path;
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        //如果只有一个数字，直接返回一个空集与当前数字
        if (nums.size() == 1) {
            ans.push_back(vector<int>{});
            ans.push_back(vector<int>{nums[0]});
        } else {
            for (auto itor:nums) cnt[itor] += 1;
            //这题范围较小，直接枚举
            dfs(-10);
        }
        return ans;
    }

    void dfs(int n) {
        //超过边界将结果保存
        if (n > 10) ans.push_back(path);
        else {
            //这里处理数字出现的次数，从0到cnk[n]次
            for (int i=0;i<cnt[n]+1;i++){
                dfs(n+1);
                path.push_back(n);
            }
            //清理现场
            for (int i=0;i<cnt[n]+1;i++) path.pop_back();
        }
    }
};


//leetcode submit region end(Prohibit modification and deletion)
int main() {
    vector<int> a = {1,2,2};
    Solution solution;
    auto res = solution.subsetsWithDup(a);
    for (auto itor:res) {
        for (auto it:itor) {
            printf("%d", it);
        }
        printf(" ");
    }
    return 0;
}