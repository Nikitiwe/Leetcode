class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        vector<int> arr(nums.size()+1, 0);
        unordered_map<int, int> m;
        m[nums[0]]=0;
        int ans=1;
        for (int i=1; i<nums.size(); i++)
        {
            if (m.count(nums[i])==0) m[nums[i]]=i;
            else
            {
                arr[m[nums[i]]+1]++;
                arr[i+1]--;
            }
        }
        /*if (arr[0]==0)
            {
                ans*=2;
                ans%=1000000007;
            }*/
        for (int i=1; i<nums.size(); i++)
        {
            arr[i]+=arr[i-1];
            if (arr[i]==0)
            {
                ans*=2;
                ans%=1000000007;
            }
        }
        return ans;
    }
};