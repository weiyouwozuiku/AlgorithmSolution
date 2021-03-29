//实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
// 
// 
// 
// BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出
//。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。 
// boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。 
// int next()将指针向右移动，然后返回指针处的数字。 
// 
//
// 注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。 
// 
// 
//
// 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。 
//
// 
//
// 示例： 
//
// 
//输入
//["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext
//", "next", "hasNext"]
//[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
//输出
//[null, 3, 7, true, 9, true, 15, true, 20, false]
//
//解释
//BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
//bSTIterator.next();    // 返回 3
//bSTIterator.next();    // 返回 7
//bSTIterator.hasNext(); // 返回 True
//bSTIterator.next();    // 返回 9
//bSTIterator.hasNext(); // 返回 True
//bSTIterator.next();    // 返回 15
//bSTIterator.hasNext(); // 返回 True
//bSTIterator.next();    // 返回 20
//bSTIterator.hasNext(); // 返回 False
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 105] 内 
// 0 <= Node.val <= 106 
// 最多调用 105 次 hasNext 和 next 操作 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以设计一个满足下述条件的解决方案吗？next() 和 hasNext() 操作均摊时间复杂度为 O(1) ，并使用 O(h) 内存。其中 h 是树的高
//度。 
// 
// Related Topics 栈 树 设计 
// 👍 425 👎 0


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
class BSTIterator {
public:
    //构造栈，将根节点的左节点循环加入栈中，以此寻找相应子树的节点
    BSTIterator(TreeNode* root) {
        while (root){
            stk.push(root);
            root=root->left;
        }
    }

    //获取当前节点的信息。如果该节点存在右节点将右节点下的左节点压入栈中
    int next() {
        auto p=stk.top();
        stk.pop();
        int val=p->val;
        p=p->right;
        while(p){
            stk.push(p);
            p=p->left;
        }
        return val;
    }

    //检测是否还有元素没有遍历只需检测栈中是否还有节点
    bool hasNext() {
        return stk.size();
    }

private:
    //使用栈存储节点信息
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//leetcode submit region end(Prohibit modification and deletion)
