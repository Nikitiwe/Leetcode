class Solution {
public:
    int minimumCost(vector<int>& s, vector<int>& t, vector<vector<int>>& r) {
        int ans = abs(s[0] - t[0]) + abs(s[1] - t[1]);
        vector<int> arr(r.size(), 0);
        queue<int> id, c;
        for (int i=0; i!=r.size(); i++)
        {
            id.push(i);
            arr[i] = abs(s[0] - r[i][0]) + abs(s[1] - r[i][1]) + r[i][4];
            c.push(arr[i]);
        }
        while (id.size() > 0)
        {
            int i = id.front(); id.pop();
            int val = c.front(); c.pop();
            ans = min(ans, val + abs(r[i][2] - t[0]) + abs(r[i][3] - t[1]));
            for (int j=0; j!=r.size(); j++) if (j != i)
            {
                int add = abs(r[j][0] - r[i][2]) + abs(r[j][1] - r[i][3]) + r[j][4];
                if (val + add < arr[j])
                {
                    id.push(j);
                    arr[j] = val + add;
                    c.push(arr[j]);
                }
            }
        }
        return ans;
    }
};