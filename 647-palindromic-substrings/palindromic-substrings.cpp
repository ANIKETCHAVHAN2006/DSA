class Solution {
public:
    // bool isPalin(string &s, int i, int j){
    //     while(i<=j){
    //       if(s[i++] != s[j--]){
    //         return false;
    //       }
    //     }
    //     return true;
    // }
    // int countSubstrings(string s) {
    //     int n = s.length();
    //     int count = 0;
    //     for(int i = 0; i < n ; i++){
    //         for(int j = i; j<n;j++){
    //             if(isPalin(s,i,j)){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }

     int expand(string &s, int l, int r) {
        int count = 0;

        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }

        return count;
    }

    int countSubstrings(string s) {
        int count = 0;

        for(int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            count += expand(s, i, i);

            // Even length palindrome
            count += expand(s, i, i + 1);
        }

        return count;
    }
};