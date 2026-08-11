class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < row; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};