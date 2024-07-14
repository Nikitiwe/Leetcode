class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int ans=0, h=1, v=1;
        if (n>1&&m>1) {
        for (int i=0; i!=m+n-2; i++)
        {
            auto mg=max_element(horizontalCut.begin(), horizontalCut.end());
            auto mv=max_element(verticalCut.begin(), verticalCut.end());
            if (*mg>=*mv)
            {
                h++;
                ans+=(*mg)*v;
                horizontalCut[distance(horizontalCut.begin(), mg)]=0;
            }
            else
            {
                v++;
                ans+=(*mv)*h;
                verticalCut[distance(verticalCut.begin(), mv)]=0;
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