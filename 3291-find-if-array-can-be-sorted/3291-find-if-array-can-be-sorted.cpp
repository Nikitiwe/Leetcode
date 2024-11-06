class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<vector<int>> arr(nums.size(), vector<int> (2, 0));
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i][0]=nums[i];
            int t=nums[i];
            int s=0;
            while (t>0)
            {
                s+=t%2;
                t/=2;
            }
            arr[i][1]=s;
        }
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if (arr[i][0]>arr[j][0]&&arr[i][1]!=arr[j][1]) return 0;
            }
        }
        return 1;
    }
};