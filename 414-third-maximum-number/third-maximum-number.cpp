class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        set<int> uniqueNums(nums.begin(), nums.end());

        
        vector<int> distinctNums(uniqueNums.begin(), uniqueNums.end());

        
        sort(distinctNums.rbegin(), distinctNums.rend());

        
        if (distinctNums.size() >= 3) {
            return distinctNums[2]; 
        } else {
            return distinctNums[0]; 
        }
    }
};
