class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i] - 'a']++;
        string ans;
        string m;
        for (int i=0; i<26; i++)
        {
            if (arr[i] % 2 == 1) m += 'a' + i;
            int t = arr[i] / 2;
            for (int j=0; j!=t; j++) ans += 'a' + i;
        }
        ans += m;
        for (int i=25; i>=0; i--)
        {
            int t = arr[i] / 2;
            for (int j=0; j!=t; j++) ans += 'a' + i;
        }
        return ans;
    }
};