class Solution {
public:
    int rangeBitwiseAnd(int ll, int rr) {
        int ans = 0;
        long add = 1, r = rr, l = ll;
        while (r>0)
        {
            int a = l/2;
            int b = (r+1)/2;
            if ((b-a) == r - l + 1) ans += add;
            l /= 2;
            r /= 2;
            add *= 2;
        }
        return ans;
    }
};