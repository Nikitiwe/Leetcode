class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        for (int i=0; i<=pattern.size(); i++)
        { ans=ans+to_string(i+1); }
        while (1)
        {
            bool isit=1;
            for (int i=0; i<=pattern.size(); i++)
            {
                if (pattern[i]=='I'&&ans[i+1]<ans[i]) {isit=0; break;}
                else if (pattern[i]=='D'&&ans[i+1]>ans[i]) {isit=0; break;}
            }
            if (isit) return ans;
            next_permutation(ans.begin(), ans.end());
        }
    }
};