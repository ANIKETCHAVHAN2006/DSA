class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n = nums1.size() , m = nums2.size() ;
      vector<double>nums(n+m) ;
      int idx = 0 , i = 0 , j = 0 ;
      while(i < n && j < m){
        if(nums1[i] < nums2[j]){
            nums[idx++] = nums1[i++] ;
        }
        else{
            nums[idx++] = nums2[j++] ;
        }
      } 
      while(i < n){
         nums[idx++] = nums1[i++] ;
      }
      while(j < m){
         nums[idx++] = nums2[j++] ;
      }
      if((nums.size())%2 == 1){
        return nums[(nums.size())/2] ;
      }else{
        return ((nums[(nums.size())/2]+nums[(nums.size())/2-1])/2) ;
      }
    }
};