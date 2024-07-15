class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> ans;
        vector<double> row;
        for (int i=0; i<=query_row+1; i++)
        {
            row.push_back(0);
            ans.push_back(row);
        }
        ans[0][0]=poured;
        for(int i=0; i!=ans.size()-1; i++)
        {
            for(int j=0; j!=ans[i].size(); j++)
            {
                if (ans[i][j]>1) ans[i+1][j]+=(ans[i][j]-1)/2;
                if (ans[i][j]>1) {ans[i+1][j+1]+=(ans[i][j]-1)/2; ans[i][j]=1;}
            }
        }
        return ans[query_row][query_glass];
    }
};