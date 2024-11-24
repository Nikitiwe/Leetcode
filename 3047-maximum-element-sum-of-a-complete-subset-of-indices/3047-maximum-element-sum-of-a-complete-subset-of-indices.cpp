class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        long long ans=0;
        unordered_set<int> m;
        vector<int> isit(nums.size(), 1);
        for (int i=1; i<=10000; i++) m.insert(i*i);
        for (int i=0; i!=nums.size(); i++)
        {
            if (isit[i]==1)
            {
                int a=i+1;
                long long sum=nums[i];
                for (int j=a-1+a; j<nums.size(); j+=a)
                {
                    if (isit[j]==1&&m.count(i*j+i+j+1)>0)
                    {
                        sum+=nums[j];
                        isit[j]=0;
                    }
                    //else if (m.count(t)>0) break;
                }
                ans=max(ans, sum);
            }
        }
        return ans;
    }
};