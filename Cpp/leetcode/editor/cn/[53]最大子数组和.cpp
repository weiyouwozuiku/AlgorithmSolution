//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 子数组 是数组中的一个连续部分。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：nums = [5,4,-1,7,8]
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// 
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
//
// Related Topics 数组 分治 动态规划 👍 5717 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 这里采用了动态规划的方式。f(i)表示以nums[i]为最后一个元素的数组和
// f(i)可以分为两类只有一个元素的和多个元素累加的
// 一个元素的就是nums[i]，另一个就是f[i-1]+nums[i]
// 两种情况都包含nums[i]，提取出来就成了nums[i]+max(0,f(i-1))
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN;
        for (int i = 0,last=0; i < nums.size(); ++i) {
            last=nums[i]+max(0,last);
            res=max(last,res);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
