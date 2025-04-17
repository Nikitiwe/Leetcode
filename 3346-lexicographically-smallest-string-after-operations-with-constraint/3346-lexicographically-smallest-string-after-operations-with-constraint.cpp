class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i=0; i!=s.size(); i++)
        {
            if (k >= 13)
            {
                int d = min (s[i] - 'a', 26 - (s[i] - 'a'));
                k -= d;
                s[i] = 'a';
            }
            else
            {
                for (int j=0; j<26; j++)
                {
                    int d = min (s[i] - 'a' - j, 26 - (s[i] - 'a' - j));
                    if (d <= k)
                    {
                        k -= d;
                        s[i] = 'a' + j;
                        break;
                    }
                }
            }
            if (k == 0) break;
        }
        return s;
    }
};