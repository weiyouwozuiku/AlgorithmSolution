//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。 
//
// 
//
// 示例: 
//
// 给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]
// 
// Related Topics 数组 哈希表 
// 👍 9509 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        //heap中的键存放数组元素，值存放数组元素的索引
        unordered_map<int, int> heap;
        for (int i = 0; i < nums.size(); i++) {
            int re=target-nums[i];
            if(heap.count(re)) return {heap[re],i};
            heap[nums[i]]=i;
        }
        return {};
    }
};
//leetcode submit region end(Prohibit modification and deletion)
