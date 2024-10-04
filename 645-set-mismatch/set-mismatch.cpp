class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> n;
        unordered_map<int,int> fr;
        for(int k:nums)
        {
            fr[k]++;
            if(fr[k]>1)
            {
                n.push_back(k);
                break;
            }
        }
        bool ch1=false;
        for(int i=0;i<nums.size();i++){
            ch1=false;
            for(int j=0;j<nums.size();j++) {
                if(i+1==nums[j]) {
                    ch1=true;
                    break;
                }
            }
            if(!ch1) {
                n.push_back(i+1);
                return n;
            }
        }
        return n;
    }
};