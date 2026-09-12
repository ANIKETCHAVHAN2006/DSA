class Solution {
public:
    // long long countSubstrs(string str,int i, int j, int n, char c){
    //     if(n==1){
    //          return str[i] == c ? 1 : 0;
    //     }
    //     if(n<=0){
    //         return 0;
    //     }
    //     long long result = countSubstrs(str,i+1,j,n-1,c) + countSubstrs(str,i,j-1,n-1,c) - countSubstrs(str,i+1,j-1,n-2,c);

    //     if(str[i] == c && str[j]== c){
    //         result++;
    //     }

    //     return result;
    // }

    long long countSubstrings(string s, char c) {
    long long cnt = count(s.begin(), s.end(), c);
    return cnt + cnt * (cnt - 1) / 2;   // = cnt*(cnt+1)/2
}
};