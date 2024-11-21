class Solution {
public:
    long long repairCars(vector<int>& nums, int cc) {
        long long ans=9999999999999999, l=0, r=ans, m;
        while (l<=r)
        {
            m=(r+l)/2;
            long long loc=0, temp=0, c=cc;
            for (int i=0; i!=nums.size(); i++)
            {
                temp=min(c, (long long)sqrt(m/nums[i]));
                c-=temp;
                if (c==0) break;
            }
            if (c==0)
            {
                ans=min(ans, m);
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
};