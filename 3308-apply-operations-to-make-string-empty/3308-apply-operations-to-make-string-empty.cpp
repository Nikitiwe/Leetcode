class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> arr(s.size(), 0);
        vector<int> c(26, 0);
        int ma = 0;
        for (int i=0; i!=s.size(); i++)
        {
            c[s[i] - 'a']++;
            arr[i] = c[s[i] - 'a'];
            ma = max(ma, arr[i]);
        }
        string ans;
        for (int i=0; i!=s.size(); i++) if (arr[i] == ma) ans += s[i];
        return ans;
    }
};