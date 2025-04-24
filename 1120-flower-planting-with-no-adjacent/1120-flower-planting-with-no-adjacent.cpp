class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& p) {
        vector<int> ans(n, 0);
        for (int i=0; i!=p.size(); i++) if (p[i][0] > p[i][1]) swap(p[i][0], p[i][1]);
        sort(p.begin(), p.end());
        for (int i=0; i!=p.size(); i++)
        {
            int id = p[i][0] - 1;
            if (ans[id] == 0) ans[id] = 1;
            else if (ans[id] > 9)
            {
                int a = (ans[id]/10)%10;
                if (a == 0) ans[id] = 1;
                else
                {
                    int b = (ans[id]/100)%10;
                    if (b == 0) ans[id] = 2;
                    else
                    {
                        int c = (ans[id]/1000)%10;
                        if (c == 0) ans[id] = 3;
                        else ans[id] = 4;
                    }
                }
            }
            if (ans[id] == 1) ans[p[i][1]-1] += 10;
            else if (ans[id] == 2) ans[p[i][1]-1] += 100;
            else if (ans[id] == 3) ans[p[i][1]-1] += 1000;
            else ans[p[i][1]-1] += 10000;
        }
        for (int i=0; i!=ans.size(); i++)
        {
            int id = i;
            if (ans[id] == 0) ans[id] = 1;
            else if (ans[id] > 9)
            {
                int a = (ans[id]/10)%10;
                if (a == 0) ans[id] = 1;
                else
                {
                    int b = (ans[id]/100)%10;
                    if (b == 0) ans[id] = 2;
                    else
                    {
                        int c = (ans[id]/1000)%10;
                        if (c == 0) ans[id] = 3;
                        else ans[id] = 4;
                    }
                }
            }
        }
        return ans;
    }
};