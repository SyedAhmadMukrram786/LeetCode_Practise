class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> fr;
        int ans=0;
        for(char n: s)
        {
            fr[n]++;
        }
        bool ch=false,ch1=false;
        for(auto &p : fr) {
            if(!ch && (p.second==1))
            {
                ch=true;
                ans += p.second;
            }
            else if(p.second%2==0)
            {
                ans += p.second;
            }
            else if(p.second!=1 && p.second%2!=0)
            {
                ch1=true;
                ans += p.second-1;
            }
            cout<<p.second<<endl;
        }
        if(ch1 && !ch)
        {
            ans++;
        }
        return ans;
    }
};