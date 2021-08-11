//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 示例 4: 
//
// 
//输入: s = ""
//输出: 0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 104 
// s 由英文字母、数字、符号和空格组成 
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 5164 👎 0

/**
 * 本题的解题思路：
 * 双指针算法的主要优化点就是寻找题目中的单调性。假设变量i,j,i与j之间就是非重复元素的子串。
 * 则当i向后时，j最前的位置只能是当前位置或朝后的位置。可以采用反证法证明。
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> heap;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            heap[s[i]]++;
            while (heap[s[i]] > 1) heap[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
