class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        s+='Z';
        vector<vector<int>> ans;
        int l=0;
        for (int i=1; i<s.size(); i++)
        {
            if (s[i]!=s[i-1])
            {
                if (i-l>=3) ans.push_back({l, i-1});
                l=i;
            }
        }
        return ans;
    }
};