class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        if (n == 0) return 0;
        int m = moveTime[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0; // Start at time 0
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            int current_time = current[0];
            int i = current[1];
            int j = current[2];
            
            if (i == n - 1 && j == m - 1) {
                return current_time;
            }
            
            if (current_time > dist[i][j]) {
                continue;
            }
            
            for (auto& dir : dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int new_time = max(current_time, moveTime[ni][nj]) + 1;
                    if (new_time < dist[ni][nj]) {
                        dist[ni][nj] = new_time;
                        pq.push({new_time, ni, nj});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};