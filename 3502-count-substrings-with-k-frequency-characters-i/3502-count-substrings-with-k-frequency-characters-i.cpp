class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        for (int i=0; i!=s.size(); i++)
        {
            vector<int> arr(26, 0);
            for (int j=i; j<s.size(); j++)
            {
                arr[s[j] - 'a']++;
                if (arr[s[j] - 'a'] == k)
                {
                    ans += s.size() - j;
                    break;
                }
            }
        }
        return ans;
    }
};