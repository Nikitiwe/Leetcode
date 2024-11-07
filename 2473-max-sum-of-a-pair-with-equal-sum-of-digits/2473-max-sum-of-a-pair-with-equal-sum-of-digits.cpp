class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> arr(82, vector<int> (2, 0));
        for (int i=0; i!=nums.size(); i++)
        {
            int t=nums[i], s=0;
            while (t>0)
            {
                s+=t%10;
                t/=10;
            }
            if (nums[i]>=arr[s][0])
            {
                arr[s][1]=arr[s][0];
                arr[s][0]=nums[i];
            }
            else if (nums[i]>arr[s][1]) arr[s][1]=nums[i];
        }
        int ans=-1;
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i][1]>0) ans=max(ans, arr[i][0]+arr[i][1]);
        }
        return ans;
    }
};