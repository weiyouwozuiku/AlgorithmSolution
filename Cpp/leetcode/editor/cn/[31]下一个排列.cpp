//整数数组的一个 排列 就是将其所有成员以序列或线性顺序排列。 
//
// 
// 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。 
// 
//
// 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就
//是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。 
//
// 
// 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。 
// 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。 
// 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。 
// 
//
// 给你一个整数数组 nums ，找出 nums 的下一个排列。 
//
// 必须 原地 修改，只允许使用额外常数空间。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[1,2,3]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,1,5]
//输出：[1,5,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 100 
// 
//
// Related Topics 数组 双指针 👍 2099 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 本题的解题思路在于利用两次遍历，找到转折点。
// 首先是，先从后往前找第一个非递增的点，如果一直扫描到索引0，说明当前整体逆序，此时需要直接反转整个数组
// 否则，需要在找到的索引j到nums.size()-1之间找到大于nums[j-1]的最小值，交换nums[i-1]和nums[j-1]，再反转nums[i]之后的所有数
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1]) i -= 1;
        if (!i) reverse(nums.begin(), nums.end());
        else {
            int j = i;
            while (i < nums.size() && nums[i] > nums[j - 1]) i += 1;
            swap(nums[j - 1], nums[i - 1]);
            reverse(nums.begin() + j, nums.end());
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
