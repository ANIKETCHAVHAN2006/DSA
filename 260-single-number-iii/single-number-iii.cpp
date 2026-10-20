class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // vector<int>res;
        // unordered_map<int,int>mp;
        // for(int n : nums){
        //     mp[n]++;
        // }

        // for(auto& it : mp){
        //     if(it.second == 1){
        //         res.push_back(it.first);
        //     }
        // }
        // return res;

        int xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }

        unsigned int bits = xorAll;
        unsigned int bit = bits & (0u - bits);

        int first = 0;
        for (int num : nums) {
            if ((static_cast<unsigned int>(num) & bit) != 0) {
                first ^= num;
            }
        }

        return {first, xorAll ^ first};
    }
};