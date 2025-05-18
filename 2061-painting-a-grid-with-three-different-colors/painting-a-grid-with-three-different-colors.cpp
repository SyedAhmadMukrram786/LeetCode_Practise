class Solution {
public:
    int colorTheGrid(int m, int n) {
        const int MOD = 1e9 + 7;
        vector<string> validColumns;
        string current;
        generateValidColumns(m, current, validColumns);
        
        int k = validColumns.size();
        unordered_map<string, vector<string>> transitions;
        for (const string &col1 : validColumns) {
            for (const string &col2 : validColumns) {
                bool valid = true;
                for (int i = 0; i < m; ++i) {
                    if (col1[i] == col2[i]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    transitions[col1].push_back(col2);
                }
            }
        }
        
        unordered_map<string, int> dpPrev;
        for (const string &col : validColumns) {
            dpPrev[col] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            unordered_map<string, int> dpCurr;
            for (const auto &entry : dpPrev) {
                const string &col = entry.first;
                int count = entry.second;
                for (const string &nextCol : transitions[col]) {
                    dpCurr[nextCol] = (dpCurr[nextCol] + count) % MOD;
                }
            }
            dpPrev = dpCurr;
        }
        
        int result = 0;
        for (const auto &entry : dpPrev) {
            result = (result + entry.second) % MOD;
        }
        return result;
    }
    
private:
    void generateValidColumns(int m, string &current, vector<string> &validColumns) {
        if (current.size() == m) {
            validColumns.push_back(current);
            return;
        }
        for (char c : {'R', 'G', 'B'}) {
            if (current.empty() || current.back() != c) {
                current.push_back(c);
                generateValidColumns(m, current, validColumns);
                current.pop_back();
            }
        }
    }
};