class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> freq;
        for (int x : nums) {
            ++freq[x];
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [value, count] : freq) {
            buckets[count].push_back(value);
        }

        vector<int> result;
        for (int count = buckets.size() - 1; count > 0 && result.size() < k; --count) {
            for (int value : buckets[count]) {
                result.push_back(value);
                if (result.size() == k) return result;
            }
        }

        return result;
    }
};