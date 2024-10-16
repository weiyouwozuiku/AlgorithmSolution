//Given a string expression of numbers and operators, return all possible 
//results from computing all the different possible ways to group numbers and operators.
// You may return the answer in any order. 
//
// The test cases are generated such that the output values fit in a 32-bit 
//integer and the number of different results does not exceed 10⁴. 
//
// 
// Example 1: 
//
// 
//Input: expression = "2-1-1"
//Output: [0,2]
//Explanation:
//((2-1)-1) = 0 
//(2-(1-1)) = 2
// 
//
// Example 2: 
//
// 
//Input: expression = "2*3-4*5"
//Output: [-34,-14,-10,-10,10]
//Explanation:
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10
// 
//
// 
// Constraints: 
//
// 
// 1 <= expression.length <= 20 
// expression consists of digits and the operator '+', '-', and '*'. 
// All the integer values in the input expression are in the range [0, 99]. 
// 
//
// Related Topics Math String Dynamic Programming Recursion Memoization 👍 5520 
//👎 297
#include <vector>
#include <iostream>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> dfs(string s, int l, int r) {
        vector<int> ans;
        for (int i = l; i <= r; ++i) {
            if (s[i] >= '0' && s[i] <= '9') continue;
            auto _l = dfs(s, l, i - 1), _r = dfs(s, i + 1, r);
            for (const auto l1: _l) {
                for (const auto r1: _r) {
                    if (s[i] == '+') ans.push_back(l1 + r1);
                    if (s[i] == '-') ans.push_back(l1 - r1);
                    if (s[i] == '*') ans.push_back(l1 * r1);
                    if (s[i] == '/') ans.push_back(l1 / r1);
                }
            }
        }
        if (ans.empty()) {
            int cur = 0;
            for (int i = l; i <= r; ++i) cur = cur * 10 + (s[i] - '0');
            ans.push_back(cur);
        }
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression, 0, expression.size() - 1);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution a;
    auto demo = a.diffWaysToCompute("2*3-4*5");
    for (const auto i: demo) cout << i << endl;
}
