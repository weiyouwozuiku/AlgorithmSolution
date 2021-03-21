/*
 * @lc app=leetcode.cn id=4 lang=java
 *
 * [4] 寻找两个有序数组的中位数
 */
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1=nums1.length;
        int len2=nums2.length;
        // 处理nums1为空的情况
        if (nums1 == null || len1 == 0) {
            int index = len2 / 2;
            return len2 % 2 == 0 ? (nums2[index] + nums2[index - 1]) / 2.0 : nums2[index];
        }
        // 处理nums2为空的情况
        if (nums2 == null || len2 == 0) {
            int index = len1 / 2;
            return len1 % 2 == 0 ? (nums1[index] + nums1[index - 1]) / 2.0 : nums1[index];
        }
        // 由于采用的是二分法，所以优先处理短的数组
        // 假定num1数组较短
        if (len2<len1) {
            int[] temp=nums2;
            nums2=nums1;
            nums1=temp;
            len1=nums1.length;
            len2=nums2.length;
        }
        // 定位中位数的位置，便于将两个数组进行划分
        int half=(len1+len2+1)/2;
        boolean even=(len1+len2)%2==0;
        int start=0,end=len1,apart=0,bpart=0;
        while (start<=end) {
            // 每次循环更新两个数组的拆分位置
            apart=(start+end)/2;
            bpart=half-apart;
            if (apart>start&&nums1[apart-1]>nums2[bpart]){
                end=apart-1;
            }else if (apart<end&&nums1[apart]<nums2[bpart-1]) {
                start=apart+1;
            }else{
                int leftMax=0;
                // 下面两个是数组没有重合的情况
                // A数组中最小的数都大于B中的最大的数时
                if (apart==0) {
                    leftMax=nums2[bpart-1];
                }
                // B数组中最小的都比A中的大时
                else if (bpart==0) {
                    leftMax=nums1[apart-1];
                }
                else{
                    leftMax=Math.max(nums1[apart-1], nums2[bpart-1]);
                }
                // 如长度为奇数，此时直接返回leftMax即可
                if(!even){
                    return leftMax;
                }
                int rightMin=0;
                if(apart==len1){
                    rightMin=nums2[bpart];
                }else if(bpart==len2){
                    rightMin=nums1[apart];
                }else{
                    rightMin=Math.min(nums2[bpart], nums1[apart]);
                }
                return (leftMax+rightMin)/2.0;
            }
        }
        return 0;
    }
}
