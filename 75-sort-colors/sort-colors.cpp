class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int n: nums) {
            freq[n]++;
        }
        nums.clear();
        for(int i=0;i < 3;i++) {
            for(int j=0;j<freq[i];j++) {
                nums.push_back(i);
            }
        }
    }
};