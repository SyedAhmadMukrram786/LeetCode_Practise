class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        for (auto& e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        vector<int> reach1(n, 0), reach2(m, 0);

        auto bfs = [](int start, int k, vector<vector<int>>& graph, vector<int>& reach) {
            int size = graph.size();
            for (int i = 0; i < size; ++i) {
                queue<pair<int, int>> q;
                vector<bool> visited(size, false);
                q.push({i, 0});
                visited[i] = true;
                int cnt = 0;
                while (!q.empty()) {
                    auto [node, dist] = q.front();
                    q.pop();
                    if (dist > k) continue;
                    cnt++;
                    for (int nei : graph[node]) {
                        if (!visited[nei]) {
                            visited[nei] = true;
                            q.push({nei, dist + 1});
                        }
                    }
                }
                reach[i] = cnt;
            }
        };

        bfs(0, k, g1, reach1);
        bfs(0, k - 1, g2, reach2);

        int max_reach2 = *max_element(reach2.begin(), reach2.end());

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = reach1[i] + max_reach2;
        }

        return result;
    }
};