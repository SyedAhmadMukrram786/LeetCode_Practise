class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj;

        for (int i = 0; i < n; ++i) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string ans;
        for (char ch : baseStr) {
            vector<int> vis(26, 0);
            char minChar = dfs(adj, ch, vis);
            ans.push_back(minChar);
        }

        return ans;
    }
    char dfs(unordered_map<char, vector<char>>& adj, char cur, vector<int>& vis) {
        vis[cur - 'a'] = 1;
        char minChar = cur;
        for (char neighbor : adj[cur]) {
            if (vis[neighbor - 'a'] == 0) {
                minChar = min(minChar, dfs(adj, neighbor, vis));
            }
        }
        return minChar;
    }
};