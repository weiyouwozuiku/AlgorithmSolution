//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[
//k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. 
//
// Notice that the solution set must not contain duplicate triplets. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Explanation: 
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//The distinct triplets are [-1,0,1] and [-1,-1,2].
//Notice that the order of the output and the order of the triplets does not 
//matter.
// 
//
// Example 2: 
//
// 
//Input: nums = [0,1,1]
//Output: []
//Explanation: The only possible triplet does not sum up to 0.
// 
//
// Example 3: 
//
// 
//Input: nums = [0,0,0]
//Output: [[0,0,0]]
//Explanation: The only possible triplet sums up to 0.
// 
//
// 
// Constraints: 
//
// 
// 3 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// Related Topics Array Two Pointers Sorting 👍 31498 👎 2945
#include <vector>
#include <unordered_map>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(int x, int y) {
        return x < y;
    }

    vector<vector<int> > threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end(), cmp);
        vector<vector<int> > res;
        int r = nums.size() - 1;
        for (int i = 0; i < r - 1; ++i) {
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break;
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = r; j < k; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                while (j < k - 1 && nums[i] + nums[j] + nums[k] > 0) k -= 1;
                if (nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
