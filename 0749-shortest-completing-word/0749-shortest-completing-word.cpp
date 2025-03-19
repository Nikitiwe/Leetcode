class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& w) {
        int ans = -1;
        vector<int> arrs(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='a' && s[i] <= 'z') arrs[s[i]-'a']++;
            else if (s[i]>='A' && s[i] <= 'Z') arrs[s[i]-'A']++;
        }
        for (int j=0; j!=w.size(); j++)
        {
            bool isit = 1;
            vector<int> arr(26, 0);
            for (int i=0; i!=w[j].size(); i++) arr[w[j][i]-'a']++;
            for (int i=0; i!=26; i++)
            {
                if (arr[i]<arrs[i])
                {
                    isit = 0;
                    break;
                }
            }
            if (isit == 1)
            {
                if (ans == -1) ans = j;
                else if (w[j].size() < w[ans].size()) ans = j;
            }
        }
        return w[ans];
    }
};