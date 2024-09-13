class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i=0;i<t.size();i++)
        {
            bool ch=false;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]!='/' && t[i]==s[j])
                {
                    s[j]='/';
                    ch=true;
                    break;
                }
            }
            if(!ch)
            {
                return t[i];
            }
        }
        return 'a';
    }
};