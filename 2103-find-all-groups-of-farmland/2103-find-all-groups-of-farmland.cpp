class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int right, down;
        vector<vector<int>> ans;
        for (int i=0; i!=land.size(); i++)
        {
            for (int j=0; j!=land[0].size(); j++)
            {
                if (land[i][j]==1)
                {
                    right=j; down=i;
                    while (down+1<(land.size()))
                    {
                        if (land[down+1][j]==1) {down++;}
                        else break;
                    }
                    while (right+1<(land[0].size()))
                    {
                        if (land[i][right+1]==1) {right++;}
                        else break;
                    }
                    ans.push_back({i, j, down, right});
                    for (int a=i; a<=down; a++)
                    {
                        for (int b=j; b<=right; b++) land[a][b]=0;
                    }
                }
            }
        }
        return ans;
    }
};