class Solution {
public:
    int maxUniqueSplit(string s) {
        int ans=0, d=1, l=s.size();
        while (l>1)
        {
            d*=2;
            l--;
        }
        for (int i=0; i!=d; i++)
        {
            unordered_set<string> m;
            int k=i;
            string t;
            t+=s[0];
            for (int j=1; j<s.size(); j++)
            {
                if (k%2==0)
                {
                    t+=s[j];
                }
                else
                {
                    m.insert(t);
                    t="";
                    t+=s[j];
                }
                k/=2;
            }
            if (t.size()>0) m.insert(t);
            ans=max(ans, (int)m.size());
        }
        return ans;
    }
}; // Time Limit Exceeded