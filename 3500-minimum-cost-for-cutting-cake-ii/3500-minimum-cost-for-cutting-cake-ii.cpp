class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long ans=0;
        int h=1, v=1, iv=n-2, ih=m-2;
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        if (n>1&&m>1) {
        for (int i=0; i!=m+n-2; i++)
        {
            if (horizontalCut[ih]>=verticalCut[iv])
            {
                h++;
                ans+=(horizontalCut[ih])*v;
                horizontalCut[ih]=0;
                if (ih>0) ih--;
            }
            else
            {
                v++;
                ans+=(verticalCut[iv])*h;
                verticalCut[iv]=0;
                if (iv>0) iv--;
            }
        } }
        else
        {
            for (int j=0; j!=n-1; j++)
            {
                ans+=verticalCut[j];
            }
            for (int j=0; j!=m-1; j++)
            {
                ans+=horizontalCut[j];
            }
        }
        return ans;
    }
};