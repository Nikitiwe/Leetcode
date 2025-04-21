class Solution {
public:
    int maximumCostSubstring(string s, string c, vector<int>& nums) {
        int ans = 0, t = 0;
        vector<int> arr(26, 0);
        for (int i=0; i!=26; i++) arr[i] = i+1;
        for (int i=0; i!=c.size(); i++)
        {
            arr[c[i] - 'a'] = nums[i];
        }
        for (int i=0; i!=s.size(); i++)
        {
            t += arr[s[i] - 'a'];
            t = max(0, t);
            ans = max(ans, t);
        }
        return ans;
    }
};