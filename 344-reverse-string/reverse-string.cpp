class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++)
        {
            swap(s[i],s[s.size()-1-i]);
            cout<<s[i];
        }
        for(int j=s.size()/2;j<s.size();j++)
        {
            cout<<s[j];
        }
    }
};