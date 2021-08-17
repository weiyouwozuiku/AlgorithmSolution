//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 有效括号组合需满足：左括号必须以正确的顺序闭合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 动态规划 回溯 👍 1962 👎 0

/**
 * 本题的解题思路：
 * 满足要求的小括号集合必然满足以下两个性质：
 * 1. 任意前缀中'('数量必然>=')'的数量
 * 2. 左右括号数量相等
 * 如果本题不是需要输出所有方案，而是只求数量的话，可以通过卡特兰数进行计算
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <string> ans;

    vector <string> generateParenthesis(int n) {
        dfs(n, 0, 0, "");
        return ans;
    }

    void dfs(int n, int lc, int rc, string seq) {
        if (lc == n && rc == n) ans.push_back(seq);
        else {
            if (lc < n) dfs(n, lc + 1, rc, seq + '(');
            if (rc < n && lc > rc) dfs(n, lc, rc + 1, seq + ')');
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
