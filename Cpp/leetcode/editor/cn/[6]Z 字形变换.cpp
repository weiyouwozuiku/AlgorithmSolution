//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。 
//
// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下： 
//
// 
//P   A   H   N
//A P L S I I G
//Y   I   R 
//
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。 
//
// 请你实现这个将字符串进行指定行数变换的函数： 
//
// 
//string convert(string s, int numRows); 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
// 
//示例 2：
//
// 
//输入：s = "PAYPALISHIRING", numRows = 4
//输出："PINALSIGYAHRPI"
//解释：
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
// 
//
// 示例 3： 
//
// 
//输入：s = "A", numRows = 1
//输出："A"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 由英文字母（小写和大写）、',' 和 '.' 组成 
// 1 <= numRows <= 1000 
// 
// Related Topics 字符串 
// 👍 1232 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * 本题的解题思路：
 * 这道题本质上是一个找规律的题目，Z字变换指的是字符串的打印不是横着，而是横着的Z的结构进行打印
 * 本题共有三种情况进行分别考虑，n表示Z字变换的行数：
 * 1. 观察第一行与最后一行可知，其都是以2n-2为公差的等差数列
 * 2. 观察中间的行数可知，可以将打印的字符分为垂直和倾斜的两种数组的交替数组，且这两个数组依旧是以2n-2为公差的等差数组，
 *    而垂直与倾斜的二者之间存在这这样的约束关系：两两之间其和为2n-2
 * 3. 当2n-2中的n为1是，2n-2==0,会陷入死循环，因此将n==1的情况进行特判
 */

class Solution {
public:
    string convert(string s, int numRows) {
        //避免出现n==1导致的2n-2==0的出现进行特判
        if (numRows == 1) return s;
        string res;
        for (int i = 0; i < numRows; i++) {
            //首行或末行的情况
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < s.size(); j += 2 * numRows - 2) res += s[j];
            } else {
                //中间行的情况
                for (int j = i, k = 2 * numRows - 2 - i; j < s.size() || k < s.size(); j += 2 * numRows - 2, k += 2 * numRows - 2) {
                    if (j < s.size()) res += s[j];
                    if (k < s.size()) res += s[k];
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
