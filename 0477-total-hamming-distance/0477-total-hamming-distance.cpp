class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> zero(33, 0), one(33, 0);
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=0; j!=33; j++)
            {
                if (nums[i]%2==0)  zero[j]++;
                else one[j]++;
                nums[i]/=2;
            }
        }
        for (int i=0; i!=33; i++)
        {
            ans+=zero[i]*one[i];
        }
        return ans;
    }
};