class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= min(n, limit); ++i) {
            int min_j = max(0, n - i - limit);
            int max_j = min(limit, n - i);
            if (min_j <= max_j) {
                res += (max_j - min_j + 1);
            }
        }
        return res;
    }
};