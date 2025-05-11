class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s;
        for (int i=0; i!=32; i++)
        {
            s += to_string(n%2);
            n /= 2;
        }
        //reverse(s.begin(), s.end());
        uint32_t ans = 0;
        for (int i=0; i!=s.size(); i++)
        {
            ans *= 2;
            ans += s[i] - '0';
        }
        return ans;
    }
};