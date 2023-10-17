class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        int i = 0, j = 0, minLen = INT_MAX, start = 0, counter = t.size();
        string ans = "";

        // Initialize the frequency map for string t
        for (char ch : t)
            mp2[ch]++;

        while (j < s.size()) {
            // If the current character in s is in t, decrement its count in mp1
            if (mp2.find(s[j]) != mp2.end()) {
                if (mp1[s[j]] < mp2[s[j]]) {
                    counter--;
                }
                mp1[s[j]]++;
            }

            // Check if the window contains all characters of t
            while (counter == 0) {
                // Update the minimum window length
                if (minLen > (j - i + 1)) {
                    minLen = j - i + 1;
                    start = i;
                }

                // Move the left pointer to the right to find a smaller window
                if (mp2.find(s[i]) != mp2.end()) {
                    mp1[s[i]]--;
                    if (mp1[s[i]] < mp2[s[i]]) {
                        counter++;
                    }
                }
                i++;
            }
            j++;
        }

        // If no valid window is found, return an empty string
        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
