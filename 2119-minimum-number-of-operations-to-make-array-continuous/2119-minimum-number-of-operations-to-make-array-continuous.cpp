class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(), l=0, r=0, count=1, m=1;
        if (n==1) return 0;
        sort(nums.begin(), nums.end());
        while (r<nums.size())
        {
            if (r==nums.size()-1) break;
            if (nums[r+1]-nums[l]<n)
            {
                r++;
                if (nums[r-1]!=nums[r])
                {
                    count++;
                    m=max(m, count);
                }
                if (r==nums.size()-1) break;
            }
            else
            {
                if (l==nums.size()-1) break;
                l++;
                if (nums[l-1]!=nums[l])
                {
                    count--;
                }
                if (l>r)
                {
                    r++;
                    count=1;
                }
            }
        }
        return n-m;
    }
};