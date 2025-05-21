class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zero;

        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                if(matrix[i][j]==0) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    zero.push_back(temp);
                }
            }
        }

        for(int i=0;i<zero.size();i++) {
            for(int j=0;j<matrix.size();j++) {
                matrix[j][zero[i][1]]=0;
            }
            for(int j=0;j<matrix[0].size();j++) {
                matrix[zero[i][0]][j]=0;
            }
        }
    }
};