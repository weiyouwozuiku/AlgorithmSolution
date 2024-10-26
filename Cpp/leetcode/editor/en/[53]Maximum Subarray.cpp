//Given an integer array nums, find the subarray with the largest sum, and 
//return its sum. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// 
//
// Example 2: 
//
// 
//Input: nums = [1]
//Output: 1
//Explanation: The subarray [1] has the largest sum 1.
// 
//
// Example 3: 
//
// 
//Input: nums = [5,4,-1,7,8]
//Output: 23
//Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
// Follow up: If you have figured out the O(n) solution, try coding another 
//solution using the divide and conquer approach, which is more subtle. 
//
// Related Topics Array Divide and Conquer Dynamic Programming 👍 34583 👎 1467
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        // vector<int> f(nums.size());
        // f[0]=nums[0];
        // for(int i=1;i<nums.size();++i) f[i]=max(f[i-1],0)+nums[i];
        // return *max_element(f.begin(),f.end());
        int f = INT_MIN, res = INT_MIN;
        for (auto i: nums)f = max(f, 0) + i, res = max(res, f);
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
