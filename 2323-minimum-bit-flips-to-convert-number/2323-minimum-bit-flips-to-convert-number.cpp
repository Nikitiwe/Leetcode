class Solution {
public:
    int minBitFlips(int s, int g) {
        int ans=0;
        while (s>0||g>0)
        {
            if (s%2==0)
            {
                if (g%2==1) ans++;
            }
            else if (g%2==0) ans++;
            s/=2;
            g/=2;
        }
        return ans;
    }
};