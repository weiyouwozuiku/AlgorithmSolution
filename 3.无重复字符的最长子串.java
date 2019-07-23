import java.util.Set;

/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 * 
 * 这里使用sliding-window
 */
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s==null||s.length()==0){
            return 0;
        }
        int lo=0,hi=0;
        //排除了字符串为空的情况，那么最长子串至少为一
        int maxLen=1;
        int len=s.length();
        //利用set中不存在相同元素的特性，进行判断是否存在相同的元素
        Set<Character> set=new HashSet<>();
        for(;hi<len;hi++){
            char cur=s.charAt(hi);
            if(!set.add(cur)){
                while (lo<hi&&s.charAt(lo)!=cur){
                    set.remove(s.charAt(lo));
                    lo++;
                }
                lo+=1;
            }
            maxLen=Math.max(maxLen,hi-lo+1);
        }
        return maxLen;
    }
}

