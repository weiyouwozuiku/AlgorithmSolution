//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[20,9],[15,7]]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：[[1]]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 2000] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 广度优先搜索 二叉树 👍 737 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 本题的思路和二叉树层序遍历一致，只是在每隔一层反转level中的元素
class Solution {
public:
    vector <vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector <vector<int>> res;
        queue < TreeNode * > q;
        if (root) q.push(root);
        else return {};
        bool flag = false;
        while (q.size()) {
            int size = q.size();
            vector<int> level;
            while (size--) {
                auto p = q.front();
                q.pop();
                level.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            if (flag) reverse(level.begin(), level.end());
            res.push_back(level);
            flag = !flag;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
