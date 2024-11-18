class Solution {
public:
    int minSpeedOnTime(vector<int>& nums, double h) {
        //if ((int)nums.size()>(int)h) return -1;
        int l=1, r=10000001, ans=2000000000, m;
        while (l<=r)
        {
            m=(l+r)/2;
            int t=0;
            for (int i=0; i<nums.size()-1; i++)
            {
                t+=(nums[i]+m-1)/m;
            }
            double tt=(double)t+(double)(nums.back())/m;
            if (tt>h) l=m+1;
            else
            {
                ans=min(ans, m);
                r=m-1;
            }
        }
        if (ans>10000000) return -1;
        else return ans;
    }
};