//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// nums 是一个非递减数组 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related Topics 数组 二分查找 👍 2544 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 本题需要注意二分条件的选择，起点>=，终点<=以及查询到之后left需要保存下来，以免之后二分修改。
// 避免mid越界，可以l+(r-l)/2
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int len = nums.size(), l = 0, r = nums.size() - 1, mid = 0;
        if (len == 0) return {-1, -1};
        while (l < r) {
            mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[r] != target) return {-1, -1};
        int left = l;
        r = nums.size() - 1;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        return {left, r};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
