//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 
// 
// 
// Related Topics 数组 回溯 👍 1205 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    vector<bool> col, dg, udg;
    vector <string> path;
    vector <vector<string>> ans;

    vector <vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);
        path = vector<string>(n, string(n, '.'));
        dfs(0);
        return ans;
    }

    void dfs(int u) {
        if (u == n) ans.push_back(path);
        else {
            for (int i = 0; i < n; i++) {
                if (!col[i] && !dg[u - i + n] && !udg[u + i]) {
                    col[i] = dg[u - i + n] = udg[u + i] = true;
                    path[u][i] = 'Q';
                    dfs(u + 1);
                    path[u][i] = '.';
                    col[i] = dg[u - i + n] = udg[u + i] = false;
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
