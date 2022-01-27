//给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 
//mat[r][c] 的和： 
//
// 
// i - k <= r <= i + k, 
// j - k <= c <= j + k 且 
// (r, c) 在矩阵内。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//输出：[[12,21,16],[27,45,33],[24,39,28]]
// 
//
// 示例 2： 
//
// 
//输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
//输出：[[45,45,45],[45,45,45],[45,45,45]]
// 
//
// 
//
// 提示： 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= m, n, k <= 100 
// 1 <= mat[i][j] <= 100 
// 
// Related Topics 数组 矩阵 前缀和 👍 125 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //获取边界条件
    int get(vector <vector<int>> &arr,int m, int n, int x, int y ) {
        x = min(max(x, 0), m);
        y = min(max(y, 0), n);
        return arr[x][y];
    }

    vector <vector<int>> matrixBlockSum(vector <vector<int>> &mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector <vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        vector <vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = get(sum, m, n, i + k + 1, j + k+ 1) - get(sum, m, n, i - k, j + k + 1) -
                            get(sum, m, n, i + k + 1, j - k) + get(sum, m, n, i - k, j - k);
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
