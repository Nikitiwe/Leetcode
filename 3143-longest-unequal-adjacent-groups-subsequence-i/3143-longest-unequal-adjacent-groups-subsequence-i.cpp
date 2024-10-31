class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
        vector<string> ans;
        ans.push_back(w[0]);
        int k=g[0];
        for (int i=1; i<w.size(); i++)
        {
            if (g[i]!=k)
            {
                ans.push_back(w[i]);
                k=g[i];
            }
        }
        return ans;
    }
};