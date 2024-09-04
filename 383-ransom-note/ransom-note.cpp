class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool ch;
        for(int i=0;i<ransomNote.size();i++)
        {
            ch=false;
            for(int j=0;j<magazine.size();j++)
            {
                if(magazine[j]==ransomNote[i])
                {
                    magazine[j]=-1;
                    ch=true;
                    break;
                }
            }
            if(!ch)
            {
                return false;
            }
        }
        if(ch)
        {
            return true;
        }
        return false;
    }
};