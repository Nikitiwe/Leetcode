class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& l) {
        vector<int> ans(n, 0);
        int t = 0;
        for (int i=0; i!=l.size(); i++)
        {
            ans[l[i][0]] = max(ans[l[i][0]], l[i][1] - t);
            t = l[i][1];
        }
        int id = 0;
        for (int i=0; i!=ans.size(); i++)
        {
            if (ans[i] > ans[id]) id = i;
        }
        return id;
    }
};