class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.length();
        unordered_map<char, int> mp;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (mp.find(s[right]) != mp.end()) {
                // If the character is repeated, move the left pointer to the right of the previous occurrence.
                left = max(left, mp[s[right]] + 1);
            }
            mp[s[right]] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
