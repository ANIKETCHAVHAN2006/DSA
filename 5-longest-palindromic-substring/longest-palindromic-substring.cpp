class Solution {
public:
    //TC(0(n^3)) SC(0(1))

    // bool isPalin(string &s, int i , int j){
    //     while(i <= j){
    //         if(s[i++] != s[j--]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // string longestPalindrome(string s) {
    //     int n = s.length();
    //     if(n == 1 || n ==0){
    //         return s;
    //     }
    //     int maxInLow = 0;
    //     int maxInHigh = 0 ;
    //     int maxLength = 0;
    //     for(int i = 0; i < n ; i++){
    //         for(int j = i; j < n ; j++){
    //             if(isPalin(s,i,j)){
    //                 if(maxLength <= j - i + 1){
    //                     maxLength = j - i + 1;
    //                     maxInLow = i;
    //                     maxInHigh = j;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(maxInLow, maxLength);
    // }

    //TC(0(n^2)) SC(0(1)) //Sliding window

    string longestPalindrome(string s) {
        int n = s.length();

        if (n <= 1)
            return s;

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int l = i, r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLength) {
                    start = l;
                    maxLength = r - l + 1;
                }

                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLength) {
                    start = l;
                    maxLength = r - l + 1;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, maxLength);
    }
};