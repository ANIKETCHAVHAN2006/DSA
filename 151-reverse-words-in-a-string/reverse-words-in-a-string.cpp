class Solution {
public:
    string reverseWords(string s) {
        int n = s.length() ;
        string ans = "" ;  //empty
        reverse(s.begin() , s.end());
        for(int i = 0 ; i < n ; i++){
            string word = "" ;  //empty
            while(i < n && s[i] != ' '){   //space
              word += s[i] ;
              i++ ;
            }
            reverse(word.begin(),word.end()); //reverse individual word
            if(word.length() > 0){
                ans += " " + word ;
            }
        }
        return ans.substr(1) ;  //index 1 to n (removing space from beginning)
    }
};