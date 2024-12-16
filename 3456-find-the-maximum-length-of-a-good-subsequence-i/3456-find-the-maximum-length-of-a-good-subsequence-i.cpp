class Solution {
public:
    int maximumLength(vector<int>& nums, int kk) {
        vector<vector<int>> arr(nums.size(), vector<int> (nums.size()+1, 1000));
        for (int i=0; i<nums.size(); i++) arr[i][1]=0;
        int ans=1;
        for (int i=1; i<nums.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                for (int k=2; k<=j+2; k++)
                {
                    //if (arr[j][k-1]!=-1)
                    {
                        /*if (arr[i][k]==-1)
                        {
                            arr[i][k]=arr[j][k-1];
                            if (nums[i]!=nums[j]) arr[i][k]++;
                        }
                        else*/
                        {
                            int t=arr[j][k-1];
                            if (nums[i]!=nums[j]) arr[i][k]=min(arr[i][k], t+1);
                            else arr[i][k]=min(arr[i][k], t);
                        }
                    }
                    //if (arr[i][k]<=kk) ans=max(ans, k);
                }
            }
        }
        for (int i=1; i<nums.size(); i++)
        {
                for (int k=2; k<=i+1; k++)
                {
                    if (arr[i][k]<=kk) ans=max(ans, k);
                }
        }
        return ans;
    }
};