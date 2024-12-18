class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<int> arr(100001, 0), a=arr;
        for (int i=0; i!=nums.size(); i++) arr[nums[i]]++;
        long ans=0, mod=1000000007;
        for (int i=1; i!=arr.size(); i++)
        {
            if (arr[i]>0)
            {
                int t=arr[i];
                //ans+=(long)t*(t-1);
                //ans%=mod;
                for (int j=0; i+j<arr.size(); j+=i)
                {
                    a[i+j]+=t;
                }
            }
        }
        for (int i=1; i!=a.size(); i++)
        {
            a[i]+=a[i-1];
            a[i]%=mod;
            if (arr[i]>0)
            {
                ans+=(long)a[i]*arr[i];
                ans%=mod;
            }
        }
        return ans;
    }
};