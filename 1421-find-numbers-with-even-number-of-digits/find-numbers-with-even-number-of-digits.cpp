class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for (int n : nums)
        {
            if(digitLength(n)%2==0)
                ans++;
        }
        return ans;
    }
    int digitLength(int num) {
        if (num == 0) return 1;
        return floor(log10(abs(num))) + 1;
    }
};