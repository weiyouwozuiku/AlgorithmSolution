//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 👍 458 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void quicksort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return;
        } else {
            int x = nums[(l + r) / 2], i = l - 1, j = r + 1;
            while (i < j) {
                do i++; while (nums[i] < x);
                do j--; while (nums[j] > x);
                if (i < j) swap(nums[i], nums[j]);
            }
            quicksort(nums, l, j);
            quicksort(nums, j + 1, r);
        }
    }

    vector<int> sortArray(vector<int> &nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
