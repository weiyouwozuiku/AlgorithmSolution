/*
 * @lc app=leetcode.cn id=9 lang=java
 *
 * [9] 回文数
 */
class Solution {
    public boolean isPalindrome_1(int x) {
        String str=Integer.toString(x);
        int len=str.length();
        int i=0;
        while (i<len/2) {
            if (str.charAt(i)!=str.charAt(len-i-1)) {
                return false;
            }
            i++;
        }
        return true;

    }
    
    public boolean isPalindrome(int x) {
        // 判断是否为负数或者非0且最后一位为0的情况
        if (x<0||(x!=0&&x%10==0)) {
            return false;
        }
        int res=0;
        // 取x的一半或者一半长度
        while (x>res) {
            res=res*10+x%10;
            x/=10;
        }
        return (x==res||x==res/10);
    }
}

