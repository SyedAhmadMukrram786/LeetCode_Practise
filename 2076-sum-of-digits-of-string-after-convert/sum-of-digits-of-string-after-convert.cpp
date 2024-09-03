class Solution {
public:
    int getLucky(string s, int k) {
        int i=0;
        string ne;
        while(i<s.size()) {
            ne+=to_string(s[i]-96);
            i++;
        }
        int sum;
        for(int j=0;j<k;j++) {
            sum=0;
            i=0;
            while(i<ne.size()) {
                sum+=ne[i]-'0';
                i++;
            }
            ne=to_string(sum);
        }
        return sum;
    }
};