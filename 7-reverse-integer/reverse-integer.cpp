class Solution {
public:
    int reverse(int x) {
        int ans=0;        
        bool neg_x=false;
        if(x<0) {
            neg_x=true;
            if(x>INT_MIN) {
                x*=-1;
            }
        }
        bool ch=false;
        while(x>0) {   
            if(ans>=INT_MAX/10)
            {
                if(ans==INT_MAX/10 && x<INT_MAX%10 && x>=0)
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