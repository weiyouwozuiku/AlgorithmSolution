//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 
//输入: s = "rat", t = "car"
//输出: false 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s 和 t 仅包含小写字母 
// 
//
// 
//
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
//
// Related Topics 哈希表 字符串 排序 👍 862 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.size() - 1, tlen = t.size() - 1;
        int sarr[26], tarr[26];
        memset(sarr, 0, sizeof sarr), memset(tarr, 0, sizeof tarr);
        for (int i = 0; i <= slen; ++i) sarr[s[i] - 'a'] += 1;
        for (int i = 0; i <= tlen; ++i) tarr[t[i] - 'a'] += 1;
        for (int i = 0; i < 26; ++i) {
            if (sarr[i] != tarr[i]) return false;
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
