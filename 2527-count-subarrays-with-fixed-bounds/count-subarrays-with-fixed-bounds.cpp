class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastMin = -1, lastMax = -1, lastInvalid = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK)
                lastInvalid = i;

            if (nums[i] == minK)
                lastMin = i;
            if (nums[i] == maxK)
                lastMax = i;

            ans += max(0, min(lastMin, lastMax) - lastInvalid);
        }

        return ans;
    }
};