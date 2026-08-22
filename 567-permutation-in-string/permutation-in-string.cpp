class Solution {
public:
     bool isFreqSame(int freq1[],int freq2[]){
        for(int i = 0 ; i < 26 ; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
     }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0 ; i < s1.length();i++){
            freq[s1[i]-'a']++; //idx = a->0 , b->1
        }
        int windsize = s1.length();
        for(int i = 0 ; i < s2.length() ; i++){
            int windIdx = 0 , Idx = i;
            int windFreq[26] = {0};
            while(windIdx < windsize && Idx < s2.length()){
                windFreq[s2[Idx]-'a']++;
                windIdx++ ; Idx++;
            }
            if(isFreqSame(freq,windFreq)){  //found
            return true;
            }
        }
        return false;
    }
};