class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        if (nums.size()==1) return 0;
        int mi=nums[0], ma=nums[0];
        for (int i=0; i!=nums.size(); i++)
        {
            mi=min(mi, nums[i]);
            ma=max(ma, nums[i]);
        }
        vector<long long> arr(ma+2, 0), arl(ma+2, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[nums[i]+1]+=cost[i];
        }
        long long temp=arr[0], add=temp;
        for (int i=1; i<arr.size(); i++)
        {
            add+=arr[i];
            temp+=add;
            arr[i]=temp;
        }
        for (int i=0; i<nums.size(); i++)
        {
            arl[nums[i]-1]+=cost[i];
        }
        temp=arl[arl.size()-1], add=temp;
        for (int i=arl.size()-2; i>=0; i--)
        {
            add+=arl[i];
            temp+=add;
            arl[i]=temp;
        }
        long long ans=arr[0]+arl[0];
        for (int i=1; i<arr.size()-1; i++)
        {
            ans=min(ans, arr[i]+arl[i]);
        }
        return ans;
    }
};