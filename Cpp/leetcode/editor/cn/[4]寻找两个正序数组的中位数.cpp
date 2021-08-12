//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 示例 3： 
//
// 
//输入：nums1 = [0,0], nums2 = [0,0]
//输出：0.00000
// 
//
// 示例 4： 
//
// 
//输入：nums1 = [], nums2 = [1]
//输出：1.00000
// 
//
// 示例 5： 
//
// 
//输入：nums1 = [2], nums2 = []
//输出：2.00000
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -106 <= nums1[i], nums2[i] <= 106 
// 
//
// 
//
// 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？ 
// Related Topics 数组 二分查找 分治 
// 👍 4349 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        if (total % 2 == 0) {
            int left = findKthNumber(nums1, 0, nums2, 0, total / 2);
            int right = findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        } else {
            //注意这里是totle/2+1
            return findKthNumber(nums1, 0, nums2, 0, total / 2 + 1);
        }
    }

    int findKthNumber(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        /**保证nums1数组的长度小于nums2,如果不是则反转过来。
         * 这样操作的原因在于可以减少考虑的情况。
         * 如果不约定nums1的长度小于nums2,需要考虑三种情况：
         * 1. n,m>=k/2
         * 2. m<k/2
         * 3. n<k/2
         * 约定后只需要考虑两种情况
         * 1. n,m>=k/2
         * 2. m<k/2
         */
        if (nums1.size() - i > nums2.size() - j) return findKthNumber(nums2, j, nums1, i, k);
        //这个判断需要放在k==1之前操作，因为i可能会在nums1中越界。这里判断的是nums1中没有数字的情况
        if (nums1.size() == i) return nums2[j + k - 1];
        if (k == 1) return min(nums1[i], nums2[j]);
        //因为这里保证了nums1小于nums2中需要考虑元素的数量，因此存在nums2中的数字远多于nums1中的数字，直接使用i+k/2会导致超过nums1中元素的数量。
        //因此需要使用min()保证不越界,这里与nums1.size()比较是因为i在不断增大，不能使用nums1.size()-k/2
        //这里的si和sj分别表示在nums1和nums2数组中第k/2位置的后一位。因此在后面比较的时候需要-1。
        int si = min(i + k / 2, int(nums1.size())), sj = j + k / 2;
        //舍去无用子数组
        if (nums1[si - 1] > nums2[sj - 1]) {
            return findKthNumber(nums1, i, nums2, sj, k - (sj - j));
        } else {
            return findKthNumber(nums1, si, nums2, j, k - (si - i));
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
