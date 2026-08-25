class Solution {
public:

    bool isValid(int n, vector<int>& quantities, int maxAllowed) {

        int stores = 0;

        for (int q : quantities) {

            stores += (q + maxAllowed - 1) / maxAllowed;

            if (stores > n) {
                return false;
            }
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int st = 1;
        int end = *max_element(quantities.begin(), quantities.end());

        int ans = end;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (isValid(n, quantities, mid)) {

                ans = mid;
                end = mid - 1;

            } else {

                st = mid + 1;
            }
        }

        return ans;
    }
};