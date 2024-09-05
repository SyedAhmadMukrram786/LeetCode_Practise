class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=0;
        while(true)
        {
            if(pow(2,i)==n)
            {
                return true;
            }
            else if(pow(2,i)>n)
            {
                return false;
            }
            i++;
        }
    }
};