class Solution {
public:
    bool IsValid(vector<vector<int>>& grid , int r , int c , int n , int expVal){
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal){
            return false ;
        }
        if(expVal == n*n-1){
            return true ;
        }

        //8 POSSIBLE MOVES
        int ans1 = IsValid(grid , r - 2 , c + 1 , n , expVal + 1) ;
        int ans2 = IsValid(grid , r - 1 , c + 2 , n , expVal + 1) ;
        int ans3 = IsValid(grid , r + 1 , c + 2 , n , expVal + 1) ;
        int ans4 = IsValid(grid , r + 2 , c + 1 , n , expVal + 1) ;
        int ans5 = IsValid(grid , r + 2 , c - 1 , n , expVal + 1) ;
        int ans6 = IsValid(grid , r + 1 , c - 2 , n , expVal + 1) ;
        int ans7 = IsValid(grid , r - 1 , c - 2 , n , expVal + 1) ;
        int ans8 = IsValid(grid , r - 2 , c - 1 , n , expVal + 1) ;

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8 ;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return IsValid(grid , 0 , 0 , grid.size() , 0) ;
    }
};