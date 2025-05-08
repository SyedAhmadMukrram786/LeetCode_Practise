class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        if (n == 0) return 0;
        int m = moveTime[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0, 0});
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            int current_time = current[0];
            int move_seq = current[1];
            int i = current[2];
            int j = current[3];
            
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
                    int move_cost = (move_seq % 2 == 0) ? 1 : 2;
                    int new_time = max(current_time, moveTime[ni][nj]) + move_cost;
                    
                    if (new_time < dist[ni][nj]) {
                        dist[ni][nj] = new_time;
                        pq.push({new_time, move_seq + 1, ni, nj});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};