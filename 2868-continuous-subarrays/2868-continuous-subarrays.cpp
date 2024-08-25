class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=1;
        vector<vector<int>> arr(nums.size(), vector<int> (5, 1));
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]==nums[i-1]+2)
            {
                arr[i][0]=1;
                arr[i][1]=1;
                arr[i][2]=arr[i-1][0]+1;
                arr[i][3]=arr[i-1][0]+1;
                arr[i][4]=arr[i-1][0]+1;
            }
            else if (nums[i]==nums[i-1]+1)
            {
                arr[i][0]=1;
                arr[i][1]=min(arr[i-1][1], arr[i-1][0])+1;
                arr[i][2]=arr[i-1][1]+1;
                arr[i][3]=arr[i-1][1]+1;
                arr[i][4]=min(arr[i-1][1], arr[i-1][3])+1;
            }
            else if (nums[i]==nums[i-1])
            {
                arr[i][0]=arr[i-1][0]+1;
                arr[i][1]=arr[i-1][1]+1;
                arr[i][2]=arr[i-1][2]+1;
                arr[i][3]=arr[i-1][3]+1;
                arr[i][4]=arr[i-1][4]+1;
            }
            else if (nums[i]==nums[i-1]-1)
            {
                arr[i][0]=min(arr[i-1][3], arr[i-1][1])+1;
                arr[i][1]=arr[i-1][3]+1;
                arr[i][2]=arr[i-1][3]+1;
                arr[i][3]=min(arr[i-1][3], arr[i-1][4])+1;
                arr[i][4]=1;
            }
            else if (nums[i]==nums[i-1]-2)
            {
                arr[i][0]=arr[i-1][4]+1;
                arr[i][1]=arr[i-1][4]+1;
                arr[i][2]=arr[i-1][4]+1;
                arr[i][3]=1;
                arr[i][4]=1;
            }
            ans+=arr[i][2];
        }
        //return arr[2][0];
        return ans;
    }
};