class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans=0;
        vector<long long> count(n, 0);
        for (int i=0; i!=roads.size(); i++)
        {
            count[roads[i][0]]++;
            count[roads[i][1]]++;
        }
        sort(count.begin(), count.end());
        for (int i=0; i!=n; i++)
        {
            ans=ans+count[i]*(i+1);
        }
        return ans;
    }
};