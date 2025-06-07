class Solution {
public:
    string robotWithString(string s) {
        stack<char> stk;
        string t = "";
        vector<int> frq(26);

        for (char ch : s) {
            frq[ch - 'a']++;
        }

        for (char ch : s) {
            stk.push(ch);
            frq[ch - 'a']--;

            while (!stk.empty() && stk.top() <= lexico(frq)) {
                t += stk.top();
                stk.pop();
            }
        }

        while (!stk.empty()) {
            t += stk.top();
            stk.pop();
        }

        return t;
    }
    char lexico(vector<int>& freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i]) return 'a' + i;
        }
        return 'a';
    }
};