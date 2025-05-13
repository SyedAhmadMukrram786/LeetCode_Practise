class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> count(26, 0);

        for (char c : s)
            count[c - 'a']++;

        for (int i = 0; i < t; ++i) {
            vector<long long> next(26, 0);

            for (int j = 0; j < 25; ++j) {
                next[j + 1] = count[j] % MOD;
            }
            next[0] = (next[0] + count[25]) % MOD; 
            next[1] = (next[1] + count[25]) % MOD; 

            count = next;
        }

        long long totalLength = 0;
        for (int i = 0; i < 26; ++i)
            totalLength = (totalLength + count[i]) % MOD;

        return static_cast<int>(totalLength);
    }
};