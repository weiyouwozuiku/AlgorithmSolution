//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']
//', determine if the input string is valid. 
//
// An input string is valid if: 
//
// 
// Open brackets must be closed by the same type of brackets. 
// Open brackets must be closed in the correct order. 
// Every close bracket has a corresponding open bracket of the same type. 
// 
//
// 
// Example 1: 
//
// 
// Input: s = "()" 
// 
//
// Output: true 
//
// Example 2: 
//
// 
// Input: s = "()[]{}" 
// 
//
// Output: true 
//
// Example 3: 
//
// 
// Input: s = "(]" 
// 
//
// Output: false 
//
// Example 4: 
//
// 
// Input: s = "([])" 
// 
//
// Output: true 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// s consists of parentheses only '()[]{}'. 
// 
//
// Related Topics String Stack 👍 24612 👎 1814
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    unordered_map<char, char> heap = {{')', '('}, {']', '['}, {'}', '{'}};

    bool isValid(string s) {
        stack<char> stk;
        for (auto i: s) {
            if (i == '(' || i == '[' || i == '{') stk.push(i);
            else {
                if (stk.size() && heap[i] == stk.top()) stk.pop();
                else return false;
            }
        }
        return stk.size() ? false : true;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
