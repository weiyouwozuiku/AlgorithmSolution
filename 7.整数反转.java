/*
 * @lc app=leetcode.cn id=7 lang=java
 *
 * [7] 整数反转
 */
class Solution {
    public int reverse(int x) {
        // java中int的取值范围是[-2^31,2^31-1]
        // java中可以直接使用Integer中的常量值：Integer.MIN_VALUE和Integer.MAX_VALUE
        final int MaxInt=0x7fffffff;
        final int MinInt=0x80000000;
        long ans=0;
        while (x!=0) {
            ans=ans*10+(x%10);
            x/=10;
        }
        if (ans<MinInt||ans>MaxInt) {
            return 0;
        }
        return (int)ans;
    }
}

