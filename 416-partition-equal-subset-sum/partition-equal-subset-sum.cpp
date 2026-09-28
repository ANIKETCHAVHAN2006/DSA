class Solution {
public:
    vector<vector<int>> dp;  // -1 = unvisited, 0 = false, 1 = true

bool helper(vector<int>& nums, int index, int target) {
    if (target == 0) return true;
    if (index >= nums.size() || target < 0) return false;

    if (dp[index][target] != -1) return dp[index][target];

    bool take = helper(nums, index + 1, target - nums[index]);
    bool skip = helper(nums, index + 1, target);

    return dp[index][target] = (take || skip);
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int x : nums) sum += x;

    if (sum % 2 != 0) return false;

    int target = sum / 2;
    dp.assign(nums.size(), vector<int>(target + 1, -1));

    return helper(nums, 0, target);
}
};