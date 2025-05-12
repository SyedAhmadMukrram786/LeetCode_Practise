class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int count[10] = {0};
        
        for (int d : digits) {
            count[d]++;
        }

        for (int num = 100; num <= 999; ++num) {
            if (num % 2 != 0) continue; 

            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            int needed[10] = {0};
            needed[a]++;
            needed[b]++;
            needed[c]++;

            bool canForm = true;
            for (int i = 0; i < 10; ++i) {
                if (needed[i] > count[i]) {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
