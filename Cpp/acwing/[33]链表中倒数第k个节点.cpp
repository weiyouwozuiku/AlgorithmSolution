//
// Created by king on 2021/3/27.
//

class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        if(!pListHead) return NULL;
        int len=0;
        for(auto p=pListHead;p;p=p->next) len+=1;
        if(k>len)return NULL;
        else{
            auto p=pListHead;
            for(int i=0;i<len-k;i++) p=p->next;
            return p;
        }
    }
};