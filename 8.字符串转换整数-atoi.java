/*
 * @lc app=leetcode.cn id=8 lang=java
 *
 * [8] 字符串转换整数 (atoi)
 */
class Solution {
    public int myAtoi(String str) {
        int leng = 0;
        boolean flag[] = { false, false, false,false };
        boolean nag = false;
        int len = str.length();
        int i = 0;
        long ans = 0;
        while (i < len) {
            if (str.charAt(i) == ' ' && !flag[2]) {
                i++;
            } else if (str.charAt(i) == '-' && !flag[2]) {
                flag[1] = true;
                i++;
                flag[2] = true;
            } else if (str.charAt(i) == '+' && !flag[2]) {
                flag[0] = true;
                i++;
                flag[2] = true;
            }else if (str.charAt(i)=='0'&&!flag[3]) {
                i++;
                flag[2] = true;
            }else if (str.charAt(i) <= '9' && str.charAt(i) >= '0') {
                ans = ans * 10 + str.charAt(i) - '0';
                i++;
                leng++;
                flag[2] = true;
                flag[3]=true;
            } else {
                break;
            }
        }
        if (flag[1] && (!flag[0])) {
            ans = -ans;
            nag = true;
        }
        if (flag[0] && flag[1]) {
            return 0;
        }
        if (ans < Integer.MIN_VALUE || ans > Integer.MAX_VALUE || leng > 19) {
            if (nag)
                return Integer.MIN_VALUE;
            else
                return Integer.MAX_VALUE;
        }
        return (int) ans;
    }
}
