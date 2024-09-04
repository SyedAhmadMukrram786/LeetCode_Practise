class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++) {
            bool ch=false;
            for(int j=0;j<s.size();j++) {
                if(i!=j && s[i]==s[j]) {
                    ch=true;
                    break;
                }
            }
            if(!ch) {
                return i;
            }
        }
        return -1;
    }
};