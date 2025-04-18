class Solution {
public:
    int divisorSubstrings(int n, int k) {
        int ans = 0;
        string s = to_string(n);
        for (int i=0; i + k - 1 < s.size(); i++)
        {
            int d = 0;
            for (int j=i; j < i + k; j++)
            {
                d *= 10;
                d += s[j] - '0';
            }
            if (d > 0 && (n % d == 0)) ans++;
        }
        return ans;
    }
};