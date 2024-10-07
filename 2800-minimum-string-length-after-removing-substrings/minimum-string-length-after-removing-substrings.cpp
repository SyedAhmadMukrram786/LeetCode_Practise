class Solution {
public:
    int minLength(string s) {
        string s1="AB",s2="CD";
        while(true) {
            size_t pos = s.find(s1);
            size_t pos1 = s.find(s2);
            if (pos != string::npos) {
                s.erase(pos, s1.length());
            }
            else if (pos1 != string::npos) {
                s.erase(pos1, s2.length());
            }
            if(pos==18446744073709551615 && pos1==18446744073709551615)
            {
                break;
            }
        }
        return s.length();
    }
};