class Solution {
public:
    int canBeTypedWords(string t, string b) {
        unordered_set<char> m;
        for (int i=0; i!=b.size(); i++) m.insert(b[i]);
        int ans=0, i=0;
        while (i<t.size())
        {
            bool isit=1;
            while (i<t.size()&&t[i]!=' ')
            {
                if (m.count(t[i])==1)
                {
                    isit=0;
                }
                i++;
            }
            if (isit==1) ans++;
            i++;
        }
        return ans;
    }
};