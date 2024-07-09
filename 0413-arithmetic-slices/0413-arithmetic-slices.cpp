class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0, temp=1;
        if (nums.size()<3) return 0;
        for (int i=0; i!=nums.size()-1; i++)
        {
            nums[i]=nums[i+1]-nums[i];
        }
        for (int i=1; i<=nums.size()-2; i++)
        {
            if (nums[i]==nums[i-1]) {ans+=temp; temp++;}
            else temp=1;
        }
        return ans;
    }
};