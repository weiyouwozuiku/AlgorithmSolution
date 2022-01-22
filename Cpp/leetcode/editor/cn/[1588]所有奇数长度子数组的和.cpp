//给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。 
//
// 子数组 定义为原数组中的一个连续子序列。 
//
// 请你返回 arr 中 所有奇数长度子数组的和 。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [1,4,2,5,3]
//输出：58
//解释：所有奇数长度子数组和它们的和为：
//[1] = 1
//[4] = 4
//[2] = 2
//[5] = 5
//[3] = 3
//[1,4,2] = 7
//[4,2,5] = 11
//[2,5,3] = 10
//[1,4,2,5,3] = 15
//我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58 
//
// 示例 2： 
//
// 输入：arr = [1,2]
//输出：3
//解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。 
//
// 示例 3： 
//
// 输入：arr = [10,11,12]
//输出：66
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 100 
// 1 <= arr[i] <= 1000 
// 
// Related Topics 数组 数学 前缀和 👍 146 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 暴力
    int sumOddLengthSubarraysOn3(vector<int> &arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int step = 1; step + i - 1 < arr.size(); step += 2) {
                sum += accumulate(arr.begin() + i, arr.begin() + i + step, 0);
            }
        }
        return sum;
    }

    // 前缀和
    int sumOddLengthSubarraysOn2(vector<int> &arr) {
        int sum = 0;
        vector<int> res = {0};
        for (auto item: arr) {
            res.push_back(item + res.back());
        }
        for (int i = 0; i < arr.size(); i++) {
            for (int step = 1; step + i - 1 < arr.size(); step += 2) {
                sum += res[i + step] - res[i];
            }
        }
        return sum;
    }

    // 数字法
    int sumOddLengthSubarraysOn1(vector<int> &arr) {
        int sum = 0;
        int n = arr.size();
        int leftCount, rightCount, leftOdd, rightOdd, leftEven, rightEven;
        for (int i = 0; i < n; i++) {
            leftCount = i;
            rightCount = n - i - 1;
            leftOdd = (leftCount + 1) / 2;
            rightOdd = (rightCount + 1) / 2;
            leftEven = leftCount / 2 + 1;
            rightEven = rightCount / 2 + 1;
            sum += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
