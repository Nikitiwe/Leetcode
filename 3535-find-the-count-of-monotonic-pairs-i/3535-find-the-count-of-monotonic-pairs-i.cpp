class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        vector<vector<long>> arr;
        for (int i=0; i!=nums.size(); i++)
        {
            vector<long> row (nums[i]+1, 0);
            arr.push_back(row);
        }
        for (int i=0; i<=nums[0]; i++) arr[0][i]=1;
        for (int i=0; i<nums.size()-1; i++)
        {
            for (int j=0; j<=nums[i]; j++)
            {
                if (max(j, nums[i+1]-(nums[i]-j) )<=nums[i+1]) arr[i+1][max(j, nums[i+1]-(nums[i]-j) )]+=arr[i][j];
            }
            for (int j=1; j<=nums[i+1]; j++)
            {
                arr[i+1][j]+=arr[i+1][j-1];
                arr[i+1][j]%=1000000007;
            }
        }
        long ans=0;
        for (int j=0; j<=nums[nums.size()-1]; j++) ans+=arr[nums.size()-1][j];
        return ans%1000000007;
    }
};