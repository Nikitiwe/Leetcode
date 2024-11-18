class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        vector<int> arr(r1.size(), 0);
        for (int i=0; i!=arr.size(); i++) arr[i]=r1[i]-r2[i];
        vector<vector<int>> nums(arr.size(), vector<int> (2, 0));
        for (int i=0; i!=arr.size(); i++)
        {
            nums[i][0]=arr[i];
            nums[i][1]=i;
        }
        sort(nums.rbegin(), nums.rend());
        int ans=0;
        for (int i=0; i!=arr.size(); i++) ans+=r2[i];
        for (int i=0; i!=k; i++)
        {
            ans+=arr[nums[i][1]];
        }
        return ans;        
    }
};