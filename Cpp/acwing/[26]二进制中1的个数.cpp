//
// Created by king on 2021/4/19.
//

class Solution {
public:
    int NumberOf1(int n) {
        int res=0;
        while(n) n-=n&-n,res+=1;
        return res;
    }
};