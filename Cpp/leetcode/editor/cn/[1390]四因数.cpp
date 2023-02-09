//给你一个整数数组 nums，请你返回该数组中恰有四个因数的这些整数的各因数之和。如果数组中不存在满足题意的整数，则返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [21,4,7]
//输出：32
//解释：
//21 有 4 个因数：1, 3, 7, 21
//4 有 3 个因数：1, 2, 4
//7 有 2 个因数：1, 7
//答案仅为 21 的所有因数的和。
// 
//
// 示例 2: 
//
// 
//输入: nums = [21,21]
//输出: 64
// 
//
// 示例 3: 
//
// 
//输入: nums = [1,2,3,4,5]
//输出: 0 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁴ 
// 1 <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 数学 👍 27 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int sumFourDivisors(vector<int> &nums) {
        vector < unordered_map < int, int > * > primes;
        for (auto x: nums) {
            unordered_map<int, int> *map = new unordered_map<int, int>;
            for (int i = 2; i <= x / i; ++i) {
                while (x % i == 0) {
                    x /= i;
                    (*map)[i] += 1;
                }
            }
            if (x > 1) (*map)[x] += 1;
            int divisors = 1;
            for (auto &it: *map) {
                divisors *= it.second + 1;
                if (divisors > 4) break;
            }
            if (divisors == 4) primes.push_back(map);
        }
        int res = 0;
        for (auto its: primes) {
            int tmp = 1;
            for (auto it: *its) {
                int p = it.first, a = it.second, t = 1;
                while (a--) t = p * t + 1;
                tmp *= t;
            }
            res += tmp;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
