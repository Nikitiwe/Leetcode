class Solution {
public:
    void f(string &s, int &ans, int k, char a, char b, char nota, char notb)
    {
        int x = 0, y = 0;
        for (int i=0; i!=s.size(); i++) 
        {
            if (s[i] == a) x++;
            else if (s[i] == b) y++;
            else if (s[i] == nota)
            {
                if (k > 0)
                {
                    k--;
                    x++;
                }
                else x--;
            }
            else if (s[i] == notb)
            {
                if (k > 0)
                {
                    k--;
                    y++;
                }
                else y--;
            }

            ans = max(ans, abs(x) + abs(y));
        }
    }

    int maxDistance(string s, int k) {
        int ans = 0;
        f(s, ans, k, 'N', 'W', 'S', 'E');
        f(s, ans, k, 'N', 'E', 'S', 'W');
        f(s, ans, k, 'S', 'W', 'N', 'E');
        f(s, ans, k, 'S', 'E', 'N', 'W');
        return ans;
    }
};