class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=0;
        while(true)
        {
            long long int t=pow(3,i);
            i++;
            if(t==n)
            {
                return true;
            }
            else if(t>n)
            {
                return false;
            }
        }
    }
};