class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans(1, 0);
        int r=1, l=-1;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='I')
            {
                ans.push_back(r);
                r++;
            }
            else
            {
                ans.push_back(l);
                l--;
            }
        }
        l++;
        for (int i=0; i!=ans.size(); i++) ans[i]-=l;
        return ans;
    }
};