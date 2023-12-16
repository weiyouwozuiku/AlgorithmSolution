//给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。 
//
// 返回这三个数的和。 
//
// 假定每组输入只存在恰好一个解。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,0,0], target = 1
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 1000 
// -1000 <= nums[i] <= 1000 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related Topics 数组 双指针 排序 👍 1534 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(int x, int y) { return x < y; };

    int threeSumClosest(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1, res = 0, min_diff = INT_MAX, tmp = 0;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < r - 1; ++i) {
            if (i && nums[i] == nums[i - 1]) continue;
            tmp = nums[i] + nums[i + 1] + nums[i + 2];
            //此时表明之后的所有i的组合的和都大于现在的tmp，可以直接丢弃
            if (tmp > target) {
                if (tmp - target < min_diff) {
                    res = tmp;
                }
                break;
            }
            tmp = nums[i] + nums[r - 1] + nums[r];
            if (tmp < target) {
                if (target - tmp < min_diff) {
                    res = tmp;
                    min_diff = target - tmp;
                }
                continue;
            }

            for (int j = i + 1; j < r; ++j) {
                int k = r;
                while (j < k) {
                    tmp = nums[i] + nums[j] + nums[k];
                    if (tmp < target) {
                        if (target - tmp < min_diff) {
                            min_diff = target - tmp;
                            res = tmp;
                        }
                        j += 1;
                    }
                    if (tmp > target) {
                        if (tmp - target < min_diff) {
                            res = tmp;
                            min_diff = tmp - target;
                        }
                        k -= 1;
                    }
                    if (tmp == target) return target;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
