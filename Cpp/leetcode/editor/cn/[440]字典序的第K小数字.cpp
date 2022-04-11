//给定整数 n 和 k，返回 [1, n] 中字典序第 k 小的数字。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = 13, k = 2
//输出: 10
//解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
// 
//
// 示例 2: 
//
// 
//输入: n = 1, k = 1
//输出: 1
// 
//
// 
//
// 提示: 
//
// 
// 1 <= k <= n <= 10⁹ 
// 
// Related Topics 字典树 👍 424 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int getCnt(int prefix, int n) {
        long long p = 1;
        auto A = to_string(n), B = to_string(prefix);
        int dt = A.size() - B.size();
        int res = 0;
        for (int i = 0; i < dt; ++i) {
            res += p;
            p *= 10;
        }
        A = A.substr(0, B.size());
        if (A == B) res += n - prefix * p + 1;
        else if (A > B) res += p;
        return res;
    }

    int findKthNumber(int n, int k) {
        int prefix = 1;
        while (k > 1) {
            int cnt = getCnt(prefix, n);
            if (k > cnt) {
                k -= cnt;
                prefix++;
            } else {
                prefix *= 10;
                --k;
            }
        }
        return prefix;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
