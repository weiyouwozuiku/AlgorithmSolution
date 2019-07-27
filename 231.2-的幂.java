/*
 * @lc app=leetcode.cn id=231 lang=java
 *
 * [231] 2的幂
 */
class Solution {
    public boolean isPowerOfTwo(int n) {
        // 2的幂的数在二进制上显示为以1为开头，其后都是0
        // 根据这一特点，2的幂的数和比其小1的数进行与运算，答案应该为0
        if (n<=0) {
            return false;
        }
        return (n&(n-1))==0;
    }
}

