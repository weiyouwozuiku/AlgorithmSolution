//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的
//房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,3,2]
//输出：3
//解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,1]
//输出：4
//解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 3： 
//
// 
//输入：nums = [1,2,3]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 1000 
// 
//
// Related Topics 数组 动态规划 👍 1518 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
#define maxn 110
    int f[maxn][2];
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        // (x,0)表示没有起点的结果，(x,1)表示带上起点的结果
        f[0][0] = 0, f[0][1] = nums[0], f[1][0] = nums[1], f[1][1] = nums[0];
        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                f[i][j] = max(f[i - 1][j], f[i - 2][j] + nums[i]);
            }
        }
        return max(f[n - 1][0], f[n - 2][1]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
