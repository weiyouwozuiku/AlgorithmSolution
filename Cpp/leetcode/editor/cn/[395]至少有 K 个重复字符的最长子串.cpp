//给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串， 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aaabb", k = 3
//输出：3
//解释：最长子串为 "aaa" ，其中 'a' 重复了 3 次。
// 
//
// 示例 2： 
//
// 
//输入：s = "ababbc", k = 2
//输出：5
//解释：最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 仅由小写英文字母组成 
// 1 <= k <= 10⁵ 
// 
//
// Related Topics 哈希表 字符串 分治 滑动窗口 👍 783 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
// 本题的主要思想是在不满足单调性的情况下通过增加约束的方式，使得出现单调性。
// 限制住每次子串中不同字母的个数可以保证其出现单调性
class Solution {
public:
    int k;
    unordered_map<char, int> heap;

    void add(char c, int &x, int &y) {
        if (!heap[c]) x += 1;
        heap[c] += 1;
        if (heap[c] == k) y += 1;
    }

    void del(char c, int &x, int &y) {
        if (heap[c] == k) y -= 1;
        heap[c] -= 1;
        if (!heap[c]) x -= 1;
    }

    int longestSubstring(string s, int _k) {
        k = _k;
        int res = 0;
        for (int k = 1; k <= 26; ++k) {
            heap.clear();
            for (int i = 0, j = 0, x = 0, y = 0; i < s.size(); ++i) {
                add(s[i], x, y);
                while (k < x) del(s[j++], x, y);
                if (y == x) res = max(res, i - j + 1);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
