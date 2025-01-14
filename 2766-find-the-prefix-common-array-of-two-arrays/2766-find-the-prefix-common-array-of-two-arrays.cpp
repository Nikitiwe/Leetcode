class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> ans(a.size(), 0);
        unordered_map<int, int> m;
        for (int i=0; i!=a.size(); i++) m[a[i]]=i;
        int t=0;
        for (int i=0; i!=a.size(); i++)
        {
            ans[max(m[b[i]], i)]++;
            if (i>0) ans[i]+=ans[i-1];
        }
        return ans;
    }
};