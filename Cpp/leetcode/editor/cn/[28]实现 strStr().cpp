//实现 strStr() 函数。 
//
// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如
//果不存在，则返回 -1 。 
//
// 
//
// 说明： 
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "hello", needle = "ll"
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：haystack = "aaaaa", needle = "bba"
//输出：-1
// 
//
// 示例 3： 
//
// 
//输入：haystack = "", needle = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= haystack.length, needle.length <= 5 * 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
// Related Topics 双指针 字符串 字符串匹配 👍 1242 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> ne;

    void build(const string &needle) {
        int n = needle.length();
        // 这里最后多出来的元素用来标记匹配成功的情况
        ne.resize(n + 1);
        for (int i = 0, j = ne[0] = -1; i < n; ne[++i] = ++j) {
            // ~j表示j为-1的情况
            while (~j && needle[i] != needle[j]) j = ne[j];
        }
    }

    int strStr(string haystack, string needle) {
        if (!needle.length()) return 0;
        int res = -1, m = haystack.length(), n = needle.length();
        build(needle);
        for (int i = 0, j = 0; i < m; ++i) {
            while (j > 0 && haystack[i] != needle[j]) j = ne[j];
            if (haystack[i] == needle[j]) ++j;
            if (j == n) {
                res = i - n + 1;
                break;
                // 如果是查找多个
                // 只需要j=ne[j];即可，ne[n]==0，即从匹配串的第0位开始重新匹配
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
