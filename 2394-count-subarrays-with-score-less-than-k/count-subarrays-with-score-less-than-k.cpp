class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long sum = 0;
        int start = 0;
        
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];

            while (sum * (end - start + 1) >= k) {
                sum -= nums[start];
                start++;
            }

            ans += (end - start + 1);
        }
        
        return ans;
    }
};
