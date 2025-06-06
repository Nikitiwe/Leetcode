class Solution {
public:
    string robotWithString(string s) {
        string t, ans;
        vector<int> arr(26, -1);
        int c = 0;
        for (int i=0; i!=s.size(); i++) arr[s[i] - 'a'] = i;
        for (int i=0; i!=s.size(); i++)
        {
            if (arr[c] < i) c++;
            while (c < 26 && (arr[c] == -1 || arr[c] < i)) c++;
            while (t.size() > 0 && t.back() - 'a' <= c)
            {
                ans += t.back();
                t.pop_back();
            }
            if (s[i] - 'a' == c) ans += s[i];
            else t += s[i];
            /*if (arr[c] == i)
            {
                c++;
                while (c < 26 && arr[c] == -1) c++;
                while (t.size() > 0 && t.back() - 'a' <= c)
                {
                    ans += t.back();
                    t.pop_back();
                }
            }*/
        }
        for (int i=t.size()-1; i>=0; i--) ans += t[i];
        return ans;
    }
};