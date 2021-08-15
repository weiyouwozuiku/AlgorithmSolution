//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。 
//
// 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 121
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：x = -121
//输出：false
//解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
// 
//
// 示例 3： 
//
// 
//输入：x = 10
//输出：false
//解释：从右向左读, 为 01 。因此它不是一个回文数。
// 
//
// 示例 4： 
//
// 
//输入：x = -101
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// -231 <= x <= 231 - 1 
// 
//
// 
//
// 进阶：你能不将整数转为字符串来解决这个问题吗？ 
// Related Topics 数学 
// 👍 1582 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //这是将x转化为string,并比较二者
    bool isPalindrome_1(int x) {
        //如果是负数，因为符号的存在，必然不是回文数
        if (x < 0) return false;
        //to_string函数为C++11引入
        string s = to_string(x);
        //使用反向迭代器将生成的字符串与与其相反的字符串对比其是否一致
        return s == string(s.rbegin(), s.rend());
    }

    bool isPalindrome(int x) {
        //如果是负数，因为符号的存在，必然不是回文数
        if (x < 0) return false;
        long long res = 0;
        //因为后面修改了x的值，所以这里需要将x的值进行保存以便进行比较y
        int y = x;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == y;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
