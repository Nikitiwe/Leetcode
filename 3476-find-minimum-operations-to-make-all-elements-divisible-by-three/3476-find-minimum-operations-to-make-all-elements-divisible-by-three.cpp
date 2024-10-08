class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]%3==1) ans++;
            else if (nums[i]%3==2) ans++;
        }
        return ans;
    }
};