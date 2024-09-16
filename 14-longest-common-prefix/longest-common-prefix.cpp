class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        for(int i=0;i<strs[0].size();i++)
        {
            bool ch=false;
            for(int j=1;j<strs.size();j++)
            {
                if(strs[0][i]!=strs[j][i])
                {
                    ch=true;
                    break;
                }
            }
            if(!ch)
            {
                s+=strs[0][i];
            }
            else
            {
                return s;
            }
        }
        return s;
    }
};