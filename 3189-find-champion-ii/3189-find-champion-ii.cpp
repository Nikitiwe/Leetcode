class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 1);
        for (int i=0; i!=edges.size(); i++)
        {
            ans[edges[i][1]]=0;
        }
        int sum=0, id;
        for (int i=0; i!=n; i++)
        {
            sum+=ans[i];
            if (ans[i]==1) id=i;
        }
        if (sum>1) return -1;
        else return id;
    }
};