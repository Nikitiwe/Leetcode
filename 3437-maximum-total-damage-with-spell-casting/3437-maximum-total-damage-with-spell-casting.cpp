class Solution {
public:
    long long maximumTotalDamage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<long long> arr, s;
        for (int i=0; i!=nums.size(); i++)
        {
            if (i==0)
            {
                arr.push_back(nums[i]);
                s.push_back(nums[i]);
            }
            else
            {
                if (nums[i]==nums[i-1])
                {
                    s.back()+=nums[i];
                }
                else
                {
                    arr.push_back(nums[i]);
                    s.push_back(nums[i]);
                }
            }
        }
        vector<long long> a(arr.size(), 0);
        a[0]=s[0];
        for (int i=1; i<a.size(); i++)
        {
            long long p=s[i], pp=s[i], ppp=s[i], pppp=s[i], ppppp=s[i];
            if (arr[i-1]+2<arr[i]) p+=a[i-1];
            if (i>1&&arr[i-2]+2<arr[i]) pp+=a[i-2];
            if (i>2&&arr[i-3]+2<arr[i]) ppp+=a[i-3];
            if (i>3&&arr[i-4]+2<arr[i]) pppp+=a[i-4];
            if (i>4&&arr[i-5]+2<arr[i]) ppppp+=a[i-5];
            a[i]=max({p, pp, ppp, pppp, ppppp});
        }
        long long ans=a.back();
        if (a.size()>1) ans=max(ans, a[a.size()-2]);
        if (a.size()>2) ans=max(ans, a[a.size()-3]);
        return ans;
    }
};