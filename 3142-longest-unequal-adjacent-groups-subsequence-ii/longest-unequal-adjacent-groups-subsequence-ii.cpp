class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1); 
        vector<int> prev(n, -1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[j] != groups[i] && words[j].size() == words[i].size()) {
                    if (hammingDistance(words[j], words[i])) {
                        if (dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            prev[i] = j;
                        }
                    }
                }
            }
        }

        int max_len = 0;
        int last_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > max_len) {
                max_len = dp[i];
                last_idx = i;
            }
        }

        vector<string> result;
        while (last_idx != -1) {
            result.push_back(words[last_idx]);
            last_idx = prev[last_idx];
        }
        reverse(result.begin(), result.end());

        return result;
    }

private:
    bool hammingDistance(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1) {
                    return false;
                }
            }
        }
        return diff == 1;
    }
};