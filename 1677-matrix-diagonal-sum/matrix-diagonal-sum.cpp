class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans_sum=0;
        for(int i=0;i<mat.size();i++) {
            ans_sum+=mat[i][i];
            if(mat.size()%2!=0 && i==mat.size()/2) {
                continue;
            }
            ans_sum+=mat[i][mat.size()-(i+1)];
        }
        return ans_sum;
    }
};