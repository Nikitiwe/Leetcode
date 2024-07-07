class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans=0, sum;
        vector<int> arr;
        vector<vector<int>> asx, asy;
        for (int i=0; i!=grid.size(); i++)
        {
            sum=0;
            arr.clear();
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (grid[i][j]=='X') sum++;
                arr.push_back(sum);
            }
            asx.push_back(arr);
        }
        for (int i=0; i!=grid.size(); i++)
        {
            sum=0;
            arr.clear();
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (grid[i][j]=='Y') sum++;
                arr.push_back(sum);
            }
            asy.push_back(arr);
        }
        for (int i=1; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                asx[i][j]=asx[i][j]+asx[i-1][j];
                asy[i][j]=asy[i][j]+asy[i-1][j];
            }
        }
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                if (asx[i][j]>0&&asx[i][j]==asy[i][j]) ans++;
            }
        }
        return ans;
    }
};