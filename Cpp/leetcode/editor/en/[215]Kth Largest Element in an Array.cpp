//Given an integer array nums and an integer k, return the kᵗʰ largest element 
//in the array. 
//
// Note that it is the kᵗʰ largest element in the sorted order, not the kᵗʰ 
//distinct element. 
//
// Can you solve it without sorting? 
//
// 
// Example 1: 
// Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
// 
// Example 2: 
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
// 
// Constraints: 
//
// 
// 1 <= k <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// Related Topics Array Divide and Conquer Sorting Heap (Priority Queue) 
//Quickselect 👍 17325 👎 912
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int binerySort(vector<int> &nums, int l, int r, int k) {
        if (l >= r) return nums[l];
        int x = nums[l + (r - l) / 2], i = l - 1, j = r + 1;
        while (i < j) {
            do ++i;while (nums[i] > x);
            do --j;while (nums[j] < x);
            if (i < j) swap(nums[i], nums[j]);
        }
        if (k <= j) return binerySort(nums, l, j, k);
        return binerySort(nums, j + 1, r, k);
    }

    int findKthLargest(vector<int> &nums, int k) {
        return binerySort(nums, 0, nums.size() - 1, k - 1);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
