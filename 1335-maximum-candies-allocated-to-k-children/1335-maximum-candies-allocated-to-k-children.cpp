class Solution {
public:
    int maximumCandies(vector<int>& can, long long k) {
        long long l=0, r=10000000, m=(l+r)/2, ans=0, temp;
        while (l<r)
        {
            temp=0;
            for (int i=0; i!=can.size(); i++)
            {
                temp+=can[i]/m;
            }
            if (temp<k) {r=m-1;}
            else {l=m; r++;}
            m=(l+r)/2;
        }
        return m;
    }
};