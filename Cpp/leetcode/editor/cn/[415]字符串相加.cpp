//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。 
//
// 你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。 
//
// 
//
// 示例 1： 
//
// 
//输入：num1 = "11", num2 = "123"
//输出："134"
// 
//
// 示例 2： 
//
// 
//输入：num1 = "456", num2 = "77"
//输出："533"
// 
//
// 示例 3： 
//
// 
//输入：num1 = "0", num2 = "0"
//输出："0"
// 
//
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num1.length, num2.length <= 10⁴ 
// num1 和num2 都只包含数字 0-9 
// num1 和num2 都不包含任何前导零 
// 
// Related Topics 数学 字符串 模拟 👍 497 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> A, B;
        int k = 0;
        string res = "";
        for (int i = num1.size() - 1; i >= 0; i--) {
            A.push_back(num1[i] - '0');
        }
        for (int i = num2.size() - 1; i >= 0; i--) {
            B.push_back(num2[i] - '0');
        }
        for (int i = 0; i < A.size() || i < B.size(); i++) {
            if (i < A.size()) k += A[i];
            if (i < B.size()) k += B[i];
            res += char(k % 10 + '0');
            k /= 10;
        }
        if (k) res += char('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
