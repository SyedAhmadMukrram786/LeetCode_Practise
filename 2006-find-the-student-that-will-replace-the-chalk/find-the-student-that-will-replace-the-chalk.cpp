class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int s=0;
        int i=0;
        for(i=0;i<chalk.size();i++)
        {
            s+=chalk[i];
        }
        i=0;
        k=k%s;
        while(true)
        {
            k-=chalk[i];
            if(k<0)
            {
                return i;
            }
            if(i==chalk.size()-1)
            {
                i=-1;
            }
            i++;
        }
        return i;
    }
};