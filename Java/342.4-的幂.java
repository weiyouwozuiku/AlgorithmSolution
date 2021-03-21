/*
 * @lc app=leetcode.cn id=342 lang=java
 *
 * [342] 4的幂
 */
class Solution {
    public boolean isPowerOfFour(int num) {
        // 使用num&num-1判断是否是2的幂
        // 使用num&0x55555555将非4的幂去除
        if (num<=0) {
            return false;
        }
        return (num&(num-1))==0&&(num&0x55555555)!=0;
    }
}

