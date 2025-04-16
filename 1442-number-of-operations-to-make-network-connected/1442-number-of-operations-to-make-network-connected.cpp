class Solution {
public:
    void f(vector<int> &used, vector<vector<int>> &arr, int i)
    {
        used[i] = 1;
        for (int j = 0; j!= arr[i].size(); j++) if (used[arr[i][j]] == 0) f(used, arr, arr[i][j]);
    }

    int makeConnected(int n, vector<vector<int>>& c) {
        if (c.size() < n-1) return -1;
        vector<vector<int>> arr(n);
        vector<int> used(n, 0);
        for (int i=0; i!=c.size(); i++)
        {
            arr[c[i][0]].push_back(c[i][1]);
            arr[c[i][1]].push_back(c[i][0]);
        }
        int count = 0;
        for (int i=0; i!=used.size(); i++)
        {
            if (used[i] == 0)
            {
                count++;
                f(used, arr, i);
            }
        }
        return count - 1;
    }
};