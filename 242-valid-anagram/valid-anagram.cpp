class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[26]={0} , arr2[26]={0} ;
        for(int i = 0 ; i < s.length() ; i++){
            arr1[s[i]-'a']++ ;
        }
        for(int j = 0 ; j < t.length() ; j++){
            arr2[t[j]-'a']++ ;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(arr1[i] != arr2[i]){
                return false ;
            }
        }
        return true;
    }
};