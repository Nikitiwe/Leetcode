class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> m, count;
        vector<int> ans(queries.size(), 0);
        for (int i=0; i!=queries.size(); i++)
        {
            if (m.count(queries[i][0])==0)
            {
                m[queries[i][0]]=queries[i][1];
                count[queries[i][1]]++;
            }
            else
            {
                count[m[queries[i][0]]]--;
                if (count[m[queries[i][0]]]==0) count.erase(m[queries[i][0]]);
                m[queries[i][0]]=queries[i][1];
                count[queries[i][1]]++;
            }
            ans[i]=count.size();
        }
        return ans;
    }
};