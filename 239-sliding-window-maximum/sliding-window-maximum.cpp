class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq ;
        vector<int> res ;

        //1ST WINDOW
        for(int i = 0 ; i < k ; i++){
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){  // compare from back of window
              dq.pop_back() ;
            }
            dq.push_back(i) ;
        }
        for(int i = k ; i < nums.size() ; i++){
            res.push_back(nums[dq.front()]) ;

            //REMOVE THAT ARE NOT PART OF CURRENT WINDOW 
            while(dq.size() > 0 && dq.front() <= i - k){
                dq.pop_front() ;
            }

            //REMOVE THE SMALLER VALUE
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]){
                dq.pop_back() ;
            }
            dq.push_back(i) ;
        }
        res.push_back(nums[dq.front() ]) ;
        return res ;
    }
};