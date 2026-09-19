class Solution {
public:
    bool isPalin(string &s, int i, int j){
        while(i<=j){
          if(s[i++] != s[j--]){
            return false;
          }
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n ; i++){
            for(int j = i; j<n;j++){
                if(isPalin(s,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};