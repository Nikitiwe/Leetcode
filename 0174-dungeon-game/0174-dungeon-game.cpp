class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int l = 1, r = 5e6, ans = r, m, f = -r;
        while (l <= r)
        {
            m = (l+r)/2;
            vector<vector<int>> arr = d;
            arr[0][0] += m;
            if (arr[0][0] > 0)
            {
                for (int i=1; i<arr.size(); i++)
                {
                    arr[i][0] += arr[i-1][0];
                    if (arr[i][0] <= 0) arr[i][0] = f;
                }
                for (int j=1; j<arr[0].size(); j++)
                {
                    arr[0][j] += arr[0][j-1];
                    if (arr[0][j] <= 0) arr[0][j] = f;
                }
                for (int i=1; i<arr.size(); i++)
                {
                    for (int j=1; j<arr[0].size(); j++)
                    {
                        int h = max(arr[i-1][j], arr[i][j-1]);
                        arr[i][j] += h;
                        if (arr[i][j] <= 0) arr[i][j] = f;
                    }
                }
                if (arr[arr.size()-1][arr[0].size()-1] <= 0)
                {
                    l = m+1;
                }
                else
                {
                    ans = min(ans, m);
                    r = m-1;
                }
            }
            else l = m+1;
        }
        return ans;
    }
};