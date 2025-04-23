class Solution {
public:
    bool isValid(string s) {
        stack<char> a;  // Use char, not int

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                a.push(c);
            } else {
                if (a.empty()) return false;

                char top = a.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    a.pop();
                } else {
                    return false;
                }
            }
        }

        return a.empty();
    }
};
