class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        int ans = 0;
        bool middleUsed = false;

        for (auto& [word, count] : freq) {
            string rev = {word[1], word[0]};
            if (word == rev) {
                int pairs = count / 2;
                ans += pairs * 4;
                freq[word] -= pairs * 2;
                if (!middleUsed && freq[word] > 0) {
                    ans += 2;
                    middleUsed = true;
                }
            } else if (freq.find(rev) != freq.end()) {
                int pairs = min(freq[word], freq[rev]);
                ans += pairs * 4;
                freq[word] -= pairs;
                freq[rev] -= pairs;
            }
        }

        return ans;
    }
};