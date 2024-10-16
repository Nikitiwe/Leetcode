class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_set<int> m;
        m.insert(1);
        int c=1, kk=k;
        for (int i=2; i!=n+2; i++)
        {
            c+=kk;
            if (c%n!=0) c%=n;
            else c=n;
            m.insert(c);
            if (m.size()<i) break;
            kk+=k;
        }
        vector<int> ans;
        for (int i=1; i<=n; i++)
        {
            if (m.count(i)==0) ans.push_back(i);
        }
        return ans;
    }
};