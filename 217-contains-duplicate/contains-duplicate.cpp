class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> fr;

        for (int num : nums) {
            fr[num]++;
            if(fr[num]>1)
            {
                return true;
            }
        }
        return false;
    }
};