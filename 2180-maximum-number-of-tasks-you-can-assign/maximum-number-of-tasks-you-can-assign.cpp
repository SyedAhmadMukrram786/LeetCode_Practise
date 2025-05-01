class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int left = 0, right = min((int)tasks.size(), (int)workers.size()), ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> wset(workers.end() - k, workers.end());
        int usedPills = pills;

        for (int i = k - 1; i >= 0; --i) {
            auto it = wset.lower_bound(tasks[i]);
            if (it != wset.end()) {
                wset.erase(it);
            } else {
                if (usedPills == 0) return false;
                it = wset.lower_bound(tasks[i] - strength);
                if (it == wset.end()) return false;
                wset.erase(it);
                --usedPills;
            }
        }
        return true;
    }
};
