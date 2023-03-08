//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 4132 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 本题使用了单调栈实现，last存上一个点的高度，需要注意的是这里stk存的是索引，而不是高度
class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < height.size(); ++i) {
            int last = 0;
            while (stk.size() && height[i] >= height[stk.top()]) {
                res += (height[stk.top()] - last) * (i - stk.top() - 1);
                last = height[stk.top()];
                stk.pop();
            }
            if (stk.size()) res += (height[i] - last) * (i - stk.top() - 1);
            stk.push(i);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
