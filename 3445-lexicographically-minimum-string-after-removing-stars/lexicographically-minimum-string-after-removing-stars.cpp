class Solution {
public:
    string clearStars(string s) {
    priority_queue<pair<char,int>, vector<pair<char,int>>, greater<pair<char,int>>> minh;
    unordered_map<int,bool> map;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                map[-minh.top().second] = true;
                minh.pop();
            } else {
                minh.push({s[i], -i});
            }
        }
        string ans;
        for(int i = 0; i < s.size(); i++) {
            if(map.count(i) || s[i] == '*') 
                continue;
            ans += s[i];
        }
        return ans;
    }
};