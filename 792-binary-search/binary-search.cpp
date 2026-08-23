class Solution {
public:
     int binSearch(vector<int>& nums, int target,int st , int end) {
        int mid = st + (end - st)/2 ;
        if(st <= end){
        if(nums[mid] == target){
            return mid ;
        }
        if(nums[mid] <= target){ //2nd half
           return binSearch(nums , target , mid + 1 , end);
        }
        else{
            return binSearch(nums , target , st , mid - 1);
        }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
         return binSearch(nums,target ,0 ,nums.size()-1);
    }
};