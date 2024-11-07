class Solution {
public:
    int minDays(vector<int>& nums, int n, int k) {
        int l=*min_element(nums.begin(), nums.end()), r=*max_element(nums.begin(), nums.end()), m;

        {
            int c=0, s=0;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i]<=r) c++;
                else c=0;
                if (c==k)
                {
                    s++;
                    c=0;
                }
            }
            if (s<n) return -1;
        }
        
        while (l<r)
        {
            m=(l+r)/2;
            int c=0, s=0;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i]<=m) c++;
                else c=0;
                if (c==k)
                {
                    s++;
                    c=0;
                }
            }
            if (s<n) l=m+1;
            else r=m;
        }
        return (l+r)/2;
    }
};