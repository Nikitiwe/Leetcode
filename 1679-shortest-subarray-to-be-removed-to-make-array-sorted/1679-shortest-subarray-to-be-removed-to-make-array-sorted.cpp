class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        if (nums.size()==1) return 0;
        int l=0, r=nums.size()-1, ans=nums.size()-1;
        while (l<nums.size()-1&&nums[l]<=nums[l+1]) l++;
        if (l==nums.size()-1) return 0;
        while (r>0&&nums[r-1]<=nums[r]) r--;
        if (nums[l]<=nums[r]) return r-l-1;
        ans=min(ans, r);
        ans=min(ans, (int)nums.size()-l-1);
        int ll=0;
        for (int i=r; i<nums.size(); i++)
        {
            while (ll<l&&nums[ll+1]<=nums[i]) ll++;
            if (nums[ll]<=nums[i]) ans=min(ans, i-ll-1);
        }
        return ans;
    }
};