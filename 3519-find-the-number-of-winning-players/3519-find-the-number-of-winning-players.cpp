class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> arr;
        vector<int> row(11, 0);
        int ans=0;
        for (int i=0; i!=n; i++) arr.push_back(row);
        for (int i=0; i!=pick.size(); i++)
        {
            arr[pick[i][0]][pick[i][1]]++;
        }
        for (int i=0; i!=n; i++)
        {
            for (int j=0; j!=11; j++)
            {
                if (arr[i][j]>i) {ans++; break;}
            }
        }
        return ans;
    }
};