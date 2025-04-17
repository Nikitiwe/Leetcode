class Solution {
public:
    string longestNiceSubstring(string s) {
        for (int d = s.size(); d>=1; d--)
        {
            for (int i=0; i<s.size(); i++)
            {
                if (i+d > s.size()) break;
                string t = s.substr(i, d);
                vector<bool> arr(26, 0), brr(26, 0);
                for (int j=0; j!=t.size(); j++)
                {
                    if (t[j] >= 'a' && t[j] <= 'z') arr[t[j] - 'a'] = 1;
                    else brr[t[j] - 'A'] = 1;
                }
                bool isit = 1;
                for (int j=0; j!=26; j++)
                {
                    if (arr[j] ^ brr[j] == 1 )
                    {
                        isit = 0;
                        break;
                    }
                }
                if (isit == 1) return t;
            }
        }
        return "";
    }
};