class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int a1 = 0, a2 = 0;
        bool a2_check = false;
        vector<int> freqValues;
        for (const auto& pair : freq) {
            freqValues.push_back(pair.second);
        }
        sort(freqValues.begin(), freqValues.end());
        for (auto it = 0; it < freqValues.size(); it++) {
            if (freqValues[it] % 2 != 0) {
                a1 = freqValues[it];
            }
            if (freqValues[it] % 2 == 0 && !a2_check) {
                a2_check = true;
                a2 = freqValues[it];
            }
        }
        return (a1 - a2);
    }
};