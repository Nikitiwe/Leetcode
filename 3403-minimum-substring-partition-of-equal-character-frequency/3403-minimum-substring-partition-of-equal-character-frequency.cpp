class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        vector<int> ans(s.size()+1, 10000);
        ans[0] = 0;
        for (int i=0; i!=s.size(); i++)
        {
            vector<int> t(26, 0);
            for (int j=i; j<s.size(); j++)
            {
                t[s[j] - 'a']++;
                bool isit = 1;
                int val = -1;
                for (int a=0; a<26; a++)
                {
                    if (t[a] != 0)
                    {
                        if (val == -1) val = t[a];
                        else if (val != t[a])
                        {
                            isit = 0;
                            break;
                        }
                    }
                }
                if (isit == 1) ans[j+1] = min(ans[i] + 1, ans[j+1]);
            }
        }
        return ans.back();
    }
};