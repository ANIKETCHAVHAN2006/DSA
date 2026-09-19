class Solution {
public:
    bool isPalin(string &s, int i , int j){
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1 || n ==0){
            return s;
        }
        int maxInLow = 0;
        int maxInHigh = 0 ;
        int maxLength = 0;
        for(int i = 0; i < n ; i++){
            for(int j = i; j < n ; j++){
                if(isPalin(s,i,j)){
                    if(maxLength <= j - i + 1){
                        maxLength = j - i + 1;
                        maxInLow = i;
                        maxInHigh = j;
                    }
                }
            }
        }
        return s.substr(maxInLow, maxLength);
    }
};