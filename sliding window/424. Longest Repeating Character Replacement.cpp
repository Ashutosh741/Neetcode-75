class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0, j = 0,maxi = 0,maxFreq = 0;
        unordered_map<char,int>mp;

        while(j < n){
            mp[s[j]]++;
             maxFreq = max(maxFreq,mp[s[j]]);
            if(j-i+1 - maxFreq > k){
                mp[s[i]]--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};
