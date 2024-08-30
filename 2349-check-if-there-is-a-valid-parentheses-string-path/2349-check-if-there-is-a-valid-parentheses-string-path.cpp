class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if ((grid.size()+grid[0].size())%2==0) return 0;
        if (grid[0][0]==')') return 0;
        vector<vector<unordered_set<int>>> arr(grid.size(), vector<unordered_set<int>> (grid[0].size(), unordered_set<int> () ));
        arr[0][0].insert(1);
        for (int i=1; i<grid.size(); i++)
        {
            if (grid[i][0]=='(')
            {
                for (auto it=arr[i-1][0].begin(); it!=arr[i-1][0].end(); it++)
                {
                    arr[i][0].insert(*it+1);
                }
            }
            else
            {
                for (auto it=arr[i-1][0].begin(); it!=arr[i-1][0].end(); it++)
                {
                    if (*it>=1) arr[i][0].insert(*it-1);
                }
            }
        }

        for (int j=1; j<grid[0].size(); j++)
        {
            if (grid[0][j]=='(')
            {
                for (auto it=arr[0][j-1].begin(); it!=arr[0][j-1].end(); it++)
                {
                    arr[0][j].insert(*it+1);
                }
            }
            else
            {
                for (auto it=arr[0][j-1].begin(); it!=arr[0][j-1].end(); it++)
                {
                    if (*it>=1) arr[0][j].insert(*it-1);
                }
            }
        }

        for (int i=1; i<grid.size(); i++)
        {
            for (int j=1; j<grid[0].size(); j++)
            {
                if (grid[i][j]=='(')
                {
                    for (auto it=arr[i-1][j].begin(); it!=arr[i-1][j].end(); it++)
                    {
                        arr[i][j].insert(*it+1);
                    }
                    for (auto it=arr[i][j-1].begin(); it!=arr[i][j-1].end(); it++)
                    {
                        arr[i][j].insert(*it+1);
                    }
                }
                else
                {
                    for (auto it=arr[i-1][j].begin(); it!=arr[i-1][j].end(); it++)
                    {
                        if (*it>=1) arr[i][j].insert(*it-1);
                    }
                    for (auto it=arr[i][j-1].begin(); it!=arr[i][j-1].end(); it++)
                    {
                        if (*it>=1) arr[i][j].insert(*it-1);
                    }
                }
            }
        }
        if (arr[grid.size()-1][grid[0].size()-1].count(0)>0) return 1;
        else return 0;
    }
};