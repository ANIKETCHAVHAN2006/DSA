class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& current, 
                   vector<vector<int>>& result) {
        // Base case: found a valid combination
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Pruning: if remaining numbers aren't enough to reach size k, stop
        // need (k - current.size()) more numbers, available = n - i + 1
        for (int i = start; i <= n - (k - current.size()) + 1; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

    
};