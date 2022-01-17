//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。 
//
// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。 
//
// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 4
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：x = 8
//输出：2
//解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= x <= 2³¹ - 1 
// 
// Related Topics 数学 二分查找 👍 864 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int l = 1, r = x, mid;
        while (l < r) {
            // 这里直接写l+r可能会越界，但是这里将1替换成1ll会变成long long类型，避免越界
            // 或者写成l+(r-l)/2
            mid = l + 1ll + r >> 1;
            // 这里之所以写成这样是为了防止越界
            if (mid <= x / mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
