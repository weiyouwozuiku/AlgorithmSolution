//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bcabc"
//输出："abc"
// 
//
// 示例 2： 
//
// 
//输入：s = "cbacdcbc"
//输出："acdb" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 由小写英文字母组成 
// 
//
// 
//
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-
//distinct-characters 相同 
// Related Topics 栈 贪心 字符串 单调栈 👍 679 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk;
        // 存放当前字符是否存在stk中
        unordered_map<char, bool> box;
        // 存放当前字符在整个人字符串的最后位置
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.size(); ++i) lastIndex[s[i]] = i;
        for (int i = 0; i < s.size(); ++i) {
            if (!box[s[i]]) {
                while (stk.size() && s[i] < stk.back() && lastIndex[stk.back()] > i) {
                    box[stk.back()] = false;
                    stk.pop_back();
                }
                stk += s[i];
                box[s[i]] = true;
            }
        }
        return stk;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
