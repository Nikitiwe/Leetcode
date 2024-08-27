class Solution {
public:
    int minimumLevels(vector<int>& nums) {
        int sum=0, temp=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
        }
        sum-=nums.size()-sum;
        for (int i=0; i!=nums.size()-1; i++)
        {
            if (nums[i]==1) temp+=2;
            else temp-=2;
            if (temp>sum) return i+1;
        }
        return -1;
    }
};