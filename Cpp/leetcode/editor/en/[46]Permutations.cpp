//Given an array nums of distinct integers, return all the possible 
//permutations. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// 
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
//
// Related Topics Array Backtracking 👍 19357 👎 338
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<bool> st;
    vector<int> path;

    vector<vector<int> > permute(vector<int> &nums) {
        vector<vector<int> > res;
        st = vector<bool>(nums.size(), false);
        path = vector<int>(nums.size());
        dfs(nums, res, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<vector<int> > &res, int k) {
        if (k == nums.size())res.push_back(path);
        else {
            for(int i=0;i<nums.size();++i) {
                if(!st[i]) {
                    st[i]=true;
                    path[k]=nums[i];
                    dfs(nums,res,k+1);
                    st[i]=false;
                }
            }
        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)
