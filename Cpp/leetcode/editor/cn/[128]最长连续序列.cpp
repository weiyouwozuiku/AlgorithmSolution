//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 
//
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// 
//
// Related Topics 并查集 数组 哈希表 👍 2035 👎 0

#include <vector>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> hash(nums.begin(), nums.end());
        int len = 0;
        for (auto x: nums) {
            int tmp = 1;
            // 只处理数据段中的第一个,非第一个直接跳过
            if (hash.find(x - 1) == hash.end()) {
                while (hash.find(++x) != hash.end()) tmp += 1;
            }
            len = max(tmp, len);
        }
        return len;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
