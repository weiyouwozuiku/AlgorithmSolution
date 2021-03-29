//
// Created by king on 2021/3/29.
//

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        if(!p) return nullptr;
        if(p->right){
            p=p->right;
            while(p->left)
                p=p->left;
            return p;
        }else{
            while(p->father&&p->father->right==p) p=p->father;
            return p->father;
        }
    }
};