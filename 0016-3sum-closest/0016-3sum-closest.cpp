class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=0, ans=nums[0]+nums[1]+nums[2];
        for (int i=0; i!=nums.size()-2; i++)
        {
            for (int j=i+1; j!=nums.size()-1; j++)
            {
                for (int k=j+1; k!=nums.size(); k++)
                {
                    sum=nums[i]+nums[j]+nums[k];
                    if (abs(ans-target)>abs(sum-target)) ans=sum;
                }
            }
        }
        return ans;
    }
};