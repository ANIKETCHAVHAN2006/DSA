class Solution {
public:
    // int minimum(vector<int>& arr, int l, int r) {
//     if (l == r) return arr[l];
//     int mid = l + (r - l) / 2;
//     if (arr[mid] > arr[r]) {
//         return minimum(arr, mid + 1, r);
//     } else {
//         return minimum(arr, l, mid);
//     }
// }

    int minimum(vector<int>& arr, int l, int r) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > arr[r]) {
                // min must be in the right half, mid itself can't be it
                l = mid + 1;
            } else {
                // arr[mid] <= arr[r]: min is in [l, mid]
                r = mid;
            }
        }
        return arr[l];
    }

    int findMin(vector<int>& nums) {
        return minimum(nums, 0, nums.size() - 1);
    }
};

