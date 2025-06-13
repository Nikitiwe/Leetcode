class Solution {
public:
    string toHex(int num) {
        string ans;
        if (num >= 0)
        {
            if (num == 0) ans += '0';
            while (num > 0)
            {
                int r = num % 16;
                num /= 16;
                if (r < 10) ans += to_string(r);
                else ans += 'a' + r - 10;
            }
        }
        else
        {
            unsigned int x = (unsigned int)num;
            while (x > 0)
            {
                int r = x % 16;
                x /= 16;
                if (r < 10) ans += to_string(r);
                else ans += 'a' + r - 10;
            }
        }
        reverse (ans.begin(), ans.end());
        return ans;
    }
};