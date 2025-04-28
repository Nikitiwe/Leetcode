class Solution {
public:
    int closestCost(vector<int>& b, vector<int>& c, int k) {
        vector<vector<int>> arr(c.size() + 1, vector<int>());
        for (int i=0; i!=b.size(); i++) arr[0].push_back(b[i]);
        for (int i=0; i!=c.size(); i++)
        {
            for (int j=0; j!=arr[i].size(); j++) arr[i+1].push_back(arr[i][j]);
            for (int j=0; j!=arr[i].size(); j++)
            {
                if (arr[i][j] < k)
                {
                    arr[i+1].push_back(arr[i][j] + c[i]);
                    arr[i+1].push_back(arr[i][j] + 2*c[i]);
                }
            }
        }
        int ans = arr[c.size()][0];
        for (int j=0; j!=arr[c.size()].size(); j++)
        {
            if (abs(k - arr[c.size()][j]) < abs(k - ans)) ans = arr[c.size()][j];
            else if (abs(k - arr[c.size()][j]) == abs(k - ans)) ans = min(ans, arr[c.size()][j]);
        }
        return ans;
    }
};