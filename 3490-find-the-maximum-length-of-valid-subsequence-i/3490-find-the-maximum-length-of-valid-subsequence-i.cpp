class Solution {
public:
    int maximumLength(vector<int>& nums) {
        for (int i=0; i!=nums.size(); i++) {nums[i]=nums[i]%2;}
        vector<int> ans(4, 0);
        if (nums.size()==2) return 2;
        int sum, l=0;
        for (int i=0; i!=nums.size(); i++)
        {if (nums[i]==0) ans[0]++; else ans[1]++;}
        while (l<nums.size())
        {
            if (nums[l]==0)
            {
                ans[2]++;
                l++;
                if (l==nums.size()) break;
                while (nums[l]==0&&l<nums.size())
                {
                    l++;
                    if (l==nums.size()) break;
                }
                if (l==nums.size()) break;
                if (nums[l]==1) ans[2]++;
            }
            else l++; if (l==nums.size()) break;
        }
        l=0;
        while (l<nums.size())
        {
            if (nums[l]==1)
            {
                ans[3]++;
                l++;
                if (l==nums.size()) break;
                while (nums[l]==1&&l<nums.size())
                {
                    l++;
                    if (l==nums.size()) break;
                }
                if (l==nums.size()) break;
                if (nums[l]==0) ans[3]++;
            }
            else l++; if (l==nums.size()) break;
        }

        return max(max(ans[0],ans[1]),max(ans[2],ans[3]));
    }
};