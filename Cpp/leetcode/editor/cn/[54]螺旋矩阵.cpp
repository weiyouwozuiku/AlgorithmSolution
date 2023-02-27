//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1309 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector <vector<int>> &matrix) {
        vector<int> res;
        int n = matrix.size();
        if (!n) return {};
        int m = matrix[0].size();
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        for (int i = 0, x = 0, y = 0, d = 0; i < n * m; ++i) {
            res.push_back(matrix[x][y]);
            matrix[x][y]=INT_MAX;
            st[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            // 需要注意这里的n和m
            if (a < 0 || a >= n || b < 0 || b >= m || matrix[a][b]==INT_MAX) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
