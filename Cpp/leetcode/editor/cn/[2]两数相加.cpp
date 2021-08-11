//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。 
//
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。 
//
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。 
//
// 示例： 
//
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
// 
// Related Topics 链表 数学 
// 👍 5230 👎 0


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //dummy节点表示结果链表。用-1作为虚拟头节点，cur表示运算过程中的执行节点
        auto dummy = new ListNode(-1), cur = dummy;
        //t存储当前位相加的值
        int t=0;
        while (l1 || l2 || t) {
            if(l1) t+=l1->val,l1=l1->next;
            if(l2) t+=l2->val,l2=l2->next;
            //记得在更新cur->next的同时，更新cur已进行下一轮运算
            cur=cur->next=new ListNode(t%10);
            t/=10;
        }
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
