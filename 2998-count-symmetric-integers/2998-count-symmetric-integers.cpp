class Solution {
public:
    int countSymmetricIntegers(int l, int h) {
        int ans=0;
        for (int i=max(l, 10); i<=min(h, 99); i++)
        {
            if (i/10==i%10) ans++;
        }
        for (int i=max(l, 1000); i<=min(h, 9999); i++)
        {
            if (i/1000+(i/100)%10==(i/10)%10+i%10) ans++;
        }
        return ans;
    }
};