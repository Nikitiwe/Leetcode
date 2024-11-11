class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> m;
        int ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            string t;
            unordered_set<char> n;
            for (int j=i; j<s.size(); j++)
            {
                t+=s[j];
                n.insert(s[j]);
                if (n.size()>maxLetters) break;
                if (t.size()>minSize) break;
                if (t.size()>=minSize)
                {
                    m[t]++;
                    ans=max(ans, m[t]);
                }
            }
        }
        return ans;
    }
};