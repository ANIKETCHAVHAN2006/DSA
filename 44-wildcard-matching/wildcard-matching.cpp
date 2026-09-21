class Solution {
public:
    bool isMatch(string txt, string pat) {
         // code here
        int n = txt.size();
        int m = pat.size();
        
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        
        dp[0][0]=true;
        
        for(int j = 1 ; j<m+1 ; j++){ //0th row = txt = ""
            if(pat[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
            else{// '?' or english char
                dp[0][j] = false;
            }
        }
        
        //bottom up manner fill dp
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(txt[i-1] == pat[j-1] || pat[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pat[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};