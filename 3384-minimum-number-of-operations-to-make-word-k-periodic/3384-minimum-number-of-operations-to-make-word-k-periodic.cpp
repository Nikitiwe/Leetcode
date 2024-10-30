class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string s, int k) {
        int ma=0;
        unordered_map<string, int> m;
        string t;
        for (int i=0; i!=s.size(); i++)
        {
            t+=s[i];
            if (t.size()%k==0)
            {
                m[t]++;
                ma=max(ma, m[t]);
                t="";
            }
        }
        return s.size()/k-ma;
    }
};