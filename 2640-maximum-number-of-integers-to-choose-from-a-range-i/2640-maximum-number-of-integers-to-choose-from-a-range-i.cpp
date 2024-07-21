class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> m;
        for (int i=0; i!=banned.size(); i++)
        {
            if (banned[i]<=n) m.insert(banned[i]);
        }
        int ans=0, sum=0;
        for (int i=1; i<=n; i++)
        {
            if (sum+i>maxSum) break;
            if (m.count(i) == 0)
            {
                ans++;
                sum+=i;
            }
        }
        return ans;
    }
};