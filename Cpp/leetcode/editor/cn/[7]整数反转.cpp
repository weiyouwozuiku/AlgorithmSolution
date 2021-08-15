//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。 
//
// 如果反转后整数超过 32 位的有符号整数的范围 [−231, 231 − 1] ，就返回 0。 
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
// 
//
// 示例 1： 
//
// 
//输入：x = 123
//输出：321
// 
//
// 示例 2： 
//
// 
//输入：x = -123
//输出：-321
// 
//
// 示例 3： 
//
// 
//输入：x = 120
//输出：21
// 
//
// 示例 4： 
//
// 
//输入：x = 0
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// -231 <= x <= 231 - 1 
// 
// Related Topics 数学 
// 👍 2991 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Tip：
 * Cpp中取余运算不同于数学中的取模，整数取余为整数，负数取余为负数
 * 这题使用long long就不需要考虑数据越界问题，直接比较生成数字是否越界即可
 * 但如果使用int，需要先判断给定的数是否越界。如果越界直接返回为0
 * 假定r是返回的反转数字，x是传入的原数字
 * 举例： 如果是正数越界，此时10*r+x%10>INT_MAX,进行不等式变换，可以得到r>(INT_MAX-x%10)/10
 * 即满足上述条件时，获得的反转数越界，可以直接返回0
 * 负数借助Cpp中取余的特性同理可得。
 *
 * long long的写法如下：
 */
// class Solution {
//public:
//    int reverse(int x) {
//        long long r=0;
//        while(x){
//            r=r*10+x%10;
//            x/=10;
//        }
//        if(r>INT_MAX) return 0;
//        if(r<INT_MIN) return 0;
//        return r;
//    }
//};

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res > 0 && res > (INT_MAX - x % 10) / 10) return 0;
            if (res < 0 && res < (INT_MIN - x % 10) / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
