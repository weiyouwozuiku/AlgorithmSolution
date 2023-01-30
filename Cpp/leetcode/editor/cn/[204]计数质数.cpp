//给定整数 n ，返回 所有小于非负整数 n 的质数的数量 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 10
//输出：4
//解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 
//
// 示例 2： 
//
// 
//输入：n = 0
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：n = 1
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 5 * 10⁶ 
// 
//
// Related Topics 数组 数学 枚举 数论 👍 1006 👎 0

// 埃氏筛 O(loglogn)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> st(n + 1, false);
        int nums = 0;
        for (int i = 2; i < n; ++i) {
            if (!st[i]) {
                nums += 1;
                for (int j = i + i; j < n; j += i) st[j] = true;
            }
        }
        return nums;
    }
};

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> st(n + 1, false);
        vector<int> primes;
        for (int i = 2; i < n; ++i) {
            if (!st[i]) primes.push_back(i);
            for (int j = 0; j < primes.size() && primes[j] <= n / i; ++j) {
                st[primes[j]*i]=true;
                if(i%primes[j]==0) break;
            }
        }
        return primes.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
