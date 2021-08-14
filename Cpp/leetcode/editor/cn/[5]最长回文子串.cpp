//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 示例 3： 
//
// 
//输入：s = "a"
//输出："a"
// 
//
// 示例 4： 
//
// 
//输入：s = "ac"
//输出："a"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母（大写和/或小写）组成 
// 
// Related Topics 字符串 动态规划 
// 👍 3943 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * 本题的回文串存在两种可能：
 * 1. 数量为奇数，两边对称
 * 2. 数量为偶数。从中向外，两两配对
 *
 * 解题的思路是选定一个i点，左边L点和R点分别是其回文串的左端点和右端点，则整个长度为(R-1)-(L+1)+1=R-L-1
 * 复杂度分析:枚举所有点作为i点为O(n)，枚举i点的LR点也是O(n)，因此整体为O(n^2)
 * 上述的解法较为通用，若是想追求更好的时间复杂度可以采用马拉车(Manacher)算法，将时间复杂度降至O(n)，但不具备通用性。
 */
class Solution {
public:
    string longestPalindrome(string s) {
        //最长回文串
        string res;
        //将字符串的每一个点作为i点进行分析
        for (int i = 0; i < s.size(); i++) {
            //假设此时i点的回文串字符数为奇数个
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
            //假设此时i点的回文串字符数为偶数个
            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
