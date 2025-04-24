class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0;
        for (int k = 0; k!=26; k++)
        {
            int a = 0, b = 0;
            for (int i=0; i!=s.size(); i++)
            {
                b++;
                if (s[i] == 'A' + k)
                {
                    ans += (a) * (b);
                    a = b;
                    b = 0;
                }
            }
            b++;
            ans += (a) * (b);
        }
        return ans;
    }
};