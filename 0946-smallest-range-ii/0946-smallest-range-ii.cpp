class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int mi=*min_element(nums.begin(), nums.end()), ma=*max_element(nums.begin(), nums.end());
        /*if (ma-mi>=2*k)
        {
            m=(ma+mi)/2
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i]+k<=ma-k) nums[i]+=k;
                else nums[i]-=k;
            }
            return *max_element(nums.begin(), nums.end())-*min_element(nums.begin(), nums.end());
        }
        else*/ if (ma-mi>=k)
        {
            sort(nums.begin(), nums.end());
            int ans=nums[nums.size()-1]-nums[0];
            for (int i=0; i<nums.size()-1; i++)
            {
                nums[i]+=2*k;
                ma=max(nums[i], nums[nums.size()-1]);
                mi=min(nums[0], nums[i+1]);
                ans=min(ans, ma-mi);
            }
            return ans;
        }
        else return ma-mi;
    }
};