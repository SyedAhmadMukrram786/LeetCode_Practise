class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false), opened(n, false), hasKey(n, false);
        queue<int> q;
        int totalCandies = 0;

        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box]) q.push(box);
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            if (opened[box]) continue;
            opened[box] = true;
            totalCandies += candies[box];

            for (int key : keys[box]) {
                hasKey[key] = true;
                if (hasBox[key] && !opened[key]) {
                    q.push(key);
                }
            }

            for (int contained : containedBoxes[box]) {
                hasBox[contained] = true;
                if (status[contained] || hasKey[contained]) {
                    q.push(contained);
                }
            }
        }

        return totalCandies;
    }
};