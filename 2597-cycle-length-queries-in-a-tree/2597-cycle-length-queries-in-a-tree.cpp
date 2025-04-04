class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        for (int i=0; i!=q.size(); i++)
        {
            int x = q[i][0], y = q[i][1];
            if (x < y) swap(x, y);
            int l = 1;
            while (1)
            {
                if (x < y*2)
                {
                    x /= 2;
                    l++;
                    if (x == y) break;
                    y /= 2;
                    l++;
                    if (x == y) break;
                }
                else
                {
                    x /= 2;
                    l++;
                    if (x == y) break;
                }
            }
            ans.push_back(l);
        }
        return ans;
    }
};