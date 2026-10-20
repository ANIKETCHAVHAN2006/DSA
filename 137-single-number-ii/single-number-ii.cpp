// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> m;
        
//         for(auto x: nums){
//             m[x]++;
//         }

//         for(auto x: m){
//             if(x.second == 1){
//                 return x.first;
//             }
//         }
        
//         return -1;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            for (int num : nums) {
                unsigned int value = num;
                count += (value >> bit) & 1U;
            }

            if (count % 3 != 0) {
                result |= (1U << bit);
            }
        }

        return result;
    }
};