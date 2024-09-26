class Solution {
public:
    int maximumJumps(vector<int>& nums, int d) {
        vector<int> arr(nums.size(), -1);
        arr[0]=0;
        for (int i=1; i!=nums.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                if (arr[j]!=-1&&abs(nums[i]-nums[j])<=d)
                {
                    arr[i]=max(arr[i], arr[j]+1);
                }
            }
        }
        return arr[arr.size()-1];
    }
};