class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        vector<unsigned long long> arr(t+1, 0);
        arr[0]=1;
        for (int j=0; j!=t; j++)
        {
            for (int i=0; i!=nums.size(); i++)
            {
                if (j+nums[i]<=t) arr[j+nums[i]]+=arr[j];
            }
        }
        return arr[t];
    }
};