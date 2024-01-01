//给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
//
// 
//
// 提示： 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 和 word2 由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 3252 👎 0
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // 本题dp,分为几种情况：
    // 采用f(i,j)表示分别表示:i word1的字符串索引位置，j word2的字符串索引位置
    // 1. f(i-1,j):word1添加i位置的字符等于word2 word2删除j位置的字符等于word2
    // 2. f(i,j-1):word2添加j位置的字符等于word1 word1删除j位置的字符等于word2
    // 3. f(i-1,j-1): word1中[0,i-1]和word2[0,j-1]相同 word1中的i位置和word2中的j位置不同则+1，否则不加
public:
    int minDistance(string word1, string word2) {
        word1 = ' ' + word1, word2 = ' ' + word2;
        int n = word1.size(), m = word2.size();
        vector <vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; ++i) f[i][0] = i;
        for (int i = 0; i <= m; ++i) f[0][i] = i;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                int t = word1[i] != word2[j];
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);
            }
        }
        return f[n][m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
