class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0;
        int gainCount = 0;
        int minGain = INT_MAX;

        for (int num : nums) {
            int xorVal = num ^ k;
            int gain = xorVal - num;
            total += num;
            if (gain > 0) {
                gainCount++;
                total += gain;
                minGain = min(minGain, gain);
            } else {
                minGain = min(minGain, -gain);
            }
        }

        if (gainCount % 2 == 0) {
            return total;
        } else {
            return total - minGain;
        }
    }
};
