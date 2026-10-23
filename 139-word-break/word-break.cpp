// class Solution {
// public:
//     unordered_set<string> st;
//     int t[301];
//     int n;
    
//     bool solve(string &s, int idx) {
        
//         if(idx == n) {
//             return true;
//         }

//         if(st.find(s.substr( idx , n - idx )) != st.end()) {
//             return true;
//         }
        
//         if(t[idx] != -1)
//             return t[idx];
        
//         for(int l = 1; l<=n; l++) {
            
//             string temp = s.substr(idx, l);
//             if(st.find(temp) != st.end() && solve(s, idx+l))
//                 return t[idx] = true;
            
//         }
        
//         return t[idx] = false;
//     }
    
//     bool wordBreak(string s, vector<string>& wordDict) {
//         n = s.length();
        
//         memset(t, -1, sizeof(t));
        
//         for(string &word : wordDict) {
//             st.insert(word);
//         }
        
//         return solve(s, 0);
//     }
// };

class Solution {
    vector<int> memo;

    bool solve(int start, const string& s, const unordered_set<string>& words) {
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];

        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);

            if (words.count(word) && solve(end, s, words)) {
                return memo[start] = 1;
            }
        }

        return memo[start] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        memo.assign(s.size(), -1);
        return solve(0, s, words);
    }
};

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> words(wordDict.begin(), wordDict.end());
//         vector<bool> dp(s.size() + 1, false);
//         dp[0] = true;

//         for (int end = 1; end <= s.size(); ++end) {
//             for (int start = 0; start < end; ++start) {
//                 if (dp[start] && words.count(s.substr(start, end - start))) {
//                     dp[end] = true;
//                     break;
//                 }
//             }
//         }

//         return dp[s.size()];
//     }
// };