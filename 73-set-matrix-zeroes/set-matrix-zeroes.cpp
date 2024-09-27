class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> mat=matrix;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=j+1;k<matrix[i].size();k++)
                    {
                        mat[i][k]=0;
                    }
                    for(int k=j-1;k>=0;k--)
                    {
                        mat[i][k]=0;
                    }
                    for(int k=i-1;k>=0;k--)
                    {
                        mat[k][j]=0;
                    }
                    for(int k=i+1;k<matrix.size();k++)
                    {
                        mat[k][j]=0;
                    }
                }
            }
        }
        matrix=mat;
    }
};