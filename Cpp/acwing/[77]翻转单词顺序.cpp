//
// Created by king on 2021/3/30.
//

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            int j=i+1;
            while(s[j]!=' '&&j<s.size()) j++;
            reverse(s.begin()+i,s.begin()+j);
            i=j;
        }
        return s;
    }
};