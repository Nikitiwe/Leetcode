class Solution {
public:
    long long minimalKSum(vector<int>& nums, int kk) {
        sort(nums.begin(), nums.end());
        long long ans=0, t=0, temp, k=kk;
        int i=0;
        temp=min(k, (long long)nums[i]-1);
        k-=temp;
        ans+=(t+temp)*(temp+1)/2;
        i++;
        while (k>0&&i<nums.size())
        {
            temp=min(k, (long long)nums[i]-1-nums[i-1]);
            if (temp>0)
            {
                k-=temp;
                t=nums[i-1]+1;
                ans+=(2*t+temp-1)*(temp)/2;
            }
            i++;
        }
        if (k>0)
        {
            ans+=(2*nums[nums.size()-1]+1+k)*k/2;
        }
        return ans;
    }
};