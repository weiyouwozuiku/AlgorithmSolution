//Given an array of integers nums, sort the array in ascending order and return 
//it. 
//
// You must solve the problem without using any built-in functions in O(nlog(n))
// time complexity and with the smallest space complexity possible. 
//
// 
// Example 1: 
//
// 
//Input: nums = [5,2,3,1]
//Output: [1,2,3,5]
//Explanation: After sorting the array, the positions of some numbers are not 
//changed (for example, 2 and 3), while the positions of other numbers are changed (
//for example, 1 and 5).
// 
//
// Example 2: 
//
// 
//Input: nums = [5,1,1,2,0,0]
//Output: [0,0,1,1,2,5]
//Explanation: Note that the values of nums are not necessairly unique.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
//
// Related Topics Array Divide and Conquer Sorting Heap (Priority Queue) Merge 
//Sort Bucket Sort Radix Sort Counting Sort 👍 6495 👎 798
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void quicksort(vector<int> &nums, int l, int r) {
        if (l >= r) return;
        int x = nums[l], i = l - 1, j = r + 1;
        while (i < j) {
            do ++i;while (nums[i] < x);
            do --j;while (nums[j] > x);
            if (i < j) swap(nums[i], nums[j]);
        }
        quicksort(nums, l, j);
        quicksort(nums, j + 1, r);
    }

    vector<int> sortArray(vector<int> &nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
