class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        if((mat[0].size()*mat.size())!=(r*c)) {
            return mat;
        }
        else {
            int k=0;
            vector<int> a;
            for(int i=0;i<mat.size();i++) {
                for(int j=0;j<mat[i].size();j++) {
                    a.push_back(mat[i][j]);
                    k++;
                    if(k%c==0) {
                        ans.push_back(a);
                        a.clear();
                    }
                }
            }
        }
        return ans;
    }
};