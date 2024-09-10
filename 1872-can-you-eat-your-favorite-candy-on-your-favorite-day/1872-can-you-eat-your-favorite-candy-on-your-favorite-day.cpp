class Solution {
public:
    vector<bool> canEat(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int, long> m;
        long t=0;
        m[-1]=0;
        for (int i=0; i!=nums.size(); i++)
        {
            t+=nums[i];
            m[i]=t;
        }
        vector<bool> ans(queries.size(), 0);
        for (int i=0; i!=queries.size(); i++)
        {
            if (m[queries[i][0]-1]<(long)(queries[i][1]+1)*queries[i][2]&&m[queries[i][0]]>queries[i][1]) ans[i]=1;
        }
        return ans;
    }
};