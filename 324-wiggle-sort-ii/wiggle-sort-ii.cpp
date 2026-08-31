class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int l = (n - 1) / 2;  // end of smaller half
        int r = n - 1;        // end of larger half

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = temp[l--];
            }
            else {
                nums[i] = temp[r--];
            }
        }
    }
};