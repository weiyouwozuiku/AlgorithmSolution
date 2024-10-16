//Given a string s, find the length of the longest substring without repeating 
//characters. 
//
// 
// Example 1: 
//
// 
//Input: s = "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
// 
//
// Example 2: 
//
// 
//Input: s = "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
// 
//
// Example 3: 
//
// 
//Input: s = "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Notice that the answer must be a substring, "pwke" is a subsequence and not a 
//substring.
// 
//
// 
// Constraints: 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s consists of English letters, digits, symbols and spaces. 
// 
//
// Related Topics Hash Table String Sliding Window 👍 40084 👎 1920
#include <unordered_map>
#include <string>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash(s.size());
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            hash[s[i]] += 1;
            while (hash[s[i]] > 1) hash[s[j++]] -= 1;
            res = max(res, i - j + 1);
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
