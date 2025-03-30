class Solution {
public:
    int minSwaps(vector<vector<int>>& g) {
        vector<int> arr(g.size(), 0);
        for (int i=0; i!=g.size(); i++)
        {
            int t=g.size()-1;
            for (int j=g[0].size()-1; j>=0; j--)
            {
                if (g[i][j] == 0) t--;
                else break;
            }
            arr[i] = t;
        }
        int ans = 0;
        for (int i=0; i!=g.size(); i++)
        {
            int id = -1;
            for (int j=i; j<g.size(); j++)
            {
                if (arr[j] <= i)
                {
                    id = j;
                    break;
                }
            }
            if (id == -1) return -1;
            for (int j=id; j>i; j--)
            {
                swap(arr[j], arr[j-1]);
                ans++;
            }
        }
        return ans;
    }
};