class Solution {
public:
    int maxSubstrings(string s) {
        vector<int> ans(s.size(), 0);
        vector<int> arr(26, -1);
        for (int i=3; i<s.size(); i++)
        {
            arr[s[i-3] - 'a'] = i-3;
            if (arr[s[i] - 'a'] >= 0)
            {
                ans[i] = 1;
            }
            if (arr[s[i] - 'a'] >= 1)
            {
                ans[i] = ans[arr[s[i] - 'a'] - 1] + 1;
            }
            ans[i] = max(ans[i], ans[i-1]);
        }
        return ans.back();
    }
};