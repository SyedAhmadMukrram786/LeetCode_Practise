class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c=0;
        for(int i=0;i<words.size();i++)
        {
            bool ch=false;
            for(int j=0;j<words[i].size();j++)
            {
                ch=false;
                for(int k=0;k<allowed.size();k++)
                {
                    if(allowed[k]==words[i][j])
                    {
                        ch=true;
                        break;
                    }
                }
                if(!ch)
                {
                    break;
                }
            }
            if(ch)
            {
                c++;
            }
        }
        return c;
    }
};