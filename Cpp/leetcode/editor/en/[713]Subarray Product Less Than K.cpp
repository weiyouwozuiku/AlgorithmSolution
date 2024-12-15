//Given an array of integers nums and an integer k, return the number of 
//contiguous subarrays where the product of all the elements in the subarray is strictly 
//less than k. 
//
// 
// Example 1: 
//
// 
//Input: nums = [10,5,2,6], k = 100
//Output: 8
//Explanation: The 8 subarrays that have product less than 100 are:
//[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
//Note that [10, 5, 2] is not included as the product of 100 is not strictly 
//less than k.
// 
//
// Example 2: 
//
// 
//Input: nums = [1,2,3], k = 0
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// 1 <= nums[i] <= 1000 
// 0 <= k <= 10⁶ 
// 
//
// Related Topics Array Binary Search Sliding Window Prefix Sum 👍 6959 👎 222
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) return 0;
        int num = 0;
        long long int product = 1;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            product *= nums[j];
            while (product >= k) product /= nums[i++];
            if (product < k)num += j - i + 1;
        }
        return num;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
