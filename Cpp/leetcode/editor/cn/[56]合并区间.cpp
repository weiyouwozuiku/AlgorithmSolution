//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
// Related Topics 数组 排序 👍 1288 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        if (intervals.size() == 0) return intervals;
        vector <vector<int>> ans;
        // 所有区间按照左端点排序
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], end = intervals[0][1];
        // 排序完之后，之后出现三种情况
        for (auto item: intervals) {
            // 1. 起始点就与上一个区间没有重叠
            if (item[0] > end) {
                ans.push_back({st, end});
                st = item[0];
                end = item[1];
            } else {
                // 2. 区间结束点在当前区间之外
                if (end < item[1]) end = item[1];
                // 3. 区间结束点在当前区间内，不用处理
            }
        }
        // 将最后的区间压入ans队列
        ans.push_back({st, end});
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
