class Solution {
public:
    int reverse(int x) {
        int ans=0;
        //cout<<2147483648/10<<endl;
        bool neg_x=false;
        if(x<0) {
            neg_x=true;
            if(x>-2147483648)
            {
                x*=-1;
            }
        }
        bool ch=false;
        while(x>0) {   
            if(ans>=2147483648/10)
            {
                if(ans==2147483648/10 && x<2147483648%10 && x>=0)
                {
                    ans=ans*10;
                    ans+=(x%10);
                    x/=10;
                    return (neg_x)?-ans:ans;
                }
                ans=0;
                return ans;
            }
            ans=ans*10;
            ans+=(x%10);
            x/=10;
        }
        return (neg_x)?-ans:ans;
    }
};