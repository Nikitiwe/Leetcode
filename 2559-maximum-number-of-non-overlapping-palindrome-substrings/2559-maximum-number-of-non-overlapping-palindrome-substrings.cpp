class Solution {
public:
    int maxPalindromes(string s, int k) {
        vector<int> ans(s.size()+1, 0);
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=i+k-1; j<s.size(); j++)
            {
                bool isit=1;
                for (int a=0; a<=j-i; a++)
                {
                    if (s[i+a]!=s[j-a]) {isit=0; break;}
                }
                if (isit==1)
                {
                    if (i>0) for (int b=j; b<ans.size(); b++)
                    {
                        ans[b]=max(ans[b], ans[i-1]+1);
                    }
                    else for (int b=j; b<ans.size(); b++)
                    {
                        ans[b]=max(ans[b], 1);
                    }
                }
                if (isit==1) break;
            }
        }
        return ans[ans.size()-1];
    }
};