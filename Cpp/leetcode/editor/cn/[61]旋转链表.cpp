//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[4,5,1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：head = [0,1,2], k = 4
//输出：[2,0,1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 500] 内 
// -100 <= Node.val <= 100 
// 0 <= k <= 2 * 109 
// 
// Related Topics 链表 双指针 
// 👍 532 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || k == 0) return head;
        //获取链表长度
        int len = 0;
        for(auto p=head;p;p=p->next) len+=1;
        k%=len;
        //判断取余后的k是否为0,如果是直接返回
        if(!k) return head;
        else{
            //找到第n-k-1节点
            auto p=head;
            for(int i=0;i<len-k-1;i++) p=p->next;
            //找到尾节点
            auto tail=head;
            while (tail->next) tail=tail->next;
            //链接
            tail->next=head;
            head=p->next;
            p->next=NULL;
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
