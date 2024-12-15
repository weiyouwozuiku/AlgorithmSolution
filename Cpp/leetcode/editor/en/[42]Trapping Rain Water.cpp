//Given n non-negative integers representing an elevation map where the width 
//of each bar is 1, compute how much water it can trap after raining. 
//
// 
// Example 1: 
// 
// 
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [
//0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) 
//are being trapped.
// 
//
// Example 2: 
//
// 
//Input: height = [4,2,0,3,2,5]
//Output: 9
// 
//
// 
// Constraints: 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics Array Two Pointers Dynamic Programming Stack Monotonic Stack ?
//? 32899 👎 557
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // int trap(vector<int> &height) {
    //     int pre[height.size()], next[height.size()];
    //     pre[0] = height[0], next[height.size() - 1] = height[height.size() - 1];
    //     for (int i = 1; i < height.size(); ++i) pre[i] = max(height[i], pre[i - 1]);
    //     for (int i = height.size() - 2; i >= 0; --i) next[i] = max(height[i], next[i + 1]);
    //     int res = 0;
    //     for (int i = 0; i < height.size(); ++i) {
    //         res += min(next[i], pre[i]) - height[i];
    //     }
    //     return res;
    // }
    int trap(vector<int> &height) {
        int pre_max = height[0], next_max = height[height.size() - 1], res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            pre_max = max(pre_max, height[l]), next_max = max(next_max, height[r]);
            if (pre_max <= next_max) res += pre_max - height[l++];
            else res += next_max - height[r--];
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
