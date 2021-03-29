//
// Created by king on 2021/3/27.
//

class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int n=0;
        for(auto p=pListHead;p;p=p->next) n++;
        int step=n-k;
        if(step<0) return NULL;
        else{
            while(step--)pListHead=pListHead->next;
        }
        return pListHead;
    }
};