class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int n : nums){
            mp[n]++;
        }

        for(auto& it : mp){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};