class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=1, sum=1;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            if (sum<1)
            {
                ans+=1-sum;
                sum=1;
            }
        }
        return ans;
    }
};