//n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 4
//输出：2
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
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
// Related Topics 回溯 👍 337 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int n;
    vector<bool> col, dg, udg;
    int res;

    int totalNQueens(int _n) {
        n = _n;
        res = 0;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);
        dfs(0);
        return res;
    }

    void dfs(int u){
        if(u==n){
            ++res;
        } else{
            for(int i=0;i<n;++i){
                if(!col[i]&&!dg[u-i+n]&&!udg[u+i]){
                    col[i]=dg[u-i+n]=udg[u+i]=true;
                    dfs(u+1);
                    col[i]=dg[u-i+n]=udg[u+i]= false;
                }
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
