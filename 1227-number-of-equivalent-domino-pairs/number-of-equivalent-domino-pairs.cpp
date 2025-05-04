class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count[100] = {0}, ans = 0;
        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            int key = a < b ? a * 10 + b : b * 10 + a;
            ans += count[key]++;
        }
        return ans;
    }
};