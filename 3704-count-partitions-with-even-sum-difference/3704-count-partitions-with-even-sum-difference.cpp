class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i!=nums.size(); i++) sum += nums[i];
        int ans = 0, suml = 0;
        for (int i=0; i< nums.size()-1; i++)
        {
            suml += nums[i];
            sum -= nums[i];
            if (((sum - suml)%2+2)%2==0) ans++;
        }
        return ans;
    }
};